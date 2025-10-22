# Image

```shell
# Pick your device (DO NOT GUESS)
DEV=/dev/sdX

# Offsets (aligned, boring)
SPL_LBA=0                        # .sfp at LBA0
UBOOT_OFFS=$((1<<20))            # 1 MiB (dev)
MCUBOOT_OFFS=$((2<<20))          # 2 MiB (prod)
SLOT0_OFFS=$((4<<20))            # 4 MiB
SLOT1_OFFS=$((8<<20))            # 8 MiB
SCRATCH_OFFS=$((12<<20))         # 12 MiB
FS_START_MB=16                   # start filesystem at 16 MiB (safe gap)

# Images you built
SFP=u-boot-with-spl.sfp          # SPL container for BootROM
UBOOT_IMG=u-boot.img             # U-Boot proper (FIT/legacy as your SPL expects)
MCUBOOT_BIN=mcuboot.bin          # MCUboot (RAM-load build)
ZEPHYR_SIGNED=zephyr.signed.bin  # Zephyr app signed for MCUboot
```

## Devevelopment

```shell
set -e
sudo wipefs -a "$DEV"

# Write SPL container for BootROM
sudo dd if="$SFP" of="$DEV" bs=512 conv=fsync

# Write U-Boot proper at 1 MiB
sudo dd if="$UBOOT_IMG" of="$DEV" bs=1 seek="$UBOOT_OFFS" conv=fsync

# Create a single FAT32 partition starting at 16 MiB (leaves boot area untouched)
sudo parted -s "$DEV" mklabel msdos
sudo parted -s "$DEV" mkpart primary fat32 "${FS_START_MB}MiB" 100%

# Format FAT and copy whatever you want (e.g., zephyr.uImage or zephyr.elf)
sudo mkfs.vfat -F 32 "${DEV}1"
sudo mkdir -p /tmp/sd && sudo mount "${DEV}1" /tmp/sd
# example payloads:
#   sudo cp zephyr/zephyr.uImage /tmp/sd/
#   sudo cp zephyr/zephyr.elf    /tmp/sd/
sync
sudo umount /tmp/sd
```

```shell
setenv loadaddr 0x01000000
fatload mmc 0:1 ${loadaddr} zephyr/zephyr.uImage
bootm ${loadaddr}
# or
fatload mmc 0:1 ${loadaddr} zephyr/zephyr.elf
bootelf ${loadaddr}
```

## Production

```shell
set -e
sudo wipefs -a "$DEV"

# SPL
sudo dd if="$SFP" of="$DEV" bs=512 conv=fsync

# MCUboot at 2 MiB
sudo dd if="$MCUBOOT_BIN" of="$DEV" bs=1 seek="$MCUBOOT_OFFS" conv=fsync

# Slot0 at 4 MiB (your signed Zephyr image)
sudo dd if="$ZEPHYR_SIGNED" of="$DEV" bs=1 seek="$SLOT0_OFFS" conv=fsync

# (Optional now, used for upgrade tests)
# Slot1 at 8 MiB:
# sudo dd if="$ZEPHYR_SIGNED_NEXT" of="$DEV" bs=1 seek="$SLOT1_OFFS" conv=fsync
#
# Scratch at 12 MiB is just erased space; MCUboot will manage it if your build uses swap.
sync
```

## Optional

```shell
# boot.cmd (example)
setenv loadaddr 0x01000000
if fatload mmc 0:1 ${loadaddr} zephyr/zephyr.uImage; then
  echo Booting Zephyr...
  bootm ${loadaddr}
else
  echo No uImage; trying ELF...
  if fatload mmc 0:1 ${loadaddr} zephyr/zephyr.elf; then
    bootelf ${loadaddr}
  fi
fi
```

```shell
mkimage -A arm -T script -C none -n "auto" -d boot.cmd boot.scr
sudo cp boot.scr /tmp/sd/
```

## Makefile

```makefile
# Makefile (top-level)
SPL_SRC          ?= spl/           # your SPL source dir
SPL_TOOL         ?= mk_sfp         # whatever packs .sfp (vendor tool or script)
SPL_OUT          ?= out
SPL_TEXT_BASE    ?= 0xFFFF0000     # IRAM as per SoCFPGA port

# Payload offsets (match the sd layouts above)
PAYLOAD_DEV_OFFS   ?= 0x00100000   # 1 MiB (U-Boot)
PAYLOAD_PROD_OFFS  ?= 0x00200000   # 2 MiB (MCUboot)

all: dev.sfp prod.sfp

dev.sfp:
	$(MAKE) -C $(SPL_SRC) clean
	$(MAKE) -C $(SPL_SRC) SPL_TEXT_BASE=$(SPL_TEXT_BASE) PAYLOAD_OFFSET=$(PAYLOAD_DEV_OFFS)
	$(SPL_TOOL) -i $(SPL_SRC)/spl.bin -o $(SPL_OUT)/$@   # pack to SFP

prod.sfp:
	$(MAKE) -C $(SPL_SRC) clean
	$(MAKE) -C $(SPL_SRC) SPL_TEXT_BASE=$(SPL_TEXT_BASE) PAYLOAD_OFFSET=$(PAYLOAD_PROD_OFFS)
	$(SPL_TOOL) -i $(SPL_SRC)/spl.bin -o $(SPL_OUT)/$@
```

```c
#ifndef PAYLOAD_OFFSET
#define PAYLOAD_OFFSET 0x00200000u /* default to prod */
#endif
/* After DDR init, do a raw copy from SD offset PAYLOAD_OFFSET to SDRAM, then jump. */
```
