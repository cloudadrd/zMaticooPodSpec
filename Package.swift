// swift-tools-version:5.3
//
// 当前仅在 beta 分支提供 SPM（未移动任何版本 tag）。
//
// Xcode / Package.swift:
//   .package(url: "https://github.com/cloudadrd/zMaticooPodSpec.git", .branch("beta"))
// Product: MaticooSDK
//
import PackageDescription

let package = Package(
    name: "zMaticoo",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "MaticooSDK",
            targets: ["MaticooSDKResources"]
        )
    ],
    targets: [
        .target(
            name: "MaticooSDKResources",
            dependencies: [
                .target(name: "MaticooSDK")
            ],
            path: "Sources/MaticooSDKResources",
            resources: [
                .copy("MaticooSDK.bundle")
            ],
            linkerSettings: [
                .linkedLibrary("z"),
                .linkedLibrary("c++"),
                .linkedFramework("AdSupport"),
                .linkedFramework("AppTrackingTransparency"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("CoreMedia"),
                .linkedFramework("CoreTelephony"),
                .linkedFramework("SafariServices"),
                .linkedFramework("StoreKit"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("UIKit"),
                .linkedFramework("WebKit")
            ]
        ),
        .binaryTarget(
            name: "MaticooSDK",
            path: "MaticooSDK/Frameworks/MaticooSDK.xcframework"
        )
    ]
)
