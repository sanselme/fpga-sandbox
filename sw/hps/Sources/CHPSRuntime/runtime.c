// SPDX-License-Identifier: GPL-3.0
// Copyright (c) 2025 Schubert Anselme <schubert@anselm.es>

#include <stddef.h>
#include <stdint.h>

#define __NR_exit     1
#define __NR_write    4
#define __NR_sleep  162

extern int main(void);
typedef struct { unsigned long long quot, rem; } uldiv_t;

// MARK: - ARM syscall interface

static inline long syscall2(long number, long arg1, long arg2)
{
  long result;
  asm volatile(
    "mov r7, %1\n"
    "mov r0, %2\n"
    "mov r1, %3\n"
    "svc #0\n"
    "mov %0, r0"
    : "=r"(result)
    : "r"(number), "r"(arg1), "r"(arg2)
    : "memory"
  );
  return result;
}

static inline long syscall3(long number, long arg1, long arg2, long arg3)
{
  long result;
  asm volatile(
    "mov r7, %1\n"
    "mov r0, %2\n"
    "mov r1, %3\n"
    "mov r2, %4\n"
    "svc #0\n"
    "mov %0, r0"
    : "=r"(result)
    : "r"(number), "r"(arg1), "r"(arg2), "r"(arg3)
    : "memory"
  );
  return result;
}

// MARK: - ARM EABI functions

uldiv_t __aeabi_uldivmod(unsigned long long num, unsigned long long den)
{
  uldiv_t result = { num / den, num % den };
  return result;
}

void *__aeabi_memmove(void *dest, const void *src, size_t n)
{
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  if (d == s || n == 0) return dest;

  if (d < s)
  {
    for (size_t i = 0; i < n; i++) d[i] = s[i];
  }
  else
  {
    for (size_t i = n; i > 0; i--) d[i-1] = s[i-1];
  }

  return dest;
}

void *__aeabi_memset(void *s, size_t n, int c)
{
  unsigned char *ptr = (unsigned char *)s;
  for (size_t i = 0; i < n; i++) ptr[i] = (unsigned char)c;
  return s;
}

void *__aeabi_memcpy(void *dest, const void *src, size_t n)
{
  return __aeabi_memmove(dest, src, n);
}

void __aeabi_memclr(void *dest, size_t n) { __aeabi_memset(dest, n, 0); }
void __aeabi_memclr4(void *dest, size_t n) { __aeabi_memclr(dest, n); }

// MARK: - Memory management

void free(void *ptr) {}   // NOP for embedded systems

int posix_memalign(void **memptr, size_t alignment, size_t size)
{
  static char heap[64 * 1024];
  static size_t heap_offset = 0;

  size_t aligned_offset = (heap_offset + alignment - 1) & ~(alignment - 1);
  if (aligned_offset + size > sizeof(heap)) return -1;

  *memptr = &heap[aligned_offset];
  heap_offset = aligned_offset + size;

  return 0;
}

// MARK: - Utils

void _swift_exceptionPersonality(void) {}
void _sys_exit(int status) { syscall2(__NR_exit, status, 0); }    // Never returns

void _start(void) {
  int result = main();
  _sys_exit(result);
}

int sleep(const void* time_ptr)
{
  return (int)syscall2(__NR_sleep, (long)time_ptr, 0);
}

int write(int fd, const void *buf, size_t count)
{
  return (int)syscall3(__NR_write, fd, (long)buf, count);
}

int putchar(int c) {
  char ch = (char)c;
  return (int)syscall3(__NR_write, 1, (long)&ch, 1);
}
