/**
 * This header is generated by class-dump-z 0.1-11s.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/Preferences.framework/Preferences
 */

#import "Preferences-Structs.h"
#import "PSTableCell.h"

@class UIImageView;

@interface PSImageCell : PSTableCell {
	UIImageView* _imageView;
}
-(void)setImageView:(id)view;
-(void)drawTitleInRect:(CGRect)rect selected:(BOOL)selected;
@end

