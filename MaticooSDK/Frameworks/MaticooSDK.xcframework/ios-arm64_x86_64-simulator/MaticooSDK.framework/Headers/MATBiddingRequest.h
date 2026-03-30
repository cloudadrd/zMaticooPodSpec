//
//  MATBiddingRequest.h
//  MaticooSDK
//
//  Created by root on 2023/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface MATBiddingResponse : NSObject
@property (assign, nonatomic, readonly) BOOL success;
@property (strong, nonatomic, readonly, nullable) NSError *error;
@property (copy, nonatomic, readonly, nullable) NSString *bidToken;
@property (assign, nonatomic, readonly) float price;
@end

@interface MATBiddingRequestParameter : NSObject
@property (copy, nonatomic) NSString *placementId;
@property (copy, nonatomic) NSString *adxId;
@end

typedef void(^MATBiddingRequestCompletion)(MATBiddingResponse * _Nullable bidResponse);

@interface MATBiddingRequest : NSObject

+ (void)reportTrack:(MATBiddingResponse * _Nullable)bidResponse;

+ (void)biddingRequestWithParameter:(MATBiddingRequestParameter *)parameter completion:(MATBiddingRequestCompletion)completion;

@end

NS_ASSUME_NONNULL_END
