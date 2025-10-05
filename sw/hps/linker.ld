ENTRY(_start)

/* 1 GiB SDRAM starting at 0x00000000 */
MEMORY {
  RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 0x40000000 /* 1024M */
}

SECTIONS {
  . = ORIGIN(RAM);

  .text : {
    KEEP(*(.vectors*)) KEEP(*(.startup*)) KEEP(*(.init))
    *(.text*) *(.rodata*) *(.glue_7) *(.glue_7t)
  } > RAM

  .data : {
    *(.data*)
  } > RAM

  .bss (NOLOAD) : {
    __bss_start = .;
    *(.bss*) *(COMMON)
    __bss_end = .;
  } > RAM

  . = ALIGN(8);
  _end = .;
  _stack_top = ORIGIN(RAM) + LENGTH(RAM) - 0x1000; /* 4KB guard */
}
