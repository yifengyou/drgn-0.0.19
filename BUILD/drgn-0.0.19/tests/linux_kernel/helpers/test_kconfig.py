# Copyright (c) Meta Platforms, Inc. and affiliates.
# SPDX-License-Identifier: GPL-3.0-or-later

import os.path

from drgn.helpers.linux.kconfig import get_kconfig
from tests.linux_kernel import LinuxKernelTestCase


class TestKconfig(LinuxKernelTestCase):
    def test_get_kconfig(self):
        if not os.path.isfile("/proc/config.gz"):
            self.skipTest("kernel not built with CONFIG_IKCONFIG_PROC")
        m = get_kconfig(self.prog)
        self.assertIn(m["CONFIG_IKCONFIG"], {"y", "m"})
