# Kernel for Nothing Phone (1) (Spacewar)

Linux 5.4.302 kernel based on [William24hmar's KSU-SUSFS](https://github.com/William24hmar/nothing_android_kernel_sm7325/tree/KSU-SUSFS) branch with NetHunter, USB gadget, and performance additions.

## Source History

| Base | Source |
|------|--------|
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `KSU-SUSFS` | KSU syscall tamper, full SUSFS, CASS, BBR |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `Nethunter` | NetHunter Kconfig and driver configs |
| [rodrig20](https://github.com/rodrig20/moonwake_kernel_xiaomi_ruby) `moon` | USB gadget reconfig, HID keyboard descriptor |

## Features

- **KernelSU** with syscall tamper, Throne Tracker always threaded
- **SUSFS** full support (sus_path, sus_mount, sus_kstat, try_umount, spoof_uname, hide_symbols, open_redirect, sus_map)
- **CASS** scheduler + **BBR** default TCP
- **NetHunter** support: Wi-Fi monitor mode (mac80211, RTL8XXXU), WireGuard, HID gamepad (Dragonrise, Nintendo, Sony, Playstation, Pantherlord, Greenasia), USB networking, PPP/VPN, USB serial (PL2303, FTDI, CP210X)
- **NoMount** (removed - no source code in KSU-SUSFS base)
- **MPTCP** multipath TCP (mainline kernel feature)
- **Dead code elimination** and power efficient workqueues (mainline)
- **LTO + O3** optimizations, **WALT** scheduler, **F2FS** with security
- **USB gadget** reconfiguration and proper HID keyboard descriptor
- SUSFS confirmed working (susfs_sdcard_monitor, try_umount)

## Build Config

```
TARGET_KERNEL_CONFIG := vendor/lahaina-qgki_defconfig vendor/debugfs.config
```

## Credits

- [William24hmar](https://github.com/William24hmar) - KSU-SUSFS and Nethunter kernel bases
- [backslashxx](https://github.com/backslashxx) - KernelSU syscall tamper
- [rodrig20](https://github.com/rodrig20) - USB gadget reconfiguration and HID keyboard descriptor
- [simonpunk](https://gitlab.com/simonpunk/susfs4ksu) - SUSFS
