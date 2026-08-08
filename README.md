# Kernel for Nothing Phone (1) (Spacewar)

Linux 5.4.302 kernel with KSU-SUSFS, NetHunter, NoMount, Droidspaces/Docker, and performance features.

## Source History

| Source | Contributions |
|--------|---------------|
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `KSU-SUSFS` | KSU syscall tamper, full SUSFS, CASS, BBR |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `Nethunter` | NetHunter Kconfig and driver configs |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `module` | Re:Kernel proc_ops, NF tables ranged sets, log silencing |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `Test` | Critical task boost, security fixes, TCP data-race annotations |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `20260807-Bak` | TLB batched shootdown (arm64 memory management optimization) |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `20260805-bak` | Binder transaction logging, RPM-SMD deadlock fix |
| [William24hmar](https://github.com/William24hmar/nothing_android_kernel_sm7325) `Nethunter` | Full cone NAT, IPVS conntrack integration, xt_ipvs matcher |
| [maxsteeel](https://github.com/maxsteeel/nomount) | NoMount path redirection subsystem (5.4 kernel integration) |
| [Droidspaces](https://github.com/ravindu644/Droidspaces-OSS) | GKI kABI patches (SYSVIPC, POSIX_MQUEUE), Droidspaces/Docker kernel configs |

## Features

- **KernelSU** with syscall tamper, Throne Tracker always threaded
- **SUSFS** full support: sus_path, sus_mount, sus_kstat, try_umount, spoof_uname, hide_symbols, open_redirect, sus_map
- **NoMount** path redirection (hooks in namei.c, d_path.c, readdir.c)
- **CASS** scheduler + **BBR** default TCP congestion control
- **NetHunter**: Wi-Fi monitor mode (mac80211, RTL8XXXU), WireGuard, HID gamepad (Dragonrise, Nintendo, Sony, Playstation, Pantherlord, Greenasia), USB networking, PPP/VPN, USB serial (PL2303, FTDI, CP210X)
- **MPTCP** multipath TCP support
- **Re:Kernel** - converts file_operations to proc_ops for /proc file compatibility
- **Critical task boost** - binder PI bypass, sync wakeup, workqueue priority, rcu_hurry for smoother UI under load
- **Security fixes** - CVE-2026-43499 (rtmutex UAF), binder UAF, af_unix UAF, ext4 LOGFLUSH
- **TCP data-race annotations** - prevents race conditions in tp counters and dsack
- **NF tables ranged sets** - multi-field firewall rule support
- **Log silencing** - USB, IPC, serial, media, display driver log spam reduction
- **Droidspaces / Docker** - full container runtime support: all Linux namespaces (PID, IPC, UTS, NET, USER), cgroups v1+v2, seccomp+BPF filter, overlayfs, veth/bridge/netfilter NAT, nf_tables, IPVS, MACVLAN/IPVLAN/VXLAN, NFS/CIFS/9P filesystems, full cone NAT
- **TLB batched shootdown** - faster memory management on arm64, better container performance
- **RPM-SMD deadlock fix** - prevents system hang when waiting for RPM acknowledgment
- **LTO + O3** optimizations, **WALT** scheduler, **F2FS**
- Dead code elimination and power efficient workqueues
- Focaltech touchscreen DRM/FB fix (compile fix for KSU-SUSFS defconfig)

## Build Config

```
TARGET_KERNEL_CONFIG := vendor/lahaina-qgki_defconfig vendor/debugfs.config
```

KernelSU source is fetched automatically on first build via `voltage_Spacewar.mk`.

## Credits

- [William24hmar](https://github.com/William24hmar) - KSU-SUSFS and NetHunter kernel bases, `module`/`Test` branches
- [backslashxx](https://github.com/backslashxx) - KernelSU syscall tamper
- [maxsteeel](https://github.com/maxsteeel) - NoMount subsystem
- [simonpunk](https://gitlab.com/simonpunk/susfs4ksu) - SUSFS
- [RealJohnGalt](https://github.com/RealJohnGalt) - Critical task boost + CASS scheduler
- [Jann Horn](https://github.com/thejh) - af_unix UAF fix
- [Eric Dumazet](https://github.com/edumazet) - TCP data-race annotations
- [Greg Kroah-Hartman](https://github.com/gregkh) - container_of cleanup
- [nullptr-t-oss](https://github.com/nullptr-t-oss) / [lateautumn233](https://github.com/lateautumn233) - Droidspaces GKI kABI patches
- [ExTV](https://github.com/ExTV) - Droidspaces kernel reference for Spacewar
- [ferstar](https://github.com/ferstar) - Full cone NAT, IPVS conntrack, xt_ipvs matcher
