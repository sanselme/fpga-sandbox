#pragma once

#include <stdint.h>

#define UART0_BASE  0xFFC02000u  /* HPS UART0 */
#define UART_THR    0x00
#define UART_LSR    0x14
#define LSR_THRE    (1u << 5)

static inline void putchar(char c)
{
  volatile uint32_t *lsr = (uint32_t *)(UART0_BASE + UART_LSR);
  volatile uint32_t *thr = (uint32_t *)(UART0_BASE + UART_THR);

  while(((*lsr) & LSR_THRE) == 0) { /* spin */ }

  *thr = (uint32_t)c;
}

static inline void printf(const char *s)
{
  while(*s)
  {
    if (*s == '\n') putchar('\r');
    putchar(*s++);
  }
}
