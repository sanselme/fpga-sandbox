#include <stdio.h>

// putchar implementation for Swift Embedded print support
int putchar(int c)
{
  return fputc(c, stdout);
}

// Minimal Swift runtime stubs for embedded mode
// These are normally provided by the Swift runtime but are missing in embedded mode
void _swift_exceptionPersonality(void) {}
