CROSS  ?= arm-none-eabi

CC     := $(CROSS)-gcc
AS     := $(CROSS)-gcc
LD     := $(CROSS)-gcc
OBJCOPY := $(CROSS)-objcopy

CFLAGS   := -mcpu=cortex-a9 -marm -ffreestanding -fno-builtin -O2 -Wall -Wextra
LDFLAGS  := -nostdlib -Wl,-T,linker.ld -Wl,--gc-sections

all: hello.elf hello.bin

hello.elf: start.S main.c linker.ld
	$(CC) $(CFLAGS) start.S main.c -o $@ $(LDFLAGS)

hello.bin: hello.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f hello.elf hello.bin
