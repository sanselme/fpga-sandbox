print("hps - Hello from HPS (ARMv7-A)")

while true {
  try? await Task.sleep(nanoseconds: 1_000_000_000)
  print("hps - Heartbeat")
}
