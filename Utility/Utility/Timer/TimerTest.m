//
//  TimerTest.m
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import "TimerTest.h"
#import "GCDTimer.h"
#import "TimerProxy.h"

#define kGCDTimerEnable (0)
#define kTimerProxyEnable (1)

NSString *g_timerName = nil;
NSTimer *g_timer = nil;

@implementation TimerTest

- (void)test {
    
#if kGCDTimerEnable
    [self gcdTimerTest];
#endif
    
#if kTimerProxyEnable
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
    
#if kTimerProxyEnable
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
    TimerProxy *proxy = [TimerProxy proxyWithTarget:self];
    g_timer = [NSTimer scheduledTimerWithTimeInterval:1 target:proxy selector:@selector(handleTimerFunc) userInfo:nil repeats:YES];
}

- (void)handleTimerFunc {
    static int count = 0;
    NSLog(@"NSTimer is echo %d", count);
    count++;
}

@end
