//
//  UIView+Empty.h
//  Utility
//
//  Created by 王飞 on 2019/7/26.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Empty)

/**
 显示空视图提示

 @param icon 提示icon
 @param descString 提示信息
 */
- (void)showEmptyViewWithIcon:(NSString *)icon
                        title:(NSString *)descString;

/**
 显示空视图提示
 
 @param icon 提示icon
 @param size 如果为CGSizeZero，则使用图片原始大小
 @param descString 提示信息
 */
- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString;

/**
 显示空视图提示

 @param icon 提示icon
 @param size 如果为CGSizeZero，则使用图片原始大小
 @param descString 提示信息
 @param font 提示信息字体
 @param color 提示信息颜色
 */
- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString
                    titleFont:(UIFont *)font
                        color:(UIColor *)color;

/**
 显示空视图提示

 @param icon 提示icon
 @param size 如果为CGSizeZero，则使用图片原始大小
 @param descString 提示信息
 @param font 提示信息字体
 @param color 提示信息颜色
 @param offsetY 提示文字距离上方图标的y方向间距
 */
- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString
                    titleFont:(UIFont *)font
                        color:(UIColor *)color
                 titleOffsetY:(CGFloat)offsetY;

/**
 设置空视图xy方向偏移量
 
 @param offset 空视图xy方向偏移量
 */
- (void)setEmptyViewOffset:(CGPoint)offset;

/**
 隐藏空视图
 */
- (void)hideEmptyView;

/// 给空白视图添加tap手势
/// @param target 响应者
/// @param action 响应方法
- (void)addEmptyViewWithTarget:(id)target
                        action:(SEL)action;

@end
