//
//  MATVideoController.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>
#import "MATVideoLifecycleDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface MATVideoController : NSObject

@property (nonatomic, weak, nullable) id<MATVideoLifecycleDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
