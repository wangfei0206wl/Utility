//
//  TimerProxy.h
//  Demo
//
//  Created by 王飞 on 2022/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TimerProxy : NSProxy

@property (weak, nonatomic) id target;

+ (instancetype)proxyWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
