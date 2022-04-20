//
//  TimerProxy.m
//  Demo
//
//  Created by 王飞 on 2022/4/20.
//

#import "TimerProxy.h"

@implementation TimerProxy

+ (instancetype)proxyWithTarget:(id)target {
    TimerProxy *proxy = [TimerProxy alloc];
    proxy.target = target;
    return proxy;
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel {
    return [self.target methodSignatureForSelector:sel];
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    [invocation invokeWithTarget:self.target];
}

@end
