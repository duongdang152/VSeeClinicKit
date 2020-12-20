//
//  Notification.h
//  VSeeClinicKit
//
//  Created by Ken on 11/1/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"
#import "FSNestedModelCollection.h"

@class User;

@interface UserNotification : FSModel

@property (nonatomic, strong, readonly) NSNumber *notificationId;
@property (nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) NSDate *date;
@property (nonatomic, strong, readonly) NSNumber *unixMillis;
@property (nonatomic, assign, readonly) NSNumber *read;
@property (nonatomic, strong, readonly) NSString *imageUrl;

@property (nonatomic, strong, readonly) User *user;

- (NSURLSessionDataTask *)markAsReadOnServerSuccess:(void (^)())successBlock
                                            failure:(void (^)(NSError *))failureBlock;

@end

@interface FoodNotification : UserNotification

@property (nonatomic, strong, readonly) NSNumber *foodId;

@end

@interface UserNotificationCollection : FSNestedModelCollection

- (NSURLSessionDataTask *)retrieveBadgeCountFromServerSuccess:(void (^)(NSInteger))successBlock
                                                      failure:(void (^)(NSError *))failureBlock;

- (NSURLSessionDataTask *)resetBadgeCountOnServerSuccess:(void (^)())successBlock
                                                 failure:(void (^)(NSError *))failureBlock;

@end
