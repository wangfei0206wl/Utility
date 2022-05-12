//
//  PersonViewController.m
//  Utility
//
//  Created by 王飞 on 2022/5/12.
//

#import "PersonViewController.h"
#import "CTMediator+CTMediatorModuleActions.h"

@interface PersonViewController ()

@end

@implementation PersonViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = UIColor.lightGrayColor;
    
    UIButton *btnSkip = [UIButton buttonWithTitle:@"跳转至课程" color:UIColor.blackColor font:14 image:nil];
    [btnSkip addTarget:self action:@selector(onClickSkip:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnSkip];
    [btnSkip mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
    }];
}

- (void)onClickSkip:(id)sender {
    UIViewController *vc = [[CTMediator sharedInstance] CTMediator_viewControllerForClass];
    [self.navigationController pushViewController:vc animated:YES];
}

@end
