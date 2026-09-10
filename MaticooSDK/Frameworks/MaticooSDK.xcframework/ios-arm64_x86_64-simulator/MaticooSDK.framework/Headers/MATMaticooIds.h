//
//  MATMaticooIds.h
//  zMaticooSDK
//
//  Created by Parker.zhao
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Identifies a successfully loaded ad. Provided by the SDK in the load success callback.
/// Each successful load produces a distinct instance that is not replaced by later loads; pass it back when showing to display the corresponding ad.
@interface MATMaticooIds : NSObject

/// Bidding request ID when loaded via bidding; `nil` for waterfall.
@property (nonatomic, copy, readonly, nullable) NSString *biddingRequestId;

/// Whether the ad was served from cache. Informational only.
@property (nonatomic, assign, readonly) BOOL isCache;

/// Placement / unit ID.
@property (nonatomic, copy, readonly) NSString *unitId;

/// Creative ID (CRID) of the selected offer. `nil` when the offer switch is off,
/// the creative is B2V, or the server did not return a CRID.
@property (nonatomic, copy, readonly, nullable) NSString *creativeId;

@end

NS_ASSUME_NONNULL_END
