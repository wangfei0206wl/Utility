APP的生命流程

1、APP的启动流程(pre-main)
    a) 系统加载解析APP的info.plist文件
        获取APP的运行条件、是否全屏、APP启动图等
    b) 创建沙盒
        iOS8后，每次APP启动都会生成新的沙盒路径
    c) 根据info.plist检查相应的权限状态
    d) 加载Mach-O文件，读取dyld路径并运行dyld动态链接器
        系统内核加载主程序，dyld只负责动态库的加载
        ii) dyld寻找合适的CPU运行环境
        ii) dyld加载依赖库并对库进行链接
        ii) 加载所有方法(runtime在此完成初始化及OC的内存布局)
        ii) 加载C函数
        ii) 加载category（此处runtime对所有类结构进行初始化）
        ii) 加载C++静态函数及+load方法
        ii) dyld返回main函数地址，main函数调起


2、APP的初始化流程(main)
    a) main函数
    b) 执行UIApplicationMain
        ii) 创建UIApplication对象
        ii) 创建UIApplication的delegate对象
        ii) 创建MainRunloop
        ii) 监听系统事件
    c) 根据info.plist获取主storyboard文件并加载
    d) 程序启动完毕调用代理方法application:didFinishLaunchingWithOptions:
        在此方法中创建UIWindow，创建并设置rootViewController
    e) 显示第一个窗口
        

3、APP的运行时生命周期
    ViewController的生命周期


APP生命期的优化
1、APP启动流程(pre-main)的优化
    a) 减少系统依赖库
        库越少dyld加载速度越快，越早进行main函数
    b) 减少第三方库
    c) 优先使用静态库，合并多个动态库为一个动态库
        动态库的加载方式比静态库慢
    d) framework根据情况设置optional和required
        framework在所有iOS系统都支持，则设置为required，否则设置为optional
        required（强引用）的framework一定会被加载到内存中，即使不使用也会加载
        optional（弱引用）的framework启动时不会加载，只在使用的时候才进行加载，可减少启动时加载动态库的时间
    e) 将不必须在+load方法中做的事情延迟到+initialize中，尽量不要用C++虚函数
    f) 减少项目文件中Category，静态变量等
    g) 使用appCode检查项目中没用的类和方法，并删除
    h) 将UI资源压缩到最小
        启动加载时会加载资源图片进行IO操作，所以图片小加载速度也会提升
    i) 内存上优化，类和方法名不要太长
        iOS类和方法名都在__cstring段里保存相应的字符串值
2、APP初始化流程的优化
    a) 尽量使用纯代码进行UI的搭建，不使用xib或storyboard
        xib和storyboard需要解析成代码来渲染页面，会增加代码的执行效率，从而增加启动时长
    b) 尽量减少application:didFinishLaunchingWithOptions:中代码的执行时间
        能多线程尽量多线程，能后台执行就后台执行，能延迟执行的就延迟执行
        不要阻塞主线程从而造成启动时间加长

其他细碎点整理

Mach-O文件
OSX与iOS系统上的可执行文件格式，可使用otool工具查看，分为3部分
1、Header：保存基本信息（运行的平台、文件类型、LoadCommands的个数等）
2、LoadCommands: 加载命令，确定内存分布及相关的加载命令（main函数的地址, dyld的文件路径，依赖库的文件路径等）
3、Data: 每个segment，包含有具体的代码、数据等

安全 - ASLR（Address Space Layout Randomization 地址空间布局随机化）
镜像会在随机的地址上加载

代码签名
为了运行时验证Mach-O文件的签名，把文件每页内容都生成一个单独的加密散列值，并把值存于__LINKEDIT中。
使得文件的每一页内容都能被检验保证不会被篡改。

dyld
动态链接器，主要职责是完成库的链接，C++实现
系统从xnu(内核态)把控制权交给dyld（用户态）后
1、dyld先初始化程序环境，把可执行文件及系统依赖库、第三方库加载至内存
2、生成对应的image对象（镜像文件），对image进行链接，调用各image的初始化方法等
   runtime就是在此过程中被初始化的
以上大都在dyld:_main方法中执行

冷启动、热启动
程序第一次被启动，程序的代码会被dyld缓存起来，即使杀掉进程再次启动加载也会快一些（热启动）；
如果长时间没有启动或当前dyld的缓存被其他应用占据，则需要重新加载整个程序，花费的时间也就长一些（冷启动）。

启动时间检测
Xcode->Edit Scheme->Run->Auguments设置环境变量DYLD_PRINT_STATISTICS为1，即可打印启动耗时内容

app生命周期相关方法说明

1、 app启动完毕后就会调用
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions

2、 即将进入非活动状态，比如当有电话进来或短信进来或锁屏等
- (void)applicationWillResignActive:(UIApplication *)application

3、 app进入后台，当挂起时，程序还是停留在内存中的，当系统内存低时，系统就把挂起的程序清除掉，为前台程序提供更多的内存
- (void)applicationDidEnterBackground:(UIApplication *)application

4、 在程序进入后台时，添加此方法，则程序进入后台10分钟内，程序还在运行，并可以响应一些消息
[[UIApplication sharedApplication] beginBackgroundTaskWithExpirationHandler:^{
        NSLog(@"程序关闭");
}];

5、 app即将进入前台
- (void)applicationWillEnterForeground:(UIApplication *)application

6、 app激活（获取焦点）
- (void)applicationDidBecomeActive:(UIApplication *)application

7、 内存警告
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application

8、 app即将退出
- (void)applicationWillTerminate:(UIApplication *)application


相关资料
1、iOS-APP的启动流程和生命周期
https://www.jianshu.com/p/229dd6190b95

2、iOS应用的启动流程和优化详解
https://juejin.cn/post/6951591401528229895
