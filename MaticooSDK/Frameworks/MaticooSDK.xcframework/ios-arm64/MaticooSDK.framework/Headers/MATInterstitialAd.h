//
//  MATInterstitialAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

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
- (void)loadAdExtraMap:(NSDictionary<NSString *, id> *)extraMap;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
+ (void)destroy:(NSArray<NSString *> *)placementIDs;
@end

@protocol MATInterstitialAdDelegate <NSObject>
- (void)interstitialAdDidLoad:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd displayFailWithError:(NSError *)error;
- (void)interstitialAdWillLogImpression:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClick:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdWillClose:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClose:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdEndCardShow:(MATInterstitialAd *)interstitialAd;
@end

NS_ASSUME_NONNULL_END
