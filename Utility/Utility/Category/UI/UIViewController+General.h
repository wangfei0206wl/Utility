//
//  UIViewController+General.h
//  Utility
//
//  Created by mrfeiwang on 2021/11/9.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (General)

/// 最上层window
+ (UIWindow *)appTopWindow;

/// 当前vc
+ (UIViewController *)getCurrentVC;

@end

NS_ASSUME_NONNULL_END
