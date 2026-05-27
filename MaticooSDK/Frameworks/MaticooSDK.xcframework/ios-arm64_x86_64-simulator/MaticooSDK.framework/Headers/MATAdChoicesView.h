//
//  MATAdChoicesView.h
//  zMaticooSDK
//

#import <UIKit/UIKit.h>

@class MATNativeAd;

NS_ASSUME_NONNULL_BEGIN

/// AdChoices brand logo view for native ads.
/// Displays the zMaticoo brand icon and handles ad choice click internally.
/// Usage: create an instance, add to your native ad layout, call setNativeAd: after load success.
@interface MATAdChoicesView : UIView

/// Bind the native ad instance for handling ad choice click.
- (void)setNativeAd:(MATNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
