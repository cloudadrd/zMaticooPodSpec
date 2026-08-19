//
//  MATInterstitialAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATMaticooIds.h"

NS_ASSUME_NONNULL_BEGIN
@protocol MATInterstitialAdDelegate;

@interface MATInterstitialAd : NSObject
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, assign) BOOL isVideo;
@property (nonatomic, assign) BOOL isHeaderBidding;
@property (assign, nonatomic) BOOL videoMute;
@property (nonatomic, weak) id<MATInterstitialAdDelegate> delegate;
- (MATInterstitialAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd NS_SWIFT_NAME(loadAd());
- (void)loadAd:(NSString*)biddingRequestId;

/// Loads an ad with custom parameters (waterfall). Only keys supported by Maticoo take effect; others are ignored. Values must be `NSString` or `NSNumber`.
/// Pass the content page URL under the `contentUrl` key when needed for brand safety.
- (void)loadAdExtraMap:(nullable NSDictionary<NSString *, id> *)extraMap;

/// Loads a bidding ad with custom parameters. `extraMap` has the same semantics as `-loadAdExtraMap:`.
- (void)loadAd:(NSString *)biddingRequestId extraMap:(nullable NSDictionary<NSString *, id> *)extraMap;

/// Shows the ad associated with `maticooIds`.
- (void)showAdFromViewController:(UIViewController *)vc
                      maticooIds:(nullable MATMaticooIds *)maticooIds;
- (void)showAdFromRootViewControllerWithMaticooIds:(nullable MATMaticooIds *)maticooIds;

/// Returns whether the ad associated with `maticooIds` is ready to show.
- (BOOL)isReadyWithMaticooIds:(nullable MATMaticooIds *)maticooIds;

/// Still functional, but in bidding scenarios which loaded ad will be shown is not guaranteed.
- (void)showAdFromViewController:(UIViewController*) vc
    __attribute__((deprecated("Use -showAdFromViewController:maticooIds: instead.")));
- (void)showAdFromRootViewController
    __attribute__((deprecated("Use -showAdFromRootViewControllerWithMaticooIds: instead.")));

+ (void)destroy:(NSArray<NSString *> *)placementIDs;
@end

@protocol MATInterstitialAdDelegate <NSObject>
/// Called when the ad loads successfully. Retain `maticooIds` and pass it when showing. If both didLoad methods are implemented, only this one is invoked.
- (void)interstitialAdDidLoad:(MATInterstitialAd *)interstitialAd
                   maticooIds:(MATMaticooIds *)maticooIds;
- (void)interstitialAdDidLoad:(MATInterstitialAd *)interstitialAd
    __attribute__((deprecated("Use -interstitialAdDidLoad:maticooIds: instead.")));
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd displayFailWithError:(NSError *)error;
- (void)interstitialAdWillLogImpression:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClick:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdWillClose:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClose:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdEndCardShow:(MATInterstitialAd *)interstitialAd;
@end

NS_ASSUME_NONNULL_END
