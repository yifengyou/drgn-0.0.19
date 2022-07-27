# Copyright (c) Meta Platforms, Inc. and affiliates.
# SPDX-License-Identifier: GPL-3.0-or-later

"""drgn command line interface"""

import argparse
import builtins
import code
import importlib
import os
import os.path
import runpy
import shutil
import sys
from typing import Any, Dict

import drgn


def _identify_script(path: str) -> str:
    EI_NIDENT = 16
    SIZEOF_E_TYPE = 2

    with open(path, "rb") as f:
        header = f.read(EI_NIDENT + SIZEOF_E_TYPE)

    ELFMAG = b"\177ELF"
    EI_DATA = 5
    ELFDATA2LSB = 1
    ELFDATA2MSB = 2
    ET_CORE = 4

    if len(header) < EI_NIDENT + SIZEOF_E_TYPE or header[:4] != ELFMAG:
        return "other"

    if header[EI_DATA] == ELFDATA2LSB:
        byteorder = "little"
    elif header[EI_DATA] == ELFDATA2MSB:
        byteorder = "big"
    else:
        return "elf"

    e_type = int.from_bytes(
        header[EI_NIDENT : EI_NIDENT + SIZEOF_E_TYPE],
        byteorder,  # type: ignore[arg-type]  # python/mypy#9057
    )
    return "core" if e_type == ET_CORE else "elf"


def displayhook(value: Any) -> None:
    if value is None:
        return
    setattr(builtins, "_", None)
    if isinstance(value, drgn.Object):
        text = value.format_(columns=shutil.get_terminal_size((0, 0)).columns)
    elif isinstance(value, (drgn.StackFrame, drgn.StackTrace, drgn.Type)):
        text = str(value)
    else:
        text = repr(value)
    try:
        sys.stdout.write(text)
    except UnicodeEncodeError:
        encoded = text.encode(sys.stdout.encoding, "backslashreplace")
        if hasattr(sys.stdout, "buffer"):
            sys.stdout.buffer.write(encoded)
        else:
            text = encoded.decode(sys.stdout.encoding, "strict")
            sys.stdout.write(text)
    sys.stdout.write("\n")
    setattr(builtins, "_", value)


def main() -> None:
    python_version = ".".join(str(v) for v in sys.version_info[:3])
    libkdumpfile = f'with{"" if drgn._with_libkdumpfile else "out"} libkdumpfile'
    version = f"drgn {drgn.__version__} (using Python {python_version}, elfutils {drgn._elfutils_version}, {libkdumpfile})"
    parser = argparse.ArgumentParser(prog="drgn", description="Scriptable debugger")

    program_group = parser.add_argument_group(
        title="program selection",
    ).add_mutually_exclusive_group()
    program_group.add_argument(
        "-k", "--kernel", action="store_true", help="debug the running kernel (default)"
    )
    program_group.add_argument(
        "-c", "--core", metavar="PATH", type=str, help="debug the given core dump"
    )
    program_group.add_argument(
        "-p",
        "--pid",
        metavar="PID",
        type=int,
        help="debug the running process with the given PID",
    )

    symbol_group = parser.add_argument_group("debugging symbols")
    symbol_group.add_argument(
        "-s",
        "--symbols",
        metavar="PATH",
        type=str,
        action="append",
        help="load additional debugging symbols from the given file; this option may be given more than once",
    )
    default_symbols_group = symbol_group.add_mutually_exclusive_group()
    default_symbols_group.add_argument(
        "--main-symbols",
        dest="default_symbols",
        action="store_const",
        const={"main": True},
        help="only load debugging symbols for the main executable and those added with -s; "
        "for userspace programs, this is currently equivalent to --no-default-symbols",
    )
    default_symbols_group.add_argument(
        "--no-default-symbols",
        dest="default_symbols",
        action="store_const",
        const={},
        help="don't load any debugging symbols that were not explicitly added with -s",
    )

    parser.add_argument(
        "-q",
        "--quiet",
        action="store_true",
        help="don't print download progress or non-fatal warnings "
        "(e.g., about missing debugging information)",
    )
    parser.add_argument(
        "script",
        metavar="ARG",
        type=str,
        nargs=argparse.REMAINDER,
        help="script to execute instead of running in interactive mode",
    )
    parser.add_argument("--version", action="version", version=version)

    args = parser.parse_args()

    if args.script:
        # A common mistake users make is running drgn $core_dump, which tries
        # to run $core_dump as a Python script. Rather than failing later with
        # some inscrutable syntax or encoding error, try to catch this early
        # and provide a helpful message.
        try:
            script_type = _identify_script(args.script[0])
        except OSError as e:
            sys.exit(e)
        if script_type == "core":
            sys.exit(
                f"error: {args.script[0]} is a core dump\n"
                f'Did you mean "-c {args.script[0]}"?'
            )
        elif script_type == "elf":
            sys.exit(f"error: {args.script[0]} is a binary, not a drgn script")
    else:
        print(version, file=sys.stderr, flush=True)
    if not args.quiet:
        os.environ["DEBUGINFOD_PROGRESS"] = "1"

    prog = drgn.Program()
    if args.core is not None:
        prog.set_core_dump(args.core)
    elif args.pid is not None:
        prog.set_pid(args.pid or os.getpid())
    else:
        prog.set_kernel()
    if args.default_symbols is None:
        args.default_symbols = {"default": True, "main": True}
    try:
        prog.load_debug_info(args.symbols, **args.default_symbols)
    except drgn.MissingDebugInfoError as e:
        if not args.quiet:
            print(str(e), file=sys.stderr)

    init_globals: Dict[str, Any] = {"prog": prog}
    if args.script:
        sys.argv = args.script
        runpy.run_path(args.script[0], init_globals=init_globals, run_name="__main__")
    else:
        import atexit
        import readline

        from drgn.internal.rlcompleter import Completer

        init_globals["drgn"] = drgn
        drgn_globals = [
            "NULL",
            "Object",
            "cast",
            "container_of",
            "execscript",
            "offsetof",
            "reinterpret",
            "sizeof",
        ]
        for attr in drgn_globals:
            init_globals[attr] = getattr(drgn, attr)
        init_globals["__name__"] = "__main__"
        init_globals["__doc__"] = None

        histfile = os.path.expanduser("~/.drgn_history")
        try:
            readline.read_history_file(histfile)
        except OSError as e:
            if not isinstance(e, FileNotFoundError) and not args.quiet:
                print("could not read history:", str(e), file=sys.stderr)

        def write_history_file() -> None:
            try:
                readline.write_history_file(histfile)
            except OSError as e:
                if not args.quiet:
                    print("could not write history:", str(e), file=sys.stderr)

        atexit.register(write_history_file)

        readline.set_history_length(1000)
        readline.parse_and_bind("tab: complete")
        readline.set_completer(Completer(init_globals).complete)
        atexit.register(lambda: readline.set_completer(None))

        sys.displayhook = displayhook

        banner = """\
For help, type help(drgn).
>>> import drgn
>>> from drgn import """ + ", ".join(
            drgn_globals
        )
        if prog.flags & drgn.ProgramFlags.IS_LINUX_KERNEL:
            banner += "\n>>> from drgn.helpers.linux import *"
            module = importlib.import_module("drgn.helpers.linux")
            for name in module.__dict__["__all__"]:
                init_globals[name] = getattr(module, name)
        code.interact(banner=banner, exitmsg="", local=init_globals)
