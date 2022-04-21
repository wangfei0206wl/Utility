//
//  UILabel+Factory.m
//  Utility
//
//  Created by 王飞 on 2018/11/28.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import "UILabel+Factory.h"

@implementation UILabel (Factory)

+ (UILabel *)labelWithFont:(CGFloat)fontSize textColor:(UIColor *)color text:(NSString *)text {
    return [UILabel labelWithFrame:CGRectZero font:fontSize textColor:color text:text];
}

+ (UILabel *)labelWithFrame:(CGRect)frame font:(CGFloat)fontSize textColor:(UIColor *)color text:(NSString *)text {
    UILabel *label = nil;
    
    if (CGRectEqualToRect(frame, CGRectZero)) {
        label = [[UILabel alloc] init];
    } else {
        label = [[UILabel alloc] initWithFrame:frame];
    }
    
    label.font = [UIFont systemFontOfSize:fontSize];
    if (color) label.textColor = color;
    label.text = text;
    
    return label;
}

+ (UILabel *)labelWithTextFont:(UIFont *)font textColor:(UIColor *)color text:(NSString *)text {
    return [UILabel labelWithFrame:CGRectZero textFont:font textColor:color text:text];
}

+ (UILabel *)labelWithFrame:(CGRect)frame textFont:(UIFont *)font textColor:(UIColor *)color text:(NSString *)text {
    UILabel *label = nil;
    
    if (CGRectEqualToRect(frame, CGRectZero)) {
        label = [[UILabel alloc] init];
    } else {
        label = [[UILabel alloc] initWithFrame:frame];
    }
    
    label.font = font;
    if (color) label.textColor = color;
    label.text = text;
    
    return label;
}

@end
