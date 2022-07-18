//
//  OCRelevantTest.m
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import "OCRelevantTest.h"
#import "Timer/TimerTest.h"

@implementation OCRelevantTest

+ (void)test {
    
#if 1
    [OCRelevantTest timerTest];
#endif
    
}

TimerTest *g_timerTestObj = nil;
+ (void)timerTest {
    g_timerTestObj = [[TimerTest alloc] init];
    [g_timerTestObj test];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        g_timerTestObj = nil;
    });
}

@end
