//
//  MATTools.h
//  MaticooSDK
//
//  Created by root on 2023/4/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATTools : NSObject
+ (UIWindow*)keyWindow;
+ (UIViewController*)rootViewController:(UIViewController *)VC;
+ (BOOL)isDisplayedInScreenWith:(UIView *)flagView;
+ (NSString*)imageTypeForImageData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
