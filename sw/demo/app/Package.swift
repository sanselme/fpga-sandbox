// swift-tools-version: 6.2

import PackageDescription

let package = Package(
  name: "demo",
  platforms: [.macOS(.v14)],
  dependencies: [
    .package(name: "DemoSys", path: "../lib/demo-sys"),
    .package(name: "DemoSwift", path: "../lib/demo"),
  ],
  targets: [
    .executableTarget(
      name: "demo",
      dependencies: [
        "DemoSwift",
        "DemoSys",
      ],
    ),
  ]
)
