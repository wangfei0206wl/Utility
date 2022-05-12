//
//  Target_Action.m
//  Utility
//
//  Created by 王飞 on 2022/5/12.
//

#import "Target_Action.h"
#import "ClassViewController.h"

@implementation Target_Action

- (UIViewController *)Action_nativeFetchClassViewController:(NSDictionary *)params {
    ClassViewController *vc = [[ClassViewController alloc] init];
    // vc是否需要根据params做一些初始化
    return vc;
}

@end
