//
//  MATNativeAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MATNativeAd, MATAdImage, MATMediaContent, MATMediaView, MATVideoController, MATNativeAdOptions, MATVideoOptions;
@protocol MATVideoLifecycleDelegate;

typedef NS_ENUM(NSUInteger, MATBrandLogoPosition) {
    ADCHOICES_TOP_LEFT       = 0,
    ADCHOICES_TOP_RIGHT      = 1,
    ADCHOICES_BOTTOM_RIGHT   = 2,
    ADCHOICES_BOTTOM_LEFT    = 3
};

#pragma mark - MATNativeAdElements

@interface MATNativeAdElements : NSObject
@property (nonatomic, copy, readonly) NSString *headline;
@property (nonatomic, copy, readonly) NSString *body;
@property (nonatomic, copy, readonly) NSString *callToAction;
@property (nonatomic, strong, readonly) MATAdImage *icon;
@property (nonatomic, copy, readonly, nullable) NSString *advertiser;
@property (nonatomic, strong, readonly, nullable) NSArray<MATAdImage *> *images;
@property (nonatomic, strong, readonly) MATMediaContent *mediaContent;
@end

#pragma mark - MATNativeAdDelegate

@protocol MATNativeAdDelegate <NSObject>
- (void)nativeAdLoadSuccess:(MATNativeAd *)nativeAd;
- (void)nativeAdFailed:(MATNativeAd *)nativeAd withError:(NSError*)error;
- (void)nativeAdDisplayed:(MATNativeAd *)nativeAd;
- (void)nativeAd:(MATNativeAd *)nativeAd displayFailWithError:(NSError *)error;
- (void)nativeAdClicked:(MATNativeAd *)nativeAd;
@end

#pragma mark - MATNativeAd

@interface MATNativeAd : NSObject

@property (nonatomic, weak) id<MATNativeAdDelegate> delegate;
@property (nonatomic, copy, readonly) NSString *placementID;
@property (nonatomic, strong, readonly) MATNativeAdElements *nativeElements;

- (instancetype)initWithPlacementID:(NSString *)placementID;

#pragma mark - Load

- (void)loadAd;
- (void)loadAd:(NSString *)biddingRequestId;

/// Loads an ad with custom parameters (waterfall). Only keys supported by Maticoo take effect; others are ignored. Values must be `NSString` or `NSNumber`.
/// Pass the content page URL under the `contentUrl` key when needed for brand safety.
/// Keys that also exist in `MATNativeAdOptions.extras` are overridden by this `extraMap`.
- (void)loadAdExtraMap:(nullable NSDictionary<NSString *, id> *)extraMap;

/// Loads a bidding ad with custom parameters. `extraMap` has the same semantics as `-loadAdExtraMap:`.
- (void)loadAd:(NSString *)biddingRequestId extraMap:(nullable NSDictionary<NSString *, id> *)extraMap;

#pragma mark - Configuration (call before loadAd)

- (void)setNativeAdOptions:(MATNativeAdOptions *)options;

#pragma mark - Self-Rendering: bind views for interaction (call after load success, on the main thread)

- (void)registerViewForInteraction:(nullable UIView *)adView
                         mediaView:(nullable MATMediaView *)mediaView
                    clickableViews:(nullable NSArray<UIView *> *)clickableViews;

#pragma mark - Actions

- (void)handleAdChoiceClick;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
