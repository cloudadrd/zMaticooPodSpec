//
//  MATAdImage.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATAdImage : NSObject

@property (nonatomic, strong, readonly, nullable) UIImage *image;
@property (nonatomic, strong, readonly, nullable) NSURL *imageURL;
@property (nonatomic, assign, readonly) CGFloat aspectRatio;

+ (instancetype)adImageWithURL:(nullable NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
