//
//  libOBJCIPC_IMOKH_WA
//  IPC.h
//
//  Created by Alan Yip on 6 Feb 2014
//  Copyright 2014 Alan Yip. All rights reserved.
//

#import "header.h"

@interface OBJCIPC_IMOKH_WA : NSObject {
	
	BOOL _activated;
	
	// SpringBoard server port
	NSUInteger _serverPort;
	
	// process assertions
	NSMutableDictionary *_processAssertions;
	
	// store active connections (each contains its own streams)
	NSMutableSet *_pendingConnections;
	NSMutableDictionary *_activeConnections;
	
	// message handlers and queues
	NSMutableDictionary *_globalIncomingMessageHandlers;
	NSMutableDictionary *_incomingMessageHandlers;
	NSMutableDictionary *_outgoingMessageQueue;
}

@property(nonatomic) BOOL activated;
@property(nonatomic) NSUInteger serverPort;
@property(nonatomic, retain) NSMutableDictionary *processAssertions;
@property(nonatomic, retain) NSMutableSet *pendingConnections;
@property(nonatomic, retain) NSMutableDictionary *activeConnections;
@property(nonatomic, retain) NSMutableDictionary *globalIncomingMessageHandlers;
@property(nonatomic, retain) NSMutableDictionary *incomingMessageHandlers;
@property(nonatomic, retain) NSMutableDictionary *outgoingMessageQueue;

// process checking methods
+ (BOOL)isSpringBoard;
+ (BOOL)isBackBoard;
+ (BOOL)isApp;

// retrieve the shared instance
+ (instancetype)sharedInstance;

// these two methods will be called automatically when needed
+ (void)activate;
+ (void)deactivate;

// or manually close the connection between an app and SpringBoard
+ (void)deactivateAppWithIdentifier:(NSString *)identifier;

// launch app in background (called in SpringBoard)
+ (BOOL)launchAppWithIdentifier:(NSString *)identifier stayInBackground:(BOOL)stayInBackground;
+ (BOOL)setAppWithIdentifier:(NSString *)identifier inBackground:(BOOL)inBackground;

/*** Asynchronous message delivery ***/

// SpringBoard* -----> App
+ (BOOL)sendMessageToAppWithIdentifier:(NSString *)identifier messageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary replyHandler:(OBJCIPC_IMOKH_WAReplyHandler)handler;

// App* -----> SpringBoard
+ (BOOL)sendMessageToSpringBoardWithMessageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary replyHandler:(OBJCIPC_IMOKH_WAReplyHandler)handler;

/*** Synchronous message delivery ***/

// SpringBoard* -----> App
+ (NSDictionary *)sendMessageToAppWithIdentifier:(NSString *)identifier messageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary;

// App* -----> SpringBoard
+ (NSDictionary *)sendMessageToSpringBoardWithMessageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary;

/*** Register incoming message handler ***/

// App -----> SpringBoard*
+ (void)registerIncomingMessageFromAppHandlerForMessageName:(NSString *)messageName handler:(OBJCIPC_IMOKH_WAIncomingMessageHandler)handler;
+ (void)unregisterIncomingMessageFromAppHandlerForMessageName:(NSString *)messageName;

+ (void)unregisterIncomingMessageHandlerForAppWithIdentifier:(NSString *)identifier andMessageName:(NSString *)messageName;
+ (void)registerIncomingMessageHandlerForAppWithIdentifier:(NSString *)identifier andMessageName:(NSString *)messageName handler:(OBJCIPC_IMOKH_WAIncomingMessageHandler)handler;
+ (void)unregisterIncomingMessageHandlerForAppWithIdentifier:(NSString *)identifier andMessageName:(NSString *)messageName;

// SpringBoard -----> App*
+ (void)registerIncomingMessageFromSpringBoardHandlerForMessageName:(NSString *)messageName handler:(OBJCIPC_IMOKH_WAIncomingMessageHandler)handler;
+ (void)unregisterIncomingMessageFromSpringBoardHandlerForMessageName:(NSString *)messageName;

/*** For testing purpose ***/

+ (void)registerTestIncomingMessageHandlerForAppWithIdentifier:(NSString *)identifier;
+ (void)registerTestIncomingMessageHandlerForSpringBoard;
+ (void)sendAsynchronousTestMessageToAppWithIdentifier:(NSString *)identifier;
+ (void)sendAsynchronousTestMessageToSpringBoard;
+ (NSDictionary *)sendSynchronousTestMessageToAppWithIdentifier:(NSString *)identifier;
+ (NSDictionary *)sendSynchronousTestMessageToSpringBoard;

// manage connections
- (OBJCIPC_IMOKH_WAConnection *)activeConnectionWithAppWithIdentifier:(NSString *)identifier;
- (void)addPendingConnection:(OBJCIPC_IMOKH_WAConnection *)connection;
- (void)notifyConnectionBecomesActive:(OBJCIPC_IMOKH_WAConnection *)connection;
- (void)notifyConnectionIsClosed:(OBJCIPC_IMOKH_WAConnection *)connection;
- (void)removeConnection:(OBJCIPC_IMOKH_WAConnection *)connection;

// queue up the outgoing message
- (void)queueOutgoingMessage:(OBJCIPC_IMOKH_WAMessage *)message forAppWithIdentifier:(NSString *)identifier;

// private methods to setup socket server and connection
- (NSUInteger)_createSocketServer;
- (void)_createPairWithAppSocket:(CFSocketNativeHandle)handle;
- (void)_connectToSpringBoard;

// private methods to handle app activation and deactivation
+ (void)_setupAppActivationListener;
+ (void)_setupAppDeactivationListener;
+ (void)_sendActivationNotificationToAppWithIdentifier:(NSString *)identifier;
+ (void)_sendDeactivationNotificationToAppWithIdentifier:(NSString *)identifier;
+ (void)_appActivationHandler;
+ (void)_appDeactivationHandler;
- (void)_deactivateApp;

@end