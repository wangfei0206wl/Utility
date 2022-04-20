//
//  GCDTimer.h
//  Demo
//
//  Created by 王飞 on 2022/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GCDTimer : NSObject

+ (NSString *)timerTask:(void(^)(void))task
                  start:(NSTimeInterval)start
               interval:(NSTimeInterval)interval
                repeats:(BOOL)repeats
                  async:(BOOL)async;

+ (NSString *)timerTask:(id)target
               selector:(SEL)selector
                  start:(NSTimeInterval)start
               interval:(NSTimeInterval)interval
                repeats:(BOOL)repeats
                  async:(BOOL)async;

+ (void)cancelTimer:(NSString *)timerName;

@end

NS_ASSUME_NONNULL_END
