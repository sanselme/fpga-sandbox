// swift-tools-version: 6.2

import PackageDescription

let package = Package(
  name: "DemoSys",
  platforms: [.macOS(.v14)],
  products: [
    .library(name: "Demo", type: .static, targets: ["Demo"]),
    .library(name: "DemoSys", type: .static, targets: ["DemoSys"]),
  ],
  targets: [
    .target(name: "Demo"),
    .target(
      name: "DemoSys",
      dependencies: ["Demo"],
    ),
  ]
)
