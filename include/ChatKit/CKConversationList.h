/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import <Foundation/NSObject.h>

@class CKService, CKConversation, NSMutableArray;

@interface CKConversationList : NSObject {
	NSMutableArray* _conversations;
	CKConversation* _pendingConversation;
	NSMutableArray* _groupsToDelete;
	BOOL _fullyLoaded;
	CKService* _service;
}
@property(readonly, assign, nonatomic) CKService* service;
-(id)initWithService:(id)service;
-(void)dealloc;
-(id)conversationForRecipients:(id)recipients create:(BOOL)create;
-(id)_recipientForMessage:(id)message;
-(id)_createConversationForMessage:(id)message groupID:(int)id;
-(id)_conversationForMessage:(id)message groupID:(int)id create:(BOOL)create;
-(id)conversationForGroupID:(int)groupID;
-(id)existingConversationForGroupID:(int)groupID;
-(id)conversationForMessage:(id)message create:(BOOL)create;
-(void)resetCaches;
-(void)fixupNames;
-(id)activeConversations;
-(void)_addGroupToDeletionSchedule:(int)deletionSchedule;
-(void)_deleteGroups;
-(id)loadedConversations;
-(id)conversations;
-(id)existingConversationForAddresses:(id)addresses;
-(void)resort;
-(void)_conversationChanged;
-(void)addConversation:(id)conversation;
-(void)unpendConversation;
-(void)applyPendingConversation;
-(id)pendingConversation:(BOOL)conversation;
-(int)unreadCount;
-(void)deleteConversationAtIndex:(int)index;
@end

