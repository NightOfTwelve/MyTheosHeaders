/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/Frameworks/MediaPlayer.framework/MediaPlayer
 */

#import "MediaPlayer-Structs.h"
#import "MPTransitionController.h"

@class UIView, MPVideoView, UINavigationBar;

@interface MPVideoTransferTransitionController : MPTransitionController {
	MPVideoView* _inflightVideoView;
	UINavigationBar* _portraitNavigationBar;
	UIView* _transitionBehindView;
}
@property(retain, nonatomic) UINavigationBar* portraitNavigationBar;
@property(retain, nonatomic) UIView* transitionBehindView;
-(id)init;
-(void)dealloc;
-(void)transition:(unsigned)transition;
-(void)_animationDidStop;
-(void)_prepareViews;
-(void)_transformView:(id)view forOrientation:(int)orientation bounds:(CGRect)bounds;
-(void)_updateStatusBar;
@end

