# Kernel: Nothing Phone (1) — Spacewar

QTI SM7325 (Snapdragon 778G) kernel, QGKI 5.4-based, with KernelSU-SUSFS and Droidspaces container support.

## Base

[william24hmar](https://t.me/SpacewarBuilds) Re:Kernel with KSU-SUSFS.

## Cherry-picks (~41)

### william24hmar | Re:Kernel upstream
Critical task boost, binder logging, TCP annotations, full cone NAT, TLB shootdown fix, RPM-SMD fix, log silencing, NF tables.

### Security
CVE-2026-43499 (rtmutex UAF) fix from test/module branches.

## Droidspaces configs (14)

All required features for Android container runtime (Droidspaces/Docker):

| Batch | Configs | Status |
|-------|---------|--------|
| 1 | Namespaces (PID, UTS, IPC, USER) | Booting |
| 2 | Cgroups (device, pids, net_prio) | Booting |
| 3 | Devtmpfs, Netfilter | Booting |
| 4 | More netfilter options | Booting |
| 5 | Additional container features | Booting |

## Build Fixes

- Rekernel `proc_create_single` 5.4 compat
- IPVS conntrack duplicate removal
- `inode_lock_killable` helper backports
- kjson Kconfig reference removal
- `ANDROID_PARANOID_NETWORK=n` causes bootloop — must stay enabled on QGKI

## KernelSU

- SU-SFS base
- `fix_ksu_dupes.sh` + `ksu_dupes.patch` — prevents duplicate `dispatch.c` insertion during build

## Known Issues

| Issue | Status |
|-------|--------|
| SYSVIPC / POSIX_MQUEUE | kABI patches cause bootloop on 5.4 QGKI (isolated but unfixed) |
| Device-as-Webcam USB | QTI 5.4 kernel UVC limitation |
| Portrait mode (Nothing Camera) | Requires factory persist calibration from stock NOS |

## Branches

| Branch | Description |
|--------|-------------|
| `voltage-nethunter` | Main (KSU + Droidspaces + william cherry-picks) |
| `voltage` | A16 production |
| `voltage-lr` | Long-running test |

## Maintainer

Ângelo Azevedo
