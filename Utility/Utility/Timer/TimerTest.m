//
//  TimerTest.m
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import "TimerTest.h"
#import "GCDTimer.h"
#import "ProxyTimer.h"

#define kGCDTimerEnable (0)
#define kProxyTimerEnable (1)

NSString *g_timerName = nil;
NSTimer *g_timer = nil;

@implementation TimerTest

- (void)test {
    
#if kGCDTimerEnable
    [self gcdTimerTest];
#endif
    
#if kProxyTimerEnable
    [self timerProxyTest];
#endif
    
}

- (void)dealloc {
    NSLog(@"timerTest dealloc");
#if kGCDTimerEnable
    if (g_timerName) {
        [GCDTimer cancelTimer:g_timerName];
    }
#endif
    
#if kProxyTimerEnable
    if (g_timer) {
        [g_timer invalidate];
        g_timer = nil;
    }
#endif
}

- (void)gcdTimerTest {
    __block int count = 0;
    g_timerName = [GCDTimer timerTask:^{
        NSLog(@"gcd timer is echo %d", count);
        count++;
    } start:0.3 interval:1 repeats:YES async:YES];
}

- (void)timerProxyTest {
    g_timer = [ProxyTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(handleTimerFunc) userInfo:nil repeats:YES];
}

- (void)handleTimerFunc {
    static int count = 0;
    NSLog(@"NSTimer is echo %d", count);
    count++;
}

@end
