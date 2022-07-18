############################################################################################
gcd timer vs nstimer
############################################################################################
nstimer简介

通过runloop实现，两种初始化方式：invocation、selector
scheduledTimerWithTimeInterval创建timer并将timer添加到runloop，mode为NSDefaultRunLoopMode
timerWithTimeInterval只创建timer，需手动将timer添加到runloop中

子线程中使用NSTimer时，由于子线程没有默认开启runloop，所以子线程中使用NSTimer时需手动开启runloop
NSTimer *timer = [NSTimer timeWithInterval....];
[[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
[[NSRunLoop currentRunLoop] run];

问题:
其一 在耗时操作较多时，会出现延时问题
其二 受runloop mode的影响（scrollview滚动时出现timer不工作的问题）
    滚动时runloop mode变成了UITrackingRunLoopMode模式
    默认nstimer是加在defaultMode上，解决上述问题时需要将nstimer加在commonModes上
其三 selector方式时需要考虑循环引用问题(TimerProxy是其解决方案之一)

解决NSTimer循环引用问题方案
1)使用NSProxy弱引用target对象，使用消息转发方式来解决循环引用问题（参考ProxyTimer)
2)封装NSTimer弱引用target对象，解决循环引用问题（参考DSTimer）
3)使用NSTimer的block方式



