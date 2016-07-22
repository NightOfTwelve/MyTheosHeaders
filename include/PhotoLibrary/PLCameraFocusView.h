/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/PhotoLibrary.framework/PhotoLibrary
 */

#import <UIKit/UIView.h>

@class CAKeyframeAnimation, NSArray;

@interface PLCameraFocusView : UIView {
	NSArray* _images;
	CAKeyframeAnimation* _contentsAnimation;
	CAKeyframeAnimation* _boundsAnimation;
}
-(id)init:(BOOL)init;
// inherited: -(void)dealloc;
-(id)_createContentsAnimation;
-(id)_createBoundsAnimation;
-(void)startAnimating;
-(void)stopAnimating;
-(void)_fadeOut;
-(void)_fadeOutDidFinish;
-(void)focusDidEnd;
@end

