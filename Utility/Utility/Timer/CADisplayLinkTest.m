//
//  CADisplayLinkTest.m
//  Utility
//
//  Created by 王飞 on 2022/7/20.
//

#import "CADisplayLinkTest.h"

@interface CADisplayLinkTest ()

@property (nonatomic, strong) CADisplayLink *link;
@property (nonatomic, strong) UIImageView *imageView;

@end

@implementation CADisplayLinkTest

- (instancetype)init {
    self = [super init];
    
    if (self) {
        self.link = [CADisplayLink displayLinkWithTarget:self selector:@selector(linkClick)];
        self.link.paused = NO;
        [self.link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
        
        self.imageView = [[UIImageView alloc] init];
        self.imageView.image = [UIImage imageNamed:@"earth.jpeg"];
        [self addSubview:self.imageView];
        [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.equalTo(self);
            make.size.mas_equalTo(CGSizeMake(150, 150));
        }];
    }
    
    return self;
}

- (void)linkClick {
    NSLog(@"-------linkClick");
    self.imageView.transform = CGAffineTransformRotate(self.imageView.transform, M_PI / 240);
}

- (void)startAnimation {
    self.link.paused = NO;
}

- (void)stopAnimation {
    self.link.paused = YES;
    [self.link invalidate];
    self.link = nil;
}

@end
