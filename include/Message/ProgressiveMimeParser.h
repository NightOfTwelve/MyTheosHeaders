/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/Message.framework/Message
 */

#import <Foundation/NSObject.h>

@class NSArray, NSMutableData, NSData, MimePart;

@interface ProgressiveMimeParser : NSObject {
	NSMutableData* _data;
	NSArray* _preserveHeaders;
	id _delegate;
	id _context;
	unsigned _cursor;
	unsigned _lastLength;
	MimePart* _topLevelPart;
	MimePart* _currentPart;
	NSData* _currentBoundary;
	struct {
		unsigned delegateBeganMimePart : 1;
		unsigned delegateFinishedMimePart : 1;
		unsigned delegateBeganData : 1;
		unsigned delegateFailed : 1;
		unsigned state : 3;
	} _parserFlags;
}
-(id)initWithBodyData:(id)bodyData topLevelHeaders:(id)headers headersToPreserve:(id)preserve;
// inherited: -(void)dealloc;
-(void)start;
-(void)setDelegate:(id)delegate;
-(void)setContext:(id)context;
-(id)context;
-(void)noteDataLengthChanged:(unsigned)changed;
-(id)topLevelPart;
-(id)currentPart;
-(id)data;
-(void)_initializeTopLevelPartWithHeaders:(id)headers;
-(void)_continueParsingStartOfPart;
-(void)_continueParsingHeaders;
-(id)_currentBoundary;
-(void)_continueParsingBody;
-(void)_continueParsing;
-(void)_reportError:(id)error;
@end
