# Kernel for Nothing Phone (1) (Spacewar)

Linux 5.4.302 kernel with upstream RCU 5.15 backports, scheduler 6.1, BBRv3, and NetHunter support.

## Source History

| Base | Branch | Source |
|------|--------|--------|
| William24hmar | `Lineage-Rom` | RCU 5.15, scheduler 6.1, BBRv3, SUSFS, net/audio fixes |
| William24hmar | `Staging-1` | NoMount, BORE, MPTCP, Baseband-Guard |
| rodrig20 | `moonwake/moon` | USB gadget reconfiguration, HID keyboard descriptor |

## Features

- **KernelSU** with Branchlink, Throne Tracker, LSM hooks
- **SUSFS 2.2.0** (sus_path, sus_mount, sus_kstat, try_umount, spoof_uname, open_redirect)
- **NoMount** support
- **Baseband-Guard** LSM for modem security
- **BBRv3** as default TCP congestion control
- **Scheduler 6.1 mainline** + BORE + CASS
- **RCU 5.15** backports (boost, lazy, nocb, fast nohz)
- **MPTCP** (Multipath TCP)
- **IRQ balance** tuning with CPU exclusions
- **Dead code elimination** (DCE)
- **LTO + O3** optimizations
- **WALT** scheduler
- **F2FS** with security

### USB Gadget

- USB gadget reconfiguration (unregister current gadget for reconfig)
- Proper HID keyboard report descriptor (full Boot Keyboard descriptor)

## Build Config

```
TARGET_KERNEL_CONFIG := vendor/lahaina-qgki_defconfig vendor/debugfs.config
```

## Credits

- [William24hmar](https://github.com/William24hmar) - Lineage-Rom and Staging-1 kernel bases
- [rodrig20](https://github.com/rodrig20) - USB gadget reconfiguration and HID keyboard descriptor
- [simonpunk](https://gitlab.com/simonpunk/susfs4ksu) - SUSFS
- [KernelSU](https://github.com/tiann/KernelSU) - kernel-based root
