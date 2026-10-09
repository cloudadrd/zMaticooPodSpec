#import <Foundation/Foundation.h>
#import <MaticooSDK/MaticooAds+ZMATResource.h>

// The prebuilt static SDK cannot resolve SPM's resource bundle by itself, so this file (compiled by SPM,
// where SWIFTPM_MODULE_BUNDLE is known) hands it over before main(). SPM nests MaticooSDK.bundle inside
// the generated module bundle, so pass the nested one.
__attribute__((constructor))
static void zmat_registerSPMResourceBundle(void) {
    NSURL *url = [SWIFTPM_MODULE_BUNDLE URLForResource:@"MaticooSDK" withExtension:@"bundle"];
    if (!url) {
        NSLog(@"[zMaticoo] MaticooSDK.bundle missing from %@", SWIFTPM_MODULE_BUNDLE.bundlePath);
        return;
    }
    [MaticooAds zmat_setSPMResourceBundle:[NSBundle bundleWithURL:url]];
#if DEBUG
    NSLog(@"[zMaticoo] SPM resource bundle registered: %@", url.path);
#endif
}
