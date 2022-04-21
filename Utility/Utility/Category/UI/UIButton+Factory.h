//
//  UIButton+Factory.h
//  Utility
//
//  Created by 王飞 on 2018/12/19.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 创建按钮工厂
 */
@interface UIButton (Factory)

/**
 根据参数创建按钮(自动布局)

 @param title 标题
 @param titleColor 颜色
 @param fontSize 字体大小
 @param image 按钮图片
 @return 按钮
 */
+ (UIButton *)buttonWithTitle:(NSString *)title
                        color:(UIColor *)titleColor
                         font:(CGFloat)fontSize
                        image:(UIImage *)image;

/**
 根据参数创建按钮(frame)

 @param frame 按钮大小
 @param title 标题
 @param titleColor 颜色
 @param fontSize 字体大小
 @param image 按钮图片
 @return 按钮
 */
+ (UIButton *)buttonWithFrame:(CGRect)frame
                        title:(NSString *)title
                        color:(UIColor *)titleColor
                         font:(CGFloat)fontSize
                        image:(UIImage *)image;

/// 根据参数创建按钮(自动布局)
/// @param title 标题
/// @param titleColor 颜色
/// @param titleFont 字体
/// @param image 按钮图片
+ (UIButton *)buttonWithTitle:(NSString *)title
                        color:(UIColor *)titleColor
                    titleFont:(UIFont *)titleFont
                        image:(UIImage *)image;

/// 根据参数创建按钮(frame)
/// @param frame 按钮大小
/// @param title 标题
/// @param titleColor 颜色
/// @param titleFont 字体
/// @param image 按钮图片
+ (UIButton *)buttonWithFrame:(CGRect)frame
                        title:(NSString *)title
                        color:(UIColor *)titleColor
                    titleFont:(UIFont *)titleFont
                        image:(UIImage *)image;

/**
 根据参数创建按钮(仅icon的按钮)

 @param normalImage 正常状态图标
 @param highlightImage 高亮状态图标
 @param target 事件处理对象
 @param action 事件处理方法
 @return 按钮
 */
+ (UIButton *)buttonWithNormalImage:(NSString *)normalImage
                     highlightImage:(NSString *)highlightImage
                             target:(id)target
                             action:(SEL)action;

/**
 根据参数创建按钮(仅icon的按钮)
 
 @param frame 按钮大小
 @param normalImage 正常状态图标
 @param highlightImage 高亮状态图标
 @param target 事件处理对象
 @param action 事件处理方法
 @return 按钮
 */
+ (UIButton *)buttonWithFrame:(CGRect)frame
                  normalImage:(NSString *)normalImage
                     highlightImage:(NSString *)highlightImage
                             target:(id)target
                             action:(SEL)action;
@end
