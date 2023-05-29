//
//  MATFullScrrenAd.h
//  MaticooSDK
//
//  Created by root on 2023/5/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATModalViewController.h"
#import "MATWebview.h"

NS_ASSUME_NONNULL_BEGIN

@interface MATFullScrrenAd : NSObject
@property (nonatomic, strong) MATModalViewController* modalViewController;
@property (nonatomic, assign) BOOL isReady;
@property (nonatomic, strong) MATWebview* matWebview;
@property (nonatomic, assign) BOOL isVideo;
@property (nonatomic, assign) BOOL isInteractAd;
- (void)closeControlEvent;
- (void)prepareCloseButton;
- (void)presentModalView:(UIView*)view UIController:(UIViewController*) viewController;
- (void)cacheMediaFiles:(NSArray*)mediaFiles resources:(NSArray*)resources;
- (void)closeButtonConstraint:(UIButton *)btn parentView:(UIView *)parentView top:(NSInteger)topOffset right:(NSInteger) rightOffset left:(NSInteger) leftOffset;
@end

NS_ASSUME_NONNULL_END
