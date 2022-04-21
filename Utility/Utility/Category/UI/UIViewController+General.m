//
//  UIViewController+General.m
//  Utility
//
//  Created by mrfeiwang on 2021/11/9.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import "UIViewController+General.h"

@implementation UIViewController (General)

+ (UIWindow *)appTopWindow {
    return [UIApplication sharedApplication].keyWindow;
}

+ (UIViewController *)getCurrentVC {
    UIViewController *rootVC = [UIApplication sharedApplication].keyWindow.rootViewController;
    UIViewController *currentVC = [UIViewController getCurrentVCFrom:rootVC];
    
    return currentVC;
}

+ (UIViewController *)getCurrentVCFrom:(UIViewController *)rootVC {
    UIViewController *currentVC = nil;
    
    if ([rootVC presentedViewController]) {
        rootVC = [rootVC presentedViewController];
    }
    if ([rootVC isKindOfClass:[UITabBarController class]]) {
        currentVC = [UIViewController getCurrentVCFrom:[(UITabBarController *)rootVC selectedViewController]];
    } else if ([rootVC isKindOfClass:[UINavigationController class]]) {
        currentVC = [UIViewController getCurrentVCFrom:[(UINavigationController *)rootVC visibleViewController]];
    } else {
        currentVC = rootVC;
    }
    
    return currentVC;
}

@end
