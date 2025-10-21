// swift-tools-version: 6.2

import PackageDescription

let package = Package(
  name: "demofpga",
  platforms: [.macOS(.v14)],
  products: [
    .library(name: "BSP", targets: ["BSP"]),
  ],
  targets: [
    .target(name: "BSP"),
    .executableTarget(
      name: "demofpga",
      dependencies: ["BSP"],
    ),
  ]
)
