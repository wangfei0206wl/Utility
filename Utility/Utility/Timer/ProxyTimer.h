//
//  ProxyTimer.h
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ProxyTimer : NSObject

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)timeInterval
                                     target:(id)target
                                   selector:(SEL)selector
                                   userInfo:(nullable id)userInfo
                                    repeats:(BOOL)repeats;

@end

NS_ASSUME_NONNULL_END
