//
//  UILabel+Factory.h
//  Utility
//
//  Created by 王飞 on 2018/11/28.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 快捷创建label类别
 */
@interface UILabel (Factory)

/**
 根据参数创建label(自动布局使用)

 @param fontSize 字体大小
 @param color 颜色
 @param text 文本
 @return 实例
 */
+ (UILabel *)labelWithFont:(CGFloat)fontSize textColor:(UIColor *)color text:(NSString *)text;

/**
 根据参数创建label(使用frame创建时)

 @param frame 尺寸
 @param fontSize 字体大小
 @param color 颜色
 @param text 文本
 @return 实例
 */
+ (UILabel *)labelWithFrame:(CGRect)frame font:(CGFloat)fontSize textColor:(UIColor *)color text:(NSString *)text;

/// 根据参数创建label
/// @param font 字体
/// @param color 颜色
/// @param text 文本
+ (UILabel *)labelWithTextFont:(UIFont *)font textColor:(UIColor *)color text:(NSString *)text;

/// 根据参数创建label(使用frame创建时)
/// @param frame 尺寸
/// @param font 字体
/// @param color 颜色
/// @param text 文本
+ (UILabel *)labelWithFrame:(CGRect)frame textFont:(UIFont *)font textColor:(UIColor *)color text:(NSString *)text;

@end
