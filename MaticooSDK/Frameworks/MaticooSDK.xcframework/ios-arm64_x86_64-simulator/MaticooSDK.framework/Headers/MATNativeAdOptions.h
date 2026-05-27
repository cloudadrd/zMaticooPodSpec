//
//  MATNativeAdOptions.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>
#import "MATVideoOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface MATNativeAdOptions : NSObject

@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *extras;
// 这个参数作为预留参数
@property (nonatomic, assign) NSInteger adChoicesPlacement;
@property (nonatomic, strong, nullable) MATVideoOptions *videoOptions;

@end

NS_ASSUME_NONNULL_END
