//
//  Room.h
//  CEP
//
//  Created by Ken on 7/14/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "FSModel.h"
#import "FSModel+Network.h"

@class User, Intake, FSNestedModelCollection, Room, Consultation;

typedef struct {
    BOOL showProviderList;
} RoomSettings;

typedef NS_ENUM(NSUInteger, RoomQueueDisplayStyle) {
    RoomQueueDisplayStyleNone,
    RoomQueueDisplayStyleMinutes,
    RoomQueueDisplayStyleQueue
};

@interface RoomSlot : FSModel

@property (nonatomic, strong, readonly) NSString *slotId;
@property (nonatomic, strong, readonly) NSDate *start;
@property (nonatomic, strong, readonly) NSDate *end;
@property (nonatomic, strong, readonly) NSNumber *quantityBooked;
@property (nonatomic, strong, readonly) NSNumber *quantityLeft;

@property (nonatomic, strong, readonly) Room *room;

@end

@interface RoomQueueInfo : FSModel

@property (nonatomic, strong, readonly) NSNumber *queueLength;
@property (nonatomic, strong, readonly) NSNumber *queueCapacity;
@property (nonatomic, strong, readonly) NSNumber *waitingLength; // queue count till current user
@property (nonatomic, strong, readonly) NSNumber *averageVisitTime;

- (NSString *)stringWithStyle:(RoomQueueDisplayStyle)style;

@end

@interface ProviderSelectConfig: FSModel

@property (nonatomic, assign, readonly) NSNumber *walkinShow;
@property (nonatomic, assign, readonly) NSNumber *walkinAllowAny;
@property (nonatomic, assign, readonly) NSNumber *scheduleShow;
@property (nonatomic, assign, readonly) NSNumber *scheduleAllowAny;
@property (nonatomic, strong, readonly) NSString *anyOptionText;

@end

@interface Room : FSModel

@property (nonatomic, strong, readonly) NSString *slug;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *domain;
@property (nonatomic, strong, readonly) NSString *code;
@property (nonatomic, strong, readonly) NSString *roomDescription;
@property (nonatomic, strong, readonly) NSString *currency;
@property (nonatomic, strong, readonly) NSNumber *oneTimeUse;
@property (nonatomic, strong, readonly) NSNumber *publicAccess;
@property (nonatomic, strong, readonly) NSString *accountCode;
@property (nonatomic, strong, readonly) NSNumber *guestOnly;
@property (nonatomic, strong, readonly) NSNumber *memberLoginDisabled;
@property (nonatomic, strong, readonly) NSNumber *memberSignUpDisabled;
@property (nonatomic, strong, readonly) NSNumber *guestLoginEnabled;
@property (nonatomic, strong, readonly) NSNumber *guestSignUpEnabled;
@property (nonatomic, strong, readonly) NSNumber *walkinEnabled;
@property (nonatomic, strong, readonly) NSNumber *walkinForceProfileReview;
@property (nonatomic, strong, readonly) NSNumber *scheduleEnabled;
@property (nonatomic, strong, readonly) NSNumber *scheduleForceProfileReview;
@property (nonatomic, strong, readonly) NSNumber *initiateChat;
@property (nonatomic, strong, readonly) RoomQueueInfo *queueInfo; // might be outdated, call getQueueInfoFromNetworkSuccess:failure: to refresh
@property (nonatomic, assign, readonly) RoomSettings settings;
@property (nonatomic, strong, readonly) NSString *startBtnTitle;
@property (nonatomic, strong, readonly) NSString *walkinBtnTitle;
@property (nonatomic, strong, readonly) NSString *scheduleBtnTitle;
@property (nonatomic, strong, readonly) NSNumber *waitingRoomPersistedTillVisitCompleted;
@property (nonatomic, strong, readonly) NSNumber *startAppointmentInterval;
@property (nonatomic, strong, readonly) NSNumber *isClosed;
@property (nonatomic, strong, readonly) NSString *closeMessage;
@property (nonatomic, strong, readonly) NSString *shortName;
@property (nonatomic, strong, readonly) NSString *displayName;
@property (nonatomic, strong, readonly) NSNumber *eConsultEnabled;
@property (nonatomic, strong, readonly) NSString *eConsultBtnTitle;
@property (nonatomic, strong, readonly) NSNumber *scheduleBtnHidden;
@property (nonatomic, strong, readonly) NSNumber *walkinBtnHidden;
@property (nonatomic, strong, readonly) NSNumber *eConsultBtnHidden;
@property (nonatomic, strong, readonly) NSNumber *startBtnHidden;
@property (nonatomic, strong, readonly) NSNumber *recentChatCutOffTime;
@property (nonatomic, strong, readonly) NSNumber *appointmentAllowCancel;
@property (nonatomic, strong, readonly) NSString *logoImageUrl;
@property (nonatomic, strong, readonly) NSNumber *providerListShow;

@property (nonatomic, strong, readonly) NSDictionary *jsonData;

@property (nonatomic, strong, readonly, nullable) ProviderSelectConfig *providerSelectConfig;

@property (nonatomic, strong, readonly) FSNestedModelCollection *providers;
@property (nonatomic, strong, readonly) FSNestedModelCollection *slots;
@property (nonatomic, strong, readonly) FSNestedModelCollection *consultations;

@property (nonatomic, assign, readonly) BOOL hasFreeConsultations;

- (NSURLSessionDataTask *)getQueueInfoFromNetworkSuccess:(void (^)(RoomQueueInfo *queueInfo))successBlock
                                                 failure:(void (^)(NSError *error))failureBlock;

+ (NSURLSessionDataTask *)listFromServerWithParams:(NSDictionary *)params
                                              page:(NSNumber *)page
                                           success:(void (^)(NSArray * _Nonnull))successBlock
                                           failure:(void (^)(NSError * _Nonnull))failureBlock;

- (BOOL)isOneTimeUse;

@end
