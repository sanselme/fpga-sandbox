ENTRY(_start)

/* NiosV/M typical memory layout - adjust based on your specific implementation */
MEMORY {
  RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 0x00100000 /* 1MB */
}

SECTIONS {
  . = ORIGIN(RAM);

  .init : {
    KEEP(*(.init))
  } > RAM

  .text : {
    *(.text*)
    *(.rodata*)
  } > RAM

  .data : {
    *(.data*)
  } > RAM

  .bss (NOLOAD) : {
    __bss_start = .;
    *(.bss*)
    *(COMMON)
    __bss_end = .;
  } > RAM

  . = ALIGN(8);
  _end = .;
  _stack_top = ORIGIN(RAM) + LENGTH(RAM) - 0x1000; /* 4KB guard */
}
