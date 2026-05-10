//
//  MATRewardInfo.h
//  zMaticooSDK
//
//  Created by Cursor on 2026/04/02.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATRewardInfo : NSObject

@property (nonatomic, copy, readonly) NSString *rewardId;
@property (nonatomic, copy, readonly) NSString *rewardName;
@property (nonatomic, assign, readonly) NSInteger rewardAmount;

- (instancetype)initWithRewardId:(NSString *)rewardId
                      rewardName:(NSString *)rewardName
                    rewardAmount:(NSInteger)rewardAmount;

@end

NS_ASSUME_NONNULL_END
