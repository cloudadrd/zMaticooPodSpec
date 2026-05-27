//
//  MATMediaContent.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MATVideoController;

@interface MATMediaContent : NSObject

@property (nonatomic, assign, readonly) BOOL hasVideoContent;
@property (nonatomic, assign, readonly) CGFloat aspectRatio;
@property (nonatomic, assign, readonly) NSTimeInterval duration;
@property (nonatomic, strong, readonly, nullable) MATVideoController *videoController;

@end

NS_ASSUME_NONNULL_END
