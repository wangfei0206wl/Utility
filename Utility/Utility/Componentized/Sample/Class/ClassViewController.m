//
//  ClassViewController.m
//  Utility
//
//  Created by 王飞 on 2022/5/12.
//

#import "ClassViewController.h"

@interface ClassViewController ()

@end

@implementation ClassViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = UIColor.systemPinkColor;
    
    UILabel *label = [UILabel labelWithFont:16 textColor:UIColor.blackColor text:@"课程"];
    [self.view addSubview:label];
    [label mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
    }];
}

@end
