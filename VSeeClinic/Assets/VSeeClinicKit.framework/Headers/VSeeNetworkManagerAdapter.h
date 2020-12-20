//
//  VSeeNetworkManagerAdapter.h
//  CEP
//
//  Created by Ken on 8/10/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Room.h"

@class VSeeNetworkError;
@protocol VSeeNetworkManagerAdapterDelegate;

typedef void (^VSeeNetworkManagerAdapterConfigBlock)();
typedef void (^VSeeNetworkManagerAdapterSuccessBlock)();
typedef void (^VSeeNetworkManagerAdapterFailureBlock)(VSeeNetworkError *error);

typedef struct {
    BOOL userStatusVisibleOutsideWaitingRoom;
    BOOL disablePriorityMessageSend;
    BOOL disableHistory;
    BOOL disableMultiwayChat;
    NSInteger displayedChatCutOffMinutes; // chats that has not been responded by a providers in this timeframe will be hidden in chat list; use -1 to show all chats
    BOOL anonymousChatNotifications;
    BOOL anonymouseCallNotifications;
    RoomQueueDisplayStyle waitingRoomQueueDisplayStyle;
} VSeeLoginSettingsAdapter;

@interface VSeeNetworkError : NSError

@property (nonatomic, copy, readonly) NSString *errorMessage;
@property (nonatomic, assign, readonly, getter=isCancelled) BOOL cancelled;

@end

@interface VSeeNetworkManagerAdapter : NSObject

@property (nonatomic, assign, readonly, getter=isLoggingIn) BOOL loggingIn;
@property (nonatomic, assign, readonly, getter=isUserLoggedIn) BOOL userLoggedIn;
@property (nonatomic, copy, readonly) NSString *loggedInVSeeId; // nil when not fully logged-in
@property (nonatomic, assign, getter=isUserStatusVisible) BOOL userStatusVisible;
@property (nonatomic, assign, readonly) VSeeLoginSettingsAdapter loginSettings;

+ (instancetype)sharedAdapter;

- (void)validateVSeeKitSuccess:(VSeeNetworkManagerAdapterSuccessBlock)successBlock
                       failure:(VSeeNetworkManagerAdapterFailureBlock)failureBlock;

- (void)logInWithVSeeId:(NSString *)vseeid
               password:(NSString *)password
               settings:(VSeeLoginSettingsAdapter)settings
                success:(VSeeNetworkManagerAdapterSuccessBlock)successBlock
                failure:(VSeeNetworkManagerAdapterFailureBlock)failureBlock;

- (void)addLoginHandlersForVSeeId:(NSString *)vseeid
                          success:(VSeeNetworkManagerAdapterSuccessBlock)successBlock
                          failure:(VSeeNetworkManagerAdapterFailureBlock)failureBlock;

- (void)logOutSuccess:(VSeeNetworkManagerAdapterSuccessBlock)successBlock
              failure:(VSeeNetworkManagerAdapterFailureBlock)failureBlock;

- (void)addLogoutHandlersSuccess:(VSeeNetworkManagerAdapterSuccessBlock)successBlock
                         failure:(VSeeNetworkManagerAdapterFailureBlock)failureBlock;

- (void)forceLogout;

- (BOOL)isUserLoggedIn:(NSString *)vseeid;

@end
