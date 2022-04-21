//
//  GlobalMacro.h
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#ifndef GlobalMacro_h
#define GlobalMacro_h

//Log宏
#ifdef DEBUG
    #define NSLog(fmt, ...) NSLog((fmt), ##__VA_ARGS__);
#else
    #define NSLog(...);
#endif


//#define SR_IS_IPHONEX [SRUtilities is_IphoneX]
//#define SR_IS_IPAD [SRUtilities is_Ipad]
////底部安全区高度
//#define SR_BOTTOM_SAFA_AREA_HEIGHT ([SRUtilities is_IphoneX]?34:0)
//顶部状态栏的高度,适配X
#define SR_STATUSBAR_HEIGHT [[UIApplication sharedApplication] statusBarFrame].size.height
//导航高度(导航+状态栏),适配X
#define SR_NAVBAR_HEIGHT (44 + SR_STATUSBAR_HEIGHT)
// 获取屏幕高、宽
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

//判断字符串是否有效
#define SR_IS_STRING_VALID(text) (text && [text isKindOfClass:[NSString class]] && [text length]>0)

// 字符串安全处理(用于字典设置object时)
#define SR_SAFE_STRING(str)  ((str == nil)?@"":str)

//设置颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define HEX_COLOR(hex,a) [UIColor colorWithRed:((float)((hex&0xFF0000)>>16))/255.0 green:((float)((hex&0xFF00)>>8))/255.0 blue:((float)(hex&0xFF))/255.0 alpha:(a)]

#ifndef rb_dispatch_main_async_safe
#define rb_dispatch_main_async_safe(block)\
    if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue())) {\
        block();\
    } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
    }
#endif

#endif /* GlobalMacro_h */
