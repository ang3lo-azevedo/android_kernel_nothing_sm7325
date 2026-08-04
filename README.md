# Kernel for Nothing Phone (1) (Spacewar)

Linux 5.4.302 kernel based on William24hmar's KSU-SUSFS branch with NetHunter, NoMount, USB gadget, and performance additions.

## Source History

| Source | Contributions |
|--------|---------------|
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `KSU-SUSFS` | KSU syscall tamper, full SUSFS, CASS, BBR |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `Nethunter` | NetHunter Kconfig and driver configs |
| [maxsteeel](https://github.com/maxsteeel/nomount) | NoMount path redirection subsystem (5.4 kernel integration) |
| [rodrig20](https://github.com/rodrig20/moonwake_kernel_xiaomi_ruby) `moon` | USB gadget reconfig, HID keyboard descriptor |

## Features

- **KernelSU** with syscall tamper, Throne Tracker always threaded
- **SUSFS** full support (sus_path, sus_mount, sus_kstat, try_umount, spoof_uname, hide_symbols, open_redirect, sus_map)
- **NoMount** path redirection subsystem (hooks in namei.c, d_path.c, readdir.c)
- **CASS** scheduler + **BBR** default TCP
- **NetHunter** support: Wi-Fi monitor mode (mac80211, RTL8XXXU), WireGuard, HID gamepad (Dragonrise, Nintendo, Sony, Playstation, Pantherlord, Greenasia), USB networking, PPP/VPN, USB serial (PL2303, FTDI, CP210X)
- **MPTCP** multipath TCP (mainline)
- **Dead code elimination** and power efficient workqueues (mainline)
- **LTO + O3** optimizations, **WALT** scheduler, **F2FS**
- **USB gadget** reconfiguration and proper HID keyboard descriptor
- Focaltech touchscreen DRM/FB fix (compile fix for KSU-SUSFS defconfig)

## Build Config

```
TARGET_KERNEL_CONFIG := vendor/lahaina-qgki_defconfig vendor/debugfs.config
```

KernelSU source is fetched automatically on first build via voltage_Spacewar.mk.

## Credits

- [William24hmar](https://github.com/William24hmar) - KSU-SUSFS and Nethunter kernel bases
- [backslashxx](https://github.com/backslashxx) - KernelSU syscall tamper
- [rodrig20](https://github.com/rodrig20) - USB gadget improvements
- [maxsteeel](https://github.com/maxsteeel) - NoMount subsystem
- [simonpunk](https://gitlab.com/simonpunk/susfs4ksu) - SUSFS
