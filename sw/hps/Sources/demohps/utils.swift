// SPDX-License-Identifier: GPL-3.0
// Copyright (c) 2025 Schubert Anselme <schubert@anselm.es>

import CHPSRuntime

@Sendable
func print(_ message: String) {
  message.utf8.forEach { write($0) }
  write(10) // newline
}

@Sendable
func write(_ byte: UInt8) {
  withUnsafePointer(to: byte) { _ = CHPSRuntime.write(1, $0, 1) } // STDOUT_FILENO = 1
}
