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

############################################################################################
gcd timer简介

利用GCD中的Dispatch Source中的一种类型DISPATCH_SOURCE_TYPE_TIMER来实现，监听系统内核对象并处理
更加的精准，不依赖runloop，不会出现滚动视图滚动时定时器不工作的情况。
GCD定时器提供了启动、暂停、恢复、取消等功能

流程
dispatch_source_create创建一个timer类型的源
dispatch_source_set_timer设置定时器
dispatch_source_set_event_handler设置定时任务
dispatch_resume启动定时器
dispatch_suspend暂停定时器
dispatch_source_cancel停止定时器

GCD Timer的封装参考GCDTimer

############################################################################################
GCD Timer 对比 NSTimer

1)NSTimer依赖runloop，所有子线程使用NSTimer需要手动启动runloop，而GCD Timer不依赖于runloop，在子线程中可正常运行.
2)NSTimer依赖于runloop运行，在某种特定环境下可能会需要runloop模式切换.
3)NSTimer存在延时的可能性，准确性会有误差，GCD Timer是监听系统内核对象并处理，定时更加精确.
4)NSTimer容易出现循环引用，GCD Timer相对要好很多.

############################################################################################
参考

iOS定时器-- NSTimer&GCD定时器
https://juejin.cn/post/6844904094826512392

iOS gcdTimer VS NSTimer
https://www.jianshu.com/p/6257361716fd

ios NSTimer和GCDtimer对比
https://blog.csdn.net/u014600626/article/details/102080330

