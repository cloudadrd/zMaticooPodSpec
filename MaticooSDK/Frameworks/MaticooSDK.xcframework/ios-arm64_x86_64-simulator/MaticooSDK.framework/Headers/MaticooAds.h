//
//  MaticooAds.h
//  zMaticooSDK
//
//  Created by Mirinda on 2025/12/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MaticooAds : NSObject
+ (instancetype)shareSDK;

- (void)initSDK:(NSString *)appKey onSuccess:(void(^)(void))success onError:(void(^)(NSError* error))errorcb;

-(BOOL)isInitSuccess;

-(NSString*)getSDKVersion;

-(BOOL)getIsRestrictUser;

-(void)setDoNotTrackStatus:(BOOL) status;

-(BOOL)getDoNotTrackStatus;

-(void)setConsentStatus:(BOOL) status;

-(BOOL)getConsentStatus;

-(void)setIsAgeRestrictedUser:(BOOL) status;

-(BOOL)getIsAgeRestrictedUser;

-(void)setMediationName:(NSString*)n;

-(void)setCustomData:(NSDictionary*)customData;

-(NSString*)getBiddingToken:(NSString*) placementID timestamp:(NSInteger)timestamp;

- (void)adapterEventReportWithEventName:(NSString *)eventName des:(NSString *)des;


//The following deprecated interfaces are no longer supported starting from SDK version 2.0.0 and will not take effect when called.
-(BOOL)verifyPlacementID:(NSString*)placementID; //This function has been abandoned

-(id)getPlacement:(NSString*) placementId; //This function has been abandoned

-(id)getPlsInstance:(NSString*) placementId; //This function has been abandoned

-(void)addPlsInstance:(NSString*) placementId object:(NSObject*)obj; //This function has been abandoned

@end

NS_ASSUME_NONNULL_END
