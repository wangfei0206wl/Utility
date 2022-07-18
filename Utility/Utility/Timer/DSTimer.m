//
//  DSTimer.m
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import "DSTimer.h"

@implementation DSTimer

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)timeInterval
                                     target:(id)target
                                   selector:(SEL)selector
                                   userInfo:(nullable id)userInfo
                                    repeats:(BOOL)repeats {
    DSTimer *dsTimer = [[DSTimer alloc] init];
    dsTimer.target = target;
    dsTimer.selector = selector;
    NSTimer *timer = [NSTimer scheduledTimerWithTimeInterval:timeInterval target:dsTimer selector:@selector(timered:) userInfo:userInfo repeats:repeats];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    return timer;
}

- (void)timered:(NSTimer *)timer {
    if ([self.target respondsToSelector:self.selector]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
        [self.target performSelector:self.selector withObject:timer];
#pragma clang diagnostic pop
    }
}

@end
