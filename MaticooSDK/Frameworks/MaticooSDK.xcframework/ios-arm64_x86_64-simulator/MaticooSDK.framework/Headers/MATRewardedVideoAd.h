//
//  MATRewardedVideoAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATRewardInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MATRewardedVideoAdDelegate;
@interface MATRewardedVideoAd : NSObject
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, assign) BOOL videoMute;
@property (nonatomic, weak) id<MATRewardedVideoAdDelegate> delegate;
- (MATRewardedVideoAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd NS_SWIFT_NAME(loadAd());
- (void)loadAd:(NSString*)biddingRequestId;
- (void)loadAdExtraMap:(NSDictionary<NSString *, id> *)extraMap;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
+ (void)destroy:(NSArray<NSString *> *)placementIDs;
@end

@protocol MATRewardedVideoAdDelegate <NSObject>
- (void)rewardedVideoAdDidLoad:(MATRewardedVideoAd *)rewardedVideoAd;
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
//The following deprecated interfaces are no longer supported starting from SDK version 2.0.0 and will not take effect when called.
- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
