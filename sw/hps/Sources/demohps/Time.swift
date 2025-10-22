// SPDX-License-Identifier: GPL-3.0
// Copyright (c) 2025 Schubert Anselme <schubert@anselm.es>

import CHPSRuntime

struct Time: ~Copyable {
  private var sec: Int      // seconds
  private var nanosec: Int  // nanoseconds

  enum Error: Swift.Error, Sendable {
    case interrupted
    case systemError(Int32)
  }

  init(seconds: UInt32, nanoseconds: Int = 0) {
    self.sec = Int(seconds)
    self.nanosec = nanoseconds
  }

  @Sendable
  static func sleep(seconds: UInt32) {
    let time = Time(seconds: seconds)
    let result = time.exec()

    // In embedded systems, we might just continue or halt
    // For now, we'll just continue execution
    if result != 0 {}
  }

  @Sendable
  static func sleep(seconds: UInt32) -> Result<Void, Error> {
    let time = Time(seconds: seconds)
    let result = time.exec()

    switch result {
    case 0:
      return .success(())
    case -4: // EINTR
      return .failure(.interrupted)
    default:
      return .failure(.systemError(result))
    }
  }

  consuming func exec() -> Int32 {
    withUnsafePointer(to: self) { CHPSRuntime.sleep($0) }
  }

  borrowing func nanoseconds() -> Int { nanosec }
  borrowing func seconds() -> Int { sec }
}
