//
//  VSeeVideoViewManagerAdapter.h
//  FruitStreet
//
//  Created by Ken on 3/27/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Visit.h"

@class User, VSeeVideoViewManager, WalkInVisit;
@protocol VSeeChatViewControllerProtocol;

@protocol WaitingRoomProtocol <NSObject>

@property (nonatomic, assign) BOOL showCloseBeforeCall;
@property (nonatomic, readonly) WalkInCloseReason exitReason;
@property (nonatomic, readonly) BOOL wasInCall;
@property (nonatomic, readonly) BOOL isInCall;
@property (nonatomic, copy) NSString *waitingRoomTitle;
@property (nonatomic, copy) NSString *videoCallTitle;
@property (nonatomic, assign) BOOL handlingVSeeNotifications;

- (void)notifyProvidersWithVSeeIDs:(NSArray<NSString *> *)vseeIds
                            message:(NSString *)message
                            visitCode:(NSString *)visitCode
                            timeout:(NSTimeInterval)timeout;
- (void)exitWaitingRoom:(WalkInCloseReason)exitReason;
- (void)forceExitWaitingRoom;

@end

typedef BOOL (^WaitingRoomExitHandler)(UIViewController<WaitingRoomProtocol> *waitingRoomController, BOOL forceExit, void (^completion)(BOOL finished));

@interface VSeeVideoViewManagerAdapter : NSObject

@property (nonatomic, assign, readonly, getter=isInWaitingRoom) BOOL inWaitingRoom;
@property (nonatomic, readonly) UIViewController<WaitingRoomProtocol> *activeWaitingRoomController;
@property (nonatomic) Class chatListControllerClass;
@property (nonatomic, copy) void (^onForceExitWaitingRoomCompleted)(void);

+ (instancetype)sharedAdapter;

- (void)showCallNotification:(UIViewController *)callNotificationController;
- (void)showCallNotificationOutSizeWR:(UIViewController *)callNotificationController;
- (void)hideCallNotification:(UIViewController *)callNotificationController;
- (void)showActiveChat;
- (void)showChatList;
- (void)showVideo;
- (void)loadUserSettings;

// exit handler is called whenever current call ends or user explicitly click 'Back' button on navigation bar
// should return a flag indicating whether the current waiting room session has ended
// if no, the wait for call view will continue to show for user
// otherwise, waiting room state will be reset to blank
// when forceExit is true, the waiting room will always exist
// regardless of the return value of exitHandler
- (UIViewController<WaitingRoomProtocol> *)waitingRoomControllerWithWaitForCallViewController:(UIViewController *)waitForCallController
                                                                            autoAcceptVSeeIds:(NSArray *)autoAcceptVSeeIds
                                                                                    meetingId:(NSString *)meetingId
                                                                                  exitHandler:(WaitingRoomExitHandler)exitHandler
                                                                     waitingExitAlertMessage:(NSString *)waitingExitAlertMessage;

- (UIViewController<WaitingRoomProtocol> *)waitingRoomControllerWithWaitForCallViewController:(UIViewController *)waitForCallController
                                                                            autoAcceptVSeeIds:(NSArray *)autoAcceptVSeeIds
                                                                                    meetingId:(NSString *)meetingId
                                                                                  exitHandler:(WaitingRoomExitHandler)exitHandler;


@end
