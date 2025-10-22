// SPDX-License-Identifier: GPL-3.0
// Copyright (c) 2025 Schubert Anselme <schubert@anselm.es>

#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void _sys_exit(int status);

int sleep(const void* timespec_ptr);
int write(int fd, const void *buf, size_t count);

#ifdef __cplusplus
}
#endif
