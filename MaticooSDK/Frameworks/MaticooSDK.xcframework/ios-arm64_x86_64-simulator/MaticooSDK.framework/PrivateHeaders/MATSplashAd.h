//
//  MATSplashAd.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol MATSplashAdDelegate;
@interface MATSplashAd : NSObject
@property (nonatomic, assign) BOOL isReady;
@property (nonatomic, assign) BOOL isVideo;
@property (nonatomic, weak) id<MATSplashAdDelegate> delegate;
- (MATSplashAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd NS_SWIFT_NAME(loadAd());
- (void)loadAd:(NSString*)biddingRequestId;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
@end

@protocol MATSplashAdDelegate <NSObject>
- (void)splashAdDidLoad:(MATSplashAd *)splashAd;
- (void)splashAd:(MATSplashAd *)splashAd didFailWithError:(NSError *)error;
- (void)splashAd:(MATSplashAd *)splashAd displayFailWithError:(NSError *)error;
- (void)splashAdWillLogImpression:(MATSplashAd *)splashAd;
- (void)splashAdDidClick:(MATSplashAd *)splashAd;
- (void)splashAdWillClose:(MATSplashAd *)splashAd;
- (void)splashAdDidClose:(MATSplashAd *)splashAd;
@end

NS_ASSUME_NONNULL_END
