//
//  DXPopover.h
//
//  Created by xiekw on 11/14/14.
//  Copyright (c) 2014 xiekw. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, DXPopoverPosition) {
    DXPopoverPositionUp = 1,
    DXPopoverPositionDown,
};

typedef NS_ENUM(NSUInteger, DXPopoverMaskType) {
    DXPopoverMaskTypeBlack,
    DXPopoverMaskTypeNone,  // overlay does not respond to touch
};

typedef void(^DismissedBlock)(CGPoint dismissedPoint, UIEvent *touchEvent);

@interface DXPopover : UIView

+ (instancetype)popover;

/**
 *  The contentView positioned in container, default is zero;
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 *  If the popover is stay up or down the showPoint
 */
@property (nonatomic, assign, readonly) DXPopoverPosition popoverPosition;

/**
 *  The popover arrow size, default is {10.0, 10.0};
 */
@property (nonatomic, assign) CGSize arrowSize;

/**
 *  The popover corner radius, default is 7.0;
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 *  The popover animation show in duration, default is 0.4;
 */
@property (nonatomic, assign) CGFloat animationIn;

/**
 *  The popover animation dismiss duration, default is 0.3;
 */
@property (nonatomic, assign) CGFloat animationOut;

/**
 *  If the drop in animation using spring animation, default is YES;
 */
@property (nonatomic, assign) BOOL animationSpring;

/**
 *  Add an animation that has the popover bounce up and down from a point, default is NO
 */
@property (nonatomic, assign) BOOL animationBounce;

/**
 *  The distance that the animation bounces, default is 12
 */
@property (nonatomic, assign) CGFloat bounceDistance;

/**
 *  The animation time for the bounce, default is 0.7
 */
@property (nonatomic, assign) CGFloat bounceAnimationTime;

/**
 *
 *  Adding a button to dismiss at the bottom of the Content View
 */
@property (nonatomic, assign) BOOL useDoneButton;

/**
 *
 *  Color For Done Button
 */
@property (nonatomic, assign) UIColor *buttonColor;

/**
 *
 *  Font for Done Button
 */
@property (nonatomic, assign) UIFont *textFont;

/**
 *
 *  Text Color for Done Button
 */
@property (nonatomic, assign) UIColor *textColor;

/**
 *  The background of the popover, default is DXPopoverMaskTypeBlack;
 */
@property (nonatomic, assign) DXPopoverMaskType maskType;

/**
 *  If maskType does not satisfy your need, use blackoverylay to control the touch
 * event(userInterfaceEnabled) for
 * background color
 */
@property (nonatomic, strong, readonly) UIControl *blackOverlay;

/**
 *  If the popover has the shadow behind it, default is YES, if you wanna custom the shadow, set it
 * by
 * popover.layer.shadowColor, shadowOffset, shadowOpacity, shadowRadius
 */
@property (nonatomic, assign) BOOL applyShadow;

/**
 *  when you using atView show API, this value will be used as the distance between popovers'arrow
 * and atView. Note:
 * this value is invalid when popover show using the atPoint API
 */
@property (nonatomic, assign) CGFloat betweenAtViewAndArrowHeight;

/**
 * Decide the nearest edge between the containerView's border and popover, default is 4.0
 */
@property (nonatomic, assign) CGFloat sideEdge;

/**
 *  The callback when popover did show in the containerView
 */
@property (nonatomic, copy) dispatch_block_t didShowHandler;

/**
 *  The callback when popover did dismiss in the containerView;
 */
@property (nonatomic, copy) DismissedBlock didDismissHandler;

/**
 *  Show API
 *
 *  @param point         the point in the container coordinator system.
 *  @param position      stay up or stay down from the showAtPoint
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain
 */
- (void)showAtPoint:(CGPoint)point
     popoverPostion:(DXPopoverPosition)position
    withContentView:(UIView *)contentView
             inView:(UIView *)containerView;

/**
 *  Lazy show API        The show point will be caluclated for you, try it!
 *
 *  @param atView        The view to show at
 *  @param position      stay up or stay down from the atView, if up or down size is not enough for
 * contentView, then it
 * will be set correctly auto.
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain
 */
- (void)showAtView:(UIView *)atView
    popoverPostion:(DXPopoverPosition)position
   withContentView:(UIView *)contentView
            inView:(UIView *)containerView;

/**
 *  Lazy show API        The show point and show position will be caluclated for you, try it!
 *
 *  @param atView        The view to show at
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain
 */
- (void)showAtView:(UIView *)atView
   withContentView:(UIView *)contentView
            inView:(UIView *)containerView;

/**
 *  Lazy show API        The show point and show position will be caluclated for you, using
 * application's keyWindow as
 * containerView, try it!
 *
 *  @param atView        The view to show at
 *  @param contentView   the contentView to show
 */
- (void)showAtView:(UIView *)atView withContentView:(UIView *)contentView;

- (void)showAtView:(UIView *)atView withText:(NSAttributedString *)abs;
- (void)showAtView:(UIView *)atView withText:(NSAttributedString *)abs inView:(UIView *)container;

- (void)dismiss;

@end
