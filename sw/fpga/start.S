.section .init, "ax"
.global _start

_start:
  /* Set up stack pointer */
  la sp, _stack_top

  /* Clear BSS section */
  la t0, __bss_start
  la t1, __bss_end
clear_bss:
  beq t0, t1, bss_done
  sw zero, 0(t0)
  addi t0, t0, 4
  j clear_bss
bss_done:
  /* Jump to main */
  jal main

hang:
  j hang
