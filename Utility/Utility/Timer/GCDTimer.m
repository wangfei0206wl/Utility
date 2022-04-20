//
//  GCDTimer.m
//  Demo
//
//  Created by 王飞 on 2022/4/20.
//

#import "GCDTimer.h"

static NSMutableDictionary *timers;
dispatch_semaphore_t semaphore;

@implementation GCDTimer

+ (void)initialize {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        timers = [NSMutableDictionary dictionary];
        semaphore = dispatch_semaphore_create(1);
    });
}

+ (NSString *)timerTask:(void(^)(void))task
                  start:(NSTimeInterval)start
               interval:(NSTimeInterval)interval
                repeats:(BOOL)repeats
                  async:(BOOL)async {
    if (!task || start < 0 || (interval <= 0 && repeats)) {
        return nil;
    }
    
    dispatch_queue_t queue = async ? dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0) : dispatch_get_main_queue();
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    NSString *timerName = [NSString stringWithFormat:@"%zd", timers.count];
    timers[timerName] = timer;
    dispatch_semaphore_signal(semaphore);
    
    dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, start * NSEC_PER_SEC), interval * NSEC_PER_SEC, 0);
    dispatch_source_set_event_handler(timer, ^{
        task();
        if (!repeats) {
            [self cancelTimer: timerName];
        }
    });
    dispatch_resume(timer);
    
    return timerName;
}

+ (NSString *)timerTask:(id)target
               selector:(SEL)selector
                  start:(NSTimeInterval)start
               interval:(NSTimeInterval)interval
                repeats:(BOOL)repeats
                  async:(BOOL)async {
    if (!target || !selector) {
        return nil;
    }
    return [self timerTask:^{
        if ([target respondsToSelector:selector]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
            [target performSelector:selector];
#pragma clang diagnostic pop
        }
    } start:start interval:interval repeats:repeats async:async];
}

+ (void)cancelTimer:(NSString *)timerName {
    if (timerName.length == 0) {
        return;
    }
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
    dispatch_source_t timer = timers[timerName];
    if (timer) {
        dispatch_source_cancel(timer);
        [timers removeObjectForKey:timerName];
    }
    
    dispatch_semaphore_signal(semaphore);
}

@end
