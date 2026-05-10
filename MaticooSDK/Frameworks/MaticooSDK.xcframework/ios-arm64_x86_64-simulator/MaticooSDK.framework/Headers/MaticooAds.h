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

//GDPR:
-(void)setConsentStatus:(BOOL) status;

-(BOOL)getConsentStatus;

//COPPA:
-(void)setIsAgeRestrictedUser:(BOOL) status;

-(BOOL)getIsAgeRestrictedUser;

/// CCPA:
-(void)setDoNotSell:(BOOL) doNotSell;

-(BOOL)getDoNotSell;//for Adapter

/// US Privacy String (IAB format ："1YNN"/"1YYN")
-(void)setUSPrivacy:(NSString *)usPrivacy;

-(NSString *)getUSPrivacy;//for Adapter

-(void)setMediationName:(NSString*)n;

-(void)setCustomData:(NSDictionary*)customData;

-(NSString*)getBiddingToken:(NSString*) placementID timestamp:(NSInteger)timestamp;

- (void)adapterEventReportWithEventName:(NSString *)eventName des:(NSString *)des;


//The following deprecated interfaces are no longer supported starting from SDK version 2.0.0 and will not take effect when called.
-(BOOL)verifyPlacementID:(NSString*)placementID; //This function has been abandoned

-(id)getPlacement:(NSString*) placementId; //This function has been abandoned

-(id)getPlsInstance:(NSString*) placementId; //This function has been abandoned

-(void)addPlsInstance:(NSString*) placementId object:(NSObject*)obj; //This function has been abandoned

-(void)setDoNotTrackStatus:(BOOL) status;//This function has been abandoned

-(BOOL)getDoNotTrackStatus;//This function has been abandoned
@end

NS_ASSUME_NONNULL_END
