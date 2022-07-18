//
//  ProxyTimer.m
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import "ProxyTimer.h"
#import "TimerProxy.h"

@implementation ProxyTimer

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)timeInterval
                                     target:(id)target
                                   selector:(SEL)selector
                                   userInfo:(nullable id)userInfo
                                    repeats:(BOOL)repeats {
    NSTimer *timer = [NSTimer scheduledTimerWithTimeInterval:timeInterval target:[TimerProxy proxyWithTarget:target] selector:selector userInfo:userInfo repeats:repeats];
    return timer;
}

@end
