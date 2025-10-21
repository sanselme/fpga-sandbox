// swift-tools-version: 6.2

import PackageDescription

let package = Package(
  name: "DemoSwift",
  platforms: [.macOS(.v14)],
  products: [
    .library(name: "DemoSwift", type: .static, targets: ["DemoSwift"]),
  ],
  dependencies: [
    .package(name: "DemoSys", path: "../demo-sys"),
  ],
  targets: [
    .target(
      name: "DemoSwift",
      dependencies: ["DemoSys"],
    ),
  ]
)
