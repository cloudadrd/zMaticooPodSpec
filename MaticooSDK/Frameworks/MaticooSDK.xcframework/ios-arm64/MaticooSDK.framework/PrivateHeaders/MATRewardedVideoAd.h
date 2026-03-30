//
//  MATRewardedVideoAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MATRewardedVideoAdDelegate;
@interface MATRewardedVideoAd : NSObject
@property (nonatomic, assign) BOOL isReady;
@property (nonatomic, weak) id<MATRewardedVideoAdDelegate> delegate;
- (MATRewardedVideoAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd NS_SWIFT_NAME(loadAd());
- (void)loadAd:(NSString*)biddingRequestId;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
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
- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd;
@end

NS_ASSUME_NONNULL_END
