# Copyright (c) Meta Platforms, Inc. and affiliates.
# SPDX-License-Identifier: GPL-3.0-or-later

import os
from pathlib import Path
import unittest

from drgn import Program
from tests.linux_kernel import LinuxKernelTestCase, setenv

KALLSYMS_PATH = Path("/proc/kallsyms")


@unittest.skipUnless(
    KALLSYMS_PATH.exists(), "kernel does not have kallsyms (CONFIG_KALLSYMS)"
)
class TestModuleDebugInfo(LinuxKernelTestCase):
    # Arbitrary symbol that we can use to check that the module debug info was
    # loaded.
    SYMBOL = "lo_open"

    def setUp(self):
        super().setUp()
        with open("/proc/modules", "r") as f:
            for line in f:
                if line.startswith("loop "):
                    break
            else:
                self.skipTest("loop module is built in or not loaded")

        with KALLSYMS_PATH.open() as f:
            for line in f:
                tokens = line.split()
                if tokens[2] == self.SYMBOL:
                    self.symbol_address = int(tokens[0], 16)
                    break
            else:
                self.fail(f"{self.SYMBOL!r} symbol not found")

    def _test_module_debug_info(self, use_proc_and_sys):
        old_use_proc_and_sys = (
            int(os.environ.get("DRGN_USE_PROC_AND_SYS_MODULES", "1")) != 0
        )
        with setenv("DRGN_USE_PROC_AND_SYS_MODULES", "1" if use_proc_and_sys else "0"):
            if old_use_proc_and_sys == use_proc_and_sys:
                prog = self.prog
            else:
                prog = Program()
                prog.set_kernel()
                self._load_debug_info(prog)
            self.assertEqual(prog.symbol(self.SYMBOL).address, self.symbol_address)

    def test_module_debug_info_use_proc_and_sys(self):
        self._test_module_debug_info(True)

    def test_module_debug_info_use_core_dump(self):
        self._test_module_debug_info(False)
