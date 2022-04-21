//
//  UIView+Empty.m
//  Utility
//
//  Created by 王飞 on 2019/7/26.
//  Copyright © 2022 wangfei. All rights reserved.
//

#import "UIView+Empty.h"
#import <objc/runtime.h>
#import <Masonry/Masonry.h>
#import "UILabel+Factory.h"

// 关联对象对应的key的定义
#define UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY (@selector(showEmptyViewWithIcon:iconSize:title:titleFont:color:titleOffsetY:))

@implementation UIView (Empty)

- (void)showEmptyViewWithIcon:(NSString *)icon
                        title:(NSString *)descString {
    [self showEmptyViewWithIcon:icon
                       iconSize:CGSizeZero
                          title:descString];
}

- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString {
    [self showEmptyViewWithIcon:icon
                       iconSize:size
                          title:descString
                      titleFont:[UIFont systemFontOfSize:12]
                          color:HEX_COLOR(0x6d6d6d, 1)];
}

- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString
                    titleFont:(UIFont *)font
                        color:(UIColor *)color {
    [self showEmptyViewWithIcon:icon
                       iconSize:size
                          title:descString
                      titleFont:font
                          color:color
                   titleOffsetY:10];
}

- (void)showEmptyViewWithIcon:(NSString *)icon
                     iconSize:(CGSize)size
                        title:(NSString *)descString
                    titleFont:(UIFont *)font
                        color:(UIColor *)color
                 titleOffsetY:(CGFloat)offsetY {
    // 先删掉旧的空视图
    [self hideEmptyView];
    
    UIView *emptyView = [[UIView alloc] init];
    [self addSubview:emptyView];
    
    UIImageView *imageView = [[UIImageView alloc] init];
    imageView.image = [UIImage imageNamed:icon];
    [emptyView addSubview:imageView];
    
    UILabel *titleLabel = [UILabel labelWithFont:12 textColor:color text:descString];
    titleLabel.font = font;
    titleLabel.numberOfLines = 0;
    titleLabel.textAlignment = NSTextAlignmentCenter;
    [emptyView addSubview:titleLabel];
    
    [emptyView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self);
    }];
    [imageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(emptyView);
        make.centerX.equalTo(emptyView);
        if (!CGSizeEqualToSize(size, CGSizeZero)) {
            make.size.mas_equalTo(size);
        }
    }];
    [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(imageView.mas_bottom).offset(offsetY);
        make.left.right.centerX.bottom.equalTo(emptyView);
        make.width.mas_greaterThanOrEqualTo(@(200));
    }];
    
    objc_setAssociatedObject(self, UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY, emptyView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setEmptyViewOffset:(CGPoint)offset {
    UIView *emptyView = objc_getAssociatedObject(self, UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY);
    
    if (emptyView) {
        [emptyView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.centerX.equalTo(self).offset(-offset.x);
            make.centerY.equalTo(self).offset(-offset.y);
        }];
    }
}

- (void)hideEmptyView {
    UIView *emptyView = objc_getAssociatedObject(self, UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY);
    
    if (emptyView.superview) {
        [emptyView removeFromSuperview];
        objc_setAssociatedObject(self, UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
}

- (void)addEmptyViewWithTarget:(id)target
                        action:(SEL)action {
    UIView *emptyView = objc_getAssociatedObject(self, UIVIEW_EMPTY_VIEW_ASSOCIATED_KEY);
    
    if (emptyView) {
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:target action:action];
        [emptyView addGestureRecognizer:tap];
    }
}

@end
