# Kernel for Nothing Phone (1) (Spacewar)

Linux 5.4.302 kernel for the Nothing Phone (1), based on William24hmar's NetHunter branch with Staging-1 features and USB gadget improvements.

## Source History

| Base | Branch | Source |
|------|--------|--------|
| William24hmar | Lineage-Rom | RCU 5.15, scheduler 6.1, BBRv3, TCP, net/audio fixes NetHunter, Wi-Fi monitor mode, HID injection, SUSFS |
| William24hmar | Staging-1 | NoMount, BORE, MPTCP, Baseband-Guard, BBGUARD, NoMount, Baseband-Guard, MPTCP, BBR default TCP |
| rodrig20 | `moonwake/moon` | USB gadget reconfiguration, proper HID keyboard descriptor |

## Features

- **KernelSU** with Branchlink, Throne Tracker, LSM hooks
- **SUSFS 2.2.0** (sus_path, sus_mount, sus_kstat, try_umount, spoof_uname, open_redirect)
- **NoMount** support
- **Baseband-Guard** LSM for modem security
- **BBR** as default TCP congestion control
- **MPTCP** (Multipath TCP)
- **BORE** and **CASS** schedulers
- **IRQ balance** tuning
- **RCU_BOOST** + **RCU_LAZY** for performance
- **LTO + O3** optimizations with dead code elimination
- **WALT** scheduler
- **F2FS** with security

### Kali NetHunter

- **Wi-Fi monitor mode** and packet injection (mac80211, RTL8188EUS, RTL8812AU, RTL8814AU)
- **HID keyboard/mouse attacks** (USB gadget configfs)
- **USB gadget reconfiguration** (unregister current gadget for reconfig)
- **Proper HID keyboard report descriptor**
- **HID gamepad support** (Sony Playstation, Nintendo, Dragonrise, Pantherlord)
- **WireGuard** VPN
- **USB networking** (RTL8150/8152, CDC_EEM, AQC111)

## Build Config

```
TARGET_KERNEL_CONFIG := vendor/lahaina-qgki_defconfig vendor/debugfs.config
```

## Credits

- [William24hmar](https://github.com/William24hmar) - NetHunter and Staging-1 kernel bases
- [rodrig20](https://github.com/rodrig20) - USB gadget improvements
- [simonpunk](https://gitlab.com/simonpunk/susfs4ksu) - SUSFS
- [KernelSU](https://github.com/tiann/KernelSU) - kernel-based root
