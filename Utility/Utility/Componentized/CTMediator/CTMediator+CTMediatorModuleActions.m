//
//  CTMediator+CTMediatorModuleActions.m
//  Utility
//
//  Created by 王飞 on 2022/5/12.
//

#import "CTMediator+CTMediatorModuleActions.h"

NSString * const kCTMediatorTargetAction = @"Action";

NSString * const kCTMEdiatorActionNativeFetchClassViewController = @"nativeFetchClassViewController";

@implementation CTMediator (CTMediatorModuleActions)

- (UIViewController *)CTMediator_viewControllerForClass {
    UIViewController *vc = [self performTarget:kCTMediatorTargetAction
                                        action:kCTMEdiatorActionNativeFetchClassViewController
                                        params:nil
                             shouldCacheTarget:NO];
    
    if ([vc isKindOfClass:[UIViewController class]]) {
        return vc;
    } else {
        return [[UIViewController alloc] init];
    }
}

@end
