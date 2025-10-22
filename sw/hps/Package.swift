// swift-tools-version: 6.2

import PackageDescription

let package = Package(
  name: "demohps",
  platforms: [.macOS(.v13)],
  products: [
    .library(name: "CHPSRuntime", targets: ["CHPSRuntime"]),
  ],
  targets: [
    .target(name: "CHPSRuntime"),
    .executableTarget(
      name: "demohps",
      dependencies: ["CHPSRuntime"],
    ),
  ]
)
