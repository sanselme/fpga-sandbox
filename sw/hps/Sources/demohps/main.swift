// SPDX-License-Identifier: GPL-3.0
// Copyright (c) 2025 Schubert Anselme <schubert@anselm.es>

print("hps - Hello from HPS (ARMv7-A)")

while true {
  if case .failure(.systemError(let code)) = Time.sleep(seconds: 1) {
    print("Sleep error: \(code)")
  }

  print("hps - Heartbeat")
}
