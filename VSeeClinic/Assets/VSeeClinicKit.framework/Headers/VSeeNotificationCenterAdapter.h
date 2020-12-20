//
//  VSeeNotificationCenterAdapter.h
//  FruitStreet
//
//  Created by Ken on 3/21/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol VSeeNotificationCenterDelegate;
@protocol VSeeChatViewManagerDelegate;
@class VSeeChatViewManager;

extern NSString *VSeeIncomingCallNotificationName;
extern NSString *VSeeIncomingChatNotificationName;

@interface VSeeNotificationCenterAdapter : NSObject

@property (nonatomic, weak) id<VSeeNotificationCenterDelegate> delegate; // delegate methods from VSeeNotificationCenter will be forwarded to this object

@property (nonatomic, weak) id<VSeeChatViewManagerDelegate> chatDelegate; // delegate methods from VSeeNotificationCenter will be forwarded to this object

+ (instancetype)sharedAdapter; // singleton instance

- (void)retrieveUserImageForNotification:(UIViewController *)notificationController completion:(void (^)(UIImage *))completionHandler;
- (void)showChatList;
- (void)showChatViewController:(VSeeChatViewManager *)manager vc:(UIViewController*)vc animation:(BOOL)animation;
- (void)showChatViewController:(VSeeChatViewManager *)manager;
- (NSString *)vseeidForNotification:(UIViewController *)notificationController;

// VSeeNotificationCenter will not deliver imcoming chat events so we need to obserincomging chat by our self.
- (void)startObserverIncomingChats;
- (void)addProvidersOfRoomToAutoAccept;
- (void)addProvidersOfUserToAutoAccept;
@end
