//
//  ViewController.m
//  Utility
//
//  Created by 王飞 on 2022/4/20.
//

#import "ViewController.h"
#import "AlgorithmHelper.h"
#import "SampleManager.h"
#import "OCRelevantTest.h"
#import "CADisplayLinkTest.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
#if 1
    [AlgorithmHelper test];
#endif
    
#if 0
    [OCRelevantTest test];
#endif

#if 0
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [SampleManager showSample:self];
    });
#endif
    
#if 0
    CADisplayLinkTest *test = [[CADisplayLinkTest alloc] init];
    [self.view addSubview:test];
    [test mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
        make.size.mas_equalTo(CGSizeMake(200, 200));
    }];
#endif
}


@end
