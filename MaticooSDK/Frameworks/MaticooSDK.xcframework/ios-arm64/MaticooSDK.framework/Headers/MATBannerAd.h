//
//  MATBannerAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MATBannerAdDelegate;
@interface MATBannerAd : UIView
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, weak) id<MATBannerAdDelegate> delegate;
@property (nonatomic, copy, readonly) NSString *placementID;
@property (nonatomic, copy) NSDictionary *localExtra;
/// Whether to show the close button. Default NO (matches Android).
@property (nonatomic, assign) BOOL canCloseAd;
- (instancetype)initWithPlacementID:(NSString *)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;

/// Loads an ad with custom parameters (waterfall). Only keys supported by Maticoo take effect; others are ignored. Values must be `NSString` or `NSNumber`.
/// Pass the content page URL under the `contentUrl` key when needed for brand safety.
/// Keys that also exist in `localExtra` are overridden by this `extraMap`.
- (void)loadAdExtraMap:(nullable NSDictionary<NSString *, id> *)extraMap;

/// Loads a bidding ad with custom parameters. `extraMap` has the same semantics as `-loadAdExtraMap:`.
- (void)loadAd:(NSString *)biddingRequestId extraMap:(nullable NSDictionary<NSString *, id> *)extraMap;
/// Destroy the banner ad and release all resources. Call this when the banner is no longer needed.
- (void)destroy;
@end

@protocol MATBannerAdDelegate <NSObject>
- (void)bannerAdDidLoad:(MATBannerAd *)bannerAd;
- (void)bannerAd:(MATBannerAd *)bannerAd didFailWithError:(NSError *)error;
- (void)bannerAdDidImpression:(MATBannerAd*) bannerAd;
- (void)bannerAd:(MATBannerAd *)bannerAd showFailWithError:(NSError *)error;
- (void)bannerAdDidClick:(MATBannerAd*) bannerAd;
- (void)bannerAdDismissed:(MATBannerAd*) bannerAd;

@optional
- (void)bannerAdDidLeaveApp:(MATBannerAd*) bannerAd;
@end

NS_ASSUME_NONNULL_END
