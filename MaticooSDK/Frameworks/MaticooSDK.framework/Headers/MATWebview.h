//
//  MATWebview.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MATWebviewDelegate <NSObject>
//js
- (void)webviewLoadSuccess;
- (void)webviewJsLoadSuccess;
- (void)webviewLoadFailed:(NSString*)msg;
- (void)webviewVideoImp;
- (void)webviewVideoCompleted;
- (void)webviewVideoClick:(NSString*)position;
- (void)webviewAdRewareded;
- (void)webviewCloseAd;
- (void)webviewVideoMuted:(BOOL)isMuted;
//native
- (void)webviewClick;
- (void)webviewImp;
@end

@interface MATWebview : UIView
@property (nonatomic, weak) id<MATWebviewDelegate> delegate;
@property (nonatomic, assign) BOOL isVideoAd;
- (void)loadUrl:(NSString*)url;
- (void)dissMiss;
- (void)playVideo;
- (void)setVideoCacheFinish;
- (void)setVideoCacheFailed;
@end

NS_ASSUME_NONNULL_END
