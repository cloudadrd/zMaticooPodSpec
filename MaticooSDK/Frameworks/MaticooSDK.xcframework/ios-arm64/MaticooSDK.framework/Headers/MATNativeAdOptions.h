//
//  MATNativeAdOptions.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>
#import "MATVideoOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface MATNativeAdOptions : NSObject

@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *extras;
/// Reserved for future use.
@property (nonatomic, assign) NSInteger adChoicesPlacement;
@property (nonatomic, strong, nullable) MATVideoOptions *videoOptions;

@end

NS_ASSUME_NONNULL_END
