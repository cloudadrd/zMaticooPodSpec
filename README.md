# zMaticoo

[![Version](https://img.shields.io/cocoapods/v/zMaticoo.svg?style=flat)](https://cocoapods.org/pods/zMaticoo)
[![License](https://img.shields.io/cocoapods/l/zMaticoo.svg?style=flat)](https://cocoapods.org/pods/zMaticoo)
[![Platform](https://img.shields.io/cocoapods/p/zMaticoo.svg?style=flat)](https://cocoapods.org/pods/zMaticoo)

zMaticoo iOS SDK. Current version: **2.3.3**.

https://zmaticoo.com

## Requirements

- iOS 12.0+

## Installation

### CocoaPods

Add the following line to your Podfile:

```ruby
pod 'zMaticoo', '2.3.3'
```

### Swift Package Manager

In Xcode, choose **File > Add Package Dependencies…** and enter:

```
https://github.com/cloudadrd/zMaticooPodSpec.git
```

Or add it to your `Package.swift`:

```swift
.package(url: "https://github.com/cloudadrd/zMaticooPodSpec.git", from: "2.3.3")
```

Then add the `MaticooSDK` product to your app target.

> **Important:** add `-ObjC` to your app target's **Other Linker Flags**. The SDK is a static library, and without this flag its Objective-C categories are not linked. CocoaPods adds the flag automatically; Swift Package Manager does not.

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Changelog

### 2.3.3

- Fixed a race when several loads share one URL, and Native session-split now copies fields from the show context.
- Added an MP4 playback fallback, and fixed group accounting when a moov retry is exhausted.
- Shipped the privacy manifest inside the resource bundle.
- Expanded error 30115 details and playback-failure codes.
- Kept the impression callback's strong reference to its context, and stopped uploading template_url.
- Added an off-by-default switch that splits Banner and Native load sessions from cache verify.
- Reduced Hybrid request memory use, and stopped a visibility retain cycle from forming before impression.
- Filled mediation fields on adapter load and show-failure events.

### 2.3.2

- Added Swift Package Manager support, including resource bundle loading under SPM.
- Adapted full-screen ad layouts for iOS 27.1 and iPhone Duo safe areas; full-screen template buttons are positioned lower.
- Reduced repeated resource bundle lookups in edge cases and narrowed lock scope.

## License

zMaticoo is available under the MIT license. See the LICENSE file for more info.
