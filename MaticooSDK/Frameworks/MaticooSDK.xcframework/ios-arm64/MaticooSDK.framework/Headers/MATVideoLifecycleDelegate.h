//
//  MATVideoLifecycleDelegate.h
//  zMaticooSDK
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MATVideoLifecycleDelegate <NSObject>
@optional
- (void)videoDidStart;
- (void)videoDidPlay;
- (void)videoDidPause;
- (void)videoDidEnd;
- (void)videoDidMute:(BOOL)isMuted;
@end

NS_ASSUME_NONNULL_END
