//
//  UIButton+Factory.m
//  Utility
//
//  Created by 王飞 on 2018/12/19.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import "UIButton+Factory.h"

@implementation UIButton (Factory)

+ (UIButton *)buttonWithTitle:(NSString *)title
                        color:(UIColor *)titleColor
                         font:(CGFloat)fontSize
                        image:(UIImage *)image {
    return [UIButton buttonWithFrame:CGRectZero title:title color:titleColor font:fontSize image:image];
}

+ (UIButton *)buttonWithFrame:(CGRect)frame
                        title:(NSString *)title
                        color:(UIColor *)titleColor
                         font:(CGFloat)fontSize
                        image:(UIImage *)image {
    UIButton *button = nil;
    
    button = [UIButton buttonWithType:UIButtonTypeCustom];
    
    if (!CGRectEqualToRect(frame, CGRectZero)) {
        button.frame = frame;
    }
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitleColor:titleColor forState:UIControlStateNormal];
    button.titleLabel.font = [UIFont systemFontOfSize:fontSize];
    if (image) {
        [button setImage:image forState:UIControlStateNormal];
    }
    
    return button;
}

+ (UIButton *)buttonWithTitle:(NSString *)title
                        color:(UIColor *)titleColor
                    titleFont:(UIFont *)titleFont
                        image:(UIImage *)image {
    return [UIButton buttonWithFrame:CGRectZero title:title color:titleColor titleFont:titleFont image:image];
}

+ (UIButton *)buttonWithFrame:(CGRect)frame
                        title:(NSString *)title
                        color:(UIColor *)titleColor
                    titleFont:(UIFont *)titleFont
                        image:(UIImage *)image {
    UIButton *button = nil;
    
    button = [UIButton buttonWithType:UIButtonTypeCustom];
    
    if (!CGRectEqualToRect(frame, CGRectZero)) {
        button.frame = frame;
    }
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitleColor:titleColor forState:UIControlStateNormal];
    button.titleLabel.font = titleFont;
    if (image) {
        [button setImage:image forState:UIControlStateNormal];
    }
    
    return button;
}

+ (UIButton *)buttonWithNormalImage:(NSString *)normalImage
                     highlightImage:(NSString *)highlightImage
                             target:(id)target
                             action:(SEL)action {
    return [UIButton buttonWithFrame:CGRectZero normalImage:normalImage highlightImage:highlightImage target:target action:action];
}

+ (UIButton *)buttonWithFrame:(CGRect)frame
                  normalImage:(NSString *)normalImage
               highlightImage:(NSString *)highlightImage
                       target:(id)target
                       action:(SEL)action {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    
    button.frame = frame;
    [button setImage:[UIImage imageNamed:normalImage] forState:UIControlStateNormal];
    [button setImage:[UIImage imageNamed:highlightImage] forState:UIControlStateSelected];
    [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    
    return button;
}

@end
