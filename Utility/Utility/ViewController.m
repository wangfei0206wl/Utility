//
//  ViewController.m
//  Utility
//
//  Created by 王飞 on 2022/4/20.
//

#import "ViewController.h"
#import "AlgorithmHelper.h"
#import "SampleManager.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
#if 0
    [AlgorithmHelper test];
#endif

#if 1
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [SampleManager showSample:self];
    });
#endif
}


@end
