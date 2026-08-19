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
/// Request ID returned on a successful bid; pass it to subsequent `loadAd:` calls.
@property (copy, nonatomic, readonly, nullable) NSString *biddingRequestId;
/// Deprecated: Use `biddingRequestId`.
@property (copy, nonatomic, readonly, nullable) NSString *bidToken
    __attribute__((deprecated("Use biddingRequestId instead.")));
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

/// Requests a bid with custom parameters. Only keys supported by Maticoo take effect; others are ignored. Values must be `NSString` or `NSNumber`.
/// Pass the content page URL under the `contentUrl` key when needed for brand safety. Parameter handling matches `-loadAdExtraMap:`.
+ (void)biddingRequestWithParameter:(MATBiddingRequestParameter *)parameter
                              extra:(nullable NSDictionary<NSString *, id> *)extra
                         completion:(MATBiddingRequestCompletion)completion;

@end

NS_ASSUME_NONNULL_END
