//
//  SampleManager.m
//  Utility
//
//  Created by 王飞 on 2022/5/12.
//

#import "SampleManager.h"
#import "Person/PersonViewController.h"

@implementation SampleManager

+ (void)showSample:(UIViewController *)vc {
    PersonViewController *personVC = [[PersonViewController alloc] init];
    UINavigationController *navi = [[UINavigationController alloc] initWithRootViewController:personVC];
    
    [vc presentViewController:navi animated:YES completion:nil];
}

@end
