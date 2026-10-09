//
//  MaticooAds+ZMATResource.h
//  zMaticooSDK
//
//  Private header (not in MaticooSDK.h). Used by the SPM wrapper target to hand the SDK its resource bundle.
//

#import <Foundation/Foundation.h>
#if __has_include(<MaticooSDK/MaticooAds.h>)
#import <MaticooSDK/MaticooAds.h>
#else
#import "MaticooAds.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MaticooAds (ZMATResource)

/// Pass the `MaticooSDK.bundle` itself (not the SPM module bundle that contains it). Takes precedence over the SDK's own lookup.
+ (void)zmat_setSPMResourceBundle:(nullable NSBundle *)bundle;

@end

NS_ASSUME_NONNULL_END
