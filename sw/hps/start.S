.syntax unified
.cpu cortex-a9
.arm

.global _start
.extern main
.equ    MODE_SVC, 0x13

_start:
  /* Enter SVC mode, IRQ/FIQ disabled */
  mrs     r0, cpsr
  bic     r0, r0, #0x1F
  orr     r0, r0, #MODE_SVC
  orr     r0, r0, #(1<<7)     /* disable IRQ */
  orr     r0, r0, #(1<<6)     /* disable FIQ */
  msr     cpsr_c, r0

  /* Init stack */
  ldr     sp, =_stack_top
  bl      main

hang:
  b       hang
