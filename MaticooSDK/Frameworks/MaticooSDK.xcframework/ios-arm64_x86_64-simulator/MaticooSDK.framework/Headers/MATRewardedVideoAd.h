//
//  MATRewardedVideoAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATRewardInfo.h"
#import "MATMaticooIds.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MATRewardedVideoAdDelegate;
@interface MATRewardedVideoAd : NSObject
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, assign) BOOL videoMute;
@property (nonatomic, assign) BOOL isHeaderBidding;
@property (nonatomic, weak) id<MATRewardedVideoAdDelegate> delegate;
- (MATRewardedVideoAd*)initWithPlacementID:(NSString*)placementID;
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

@protocol MATRewardedVideoAdDelegate <NSObject>
/// Called when the ad loads successfully. Retain `maticooIds` and pass it when showing. If both didLoad methods are implemented, only this one is invoked.
- (void)rewardedVideoAdDidLoad:(MATRewardedVideoAd *)rewardedVideoAd
                    maticooIds:(MATMaticooIds *)maticooIds;
- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;
- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd displayFailWithError:(NSError *)error;
- (void)rewardedVideoAdStarted:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdCompleted:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdWillLogImpression:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdDidClick:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdWillClose:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdDidClose:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd rewardInfo:(MATRewardInfo *)rewardInfo;
- (void)rewardedVideoAdDidSkip:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdEndCardShow:(MATRewardedVideoAd *)rewardedVideoAd;

@optional
/// Called when the ad is displayed. If both WillLogImpression methods are implemented, only this one is invoked.
- (void)rewardedVideoAdWillLogImpression:(MATRewardedVideoAd *)rewardedVideoAd
                              maticooIds:(MATMaticooIds *)maticooIds;
//The following deprecated interfaces are no longer supported starting from SDK version 2.0.0 and will not take effect when called.
- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdDidLoad:(MATRewardedVideoAd *)rewardedVideoAd
    __attribute__((deprecated("Use -rewardedVideoAdDidLoad:maticooIds: instead.")));

@end

NS_ASSUME_NONNULL_END
