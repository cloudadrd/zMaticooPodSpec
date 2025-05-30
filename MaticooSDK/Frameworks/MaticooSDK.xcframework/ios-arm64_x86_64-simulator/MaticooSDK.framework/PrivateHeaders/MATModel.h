//
//  MATModel.h
//  MaticooSDK
//
//  Created by root on 2023/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MATPlacement, MATBanner, MATInterstitial, MATRewardedVideo, MATNativeVideo, MATInteractive, MATSplash;

@interface MATModel : NSObject
@property (nonatomic,assign) NSInteger code;
@property (nonatomic,strong) NSString *msg;
@property (nonatomic,assign) NSInteger ri;     //The next initialization delay time, in seconds
@property (nonatomic,strong) NSString *gdpr;   //"is GDPR area? 1: Yes, 0: No"
@property (nonatomic,strong) NSString *token;  //sdk bidding token prefix
@property (nonatomic,assign) NSInteger d;      //"is debug mode 1:Yes,0:No"
@property (nonatomic,strong) NSArray<MATPlacement*> *pls;
@property (nonatomic,assign) NSInteger ntv_close_total;
@property (nonatomic,assign) NSInteger ntv_close_failed;
@property (nonatomic,assign) NSInteger ort;     //1:portait 2:landscape 3:adaptive
@property (nonatomic,strong) NSDictionary* event;
@property (nonatomic,assign) NSString* bi_url;     //bi的上报地址
@property (nonatomic,assign) NSString *track_level;
@property (nonatomic,assign) NSInteger test;     //测试设备
@property (nonatomic,assign) NSInteger video_cache_ratio;
@property (nonatomic,assign) NSInteger banner_cache_ratio;
@property (nonatomic,strong) NSString* bi_app_id;
@property (nonatomic,assign) NSInteger click_timeout;
@property (nonatomic,assign) NSInteger landing_type;
@property (nonatomic,assign) NSInteger active;
@property (nonatomic,assign) NSInteger gzip;
@property (nonatomic,assign) double visible_rate;
@property (nonatomic,assign) NSInteger no_fill_count;
@property (nonatomic,strong) NSArray<NSString*> *bi_events;
@property (atomic,strong) NSString* ios_bundle;
@end

@interface MATPlacement : NSObject
@property (nonatomic,assign)int64_t pid;      //Placement ID
@property (nonatomic,strong)NSString* n;        //Placement Name
@property (nonatomic,assign)NSInteger t;        //AdType 1banner 2interstital 3rewarded 4natvie 5interactive 6splash
@property (nonatomic,strong)MATBanner* bn;
@property (nonatomic,strong)MATInterstitial* instl;
@property (nonatomic,strong)MATRewardedVideo* rw;
@property (nonatomic,strong)MATNativeVideo* ntv;
@property (nonatomic,strong)MATInteractive* ia;
@property (nonatomic,strong)MATSplash* spl;
@property (nonatomic,assign)NSInteger preload;
@end

@interface MATBanner : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger w;
@property (nonatomic,assign)NSInteger h;
@property (nonatomic,assign)NSInteger interval;
@end

@interface MATInterstitial : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger type; //1-banner, 2- video, 0 - both
@property (nonatomic,assign)NSInteger countdown;
@end

@interface MATRewardedVideo : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger ort; //Orientation
@end

@interface MATNativeVideo : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger ort; //Orientation
@end

@interface MATInteractive : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger ri;
@property (nonatomic,strong)NSString *domains;
@end

@interface MATSplash : NSObject
@property (nonatomic,assign)int64_t id;
@property (nonatomic,assign)NSInteger countdown;
@property (nonatomic,assign)BOOL skip;
@property (nonatomic,assign)NSInteger adshow;
@end
NS_ASSUME_NONNULL_END

