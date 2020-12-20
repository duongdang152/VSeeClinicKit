//
//  Visit.h
//  FruitStreet
//
//  Created by Cong Bach on 3/21/16.
//  Copyright (c) 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "FSModel.h"
#import "FSModel+Network.h"

@class PostVisitInfo, FSNestedModelCollection;

typedef NS_ENUM(NSUInteger, VisitStatus) {
    VisitStatusPending = 10,
    VisitStatusConfirmed = 20,
    VisitStatusInProgress = 25,
    VisitStatusCompleted = 30,
    VisitStatusCancelled = 40,
    VisitStatusRefunded = 50
};

typedef NS_ENUM(NSUInteger, WalkInCloseReason) {
    WalkInCloseReasonUserCancelled,
    WalkInCloseReasonUserEndedCall,
    WalkInCloseReasonCallEnded, // not by user
    WalkInCloseReasonUnknown
};

typedef NS_ENUM(NSUInteger, VisitType) {
    VisitTypeWalkIn = 1,
    VisitTypeScheduled = 2,
    VisitTypeEConsult = 3,
    VisitTypeInvitedGuest = 10
};

typedef NS_ENUM(NSUInteger, SubVisitType) {
    SubVisitTypeInPersion = 1,
    SubVisitTypePhone = 2,
    SubVisitTypeVideo = 3,
};

@class User, Provider, Payment, Intake, Walkin, MeetingInfo, Room;

@interface Visit : FSModel

@property (nonatomic, strong, readonly) NSNumber *visitId;
@property (nonatomic, strong, readonly) NSNumber *visitType;
@property (nonatomic, strong, readonly) NSNumber *subType;
@property (nonatomic, strong, readonly) NSNumber *roomCode;
@property (nonatomic, strong, readonly) NSDate *startDate;
@property (nonatomic, strong, readonly) NSDate *endDate;
@property (nonatomic, strong, readwrite) NSNumber *status;
@property (nonatomic, strong, readonly) NSNumber *isGroup;
@property (nonatomic, strong, readwrite) NSNumber *upcoming;
@property (nonatomic, strong, readonly) NSString *visitDescription;
@property (nonatomic, strong, readonly) NSString *statusString;
@property (nonatomic, strong, readonly) NSString *code;
@property (nonatomic, strong, readonly) NSNumber *expiry;

@property (nonatomic, strong, readonly) User *creator;
@property (nullable, nonatomic, strong, readonly) Provider *provider;
@property (nonatomic, strong, readonly) User *patient;
@property (nonatomic, strong, readonly) Payment *payment;
@property (nonatomic, strong, readonly) Intake *intake;
@property (nonatomic, strong, readonly) PostVisitInfo *postVisitInfo;
@property (nonatomic, strong, readonly) FSNestedModelCollection *prescriptions;
@property (nonatomic, strong, readonly, nullable) Room *room;

@property (nonatomic, strong, readonly) MeetingInfo *meetingInfo;
@property (nonatomic, assign, readonly) BOOL isMeetingVisit;

@property (nonatomic, assign, readonly) BOOL isFree;
@property (nonatomic, assign, readonly) BOOL isUnpaid;
@property (nonatomic, assign, readonly) BOOL isActive;
@property (nonatomic, assign, readonly) BOOL isCompleted;
@property (nonatomic, assign, readonly) BOOL isCancelled;
@property (nonatomic, assign, readonly) BOOL isMissed;
@property (nonatomic, assign, readonly) BOOL isHistory;

- (NSURLSessionDataTask *)updateCallConnectStatus:(NSArray *)vseeids
                                          success:(nullable void (^)())successBlock
                                          failure:(nullable void (^)(NSError *_Nullable))failureBlock;

- (NSURLSessionDataTask *)closeVisitOnServerWithReason:(WalkInCloseReason)reason
                                               success:(void (^)())successBlock
                                               failure:(void (^)(NSError *))failureBlock;

@end

@interface ScheduledVisit : Visit

@property (nonatomic, assign, readonly) BOOL hasWalkin;
@property (nonatomic, strong, readonly) NSNumber *activeWalkInPk;

+ (NSURLSessionDataTask *)createOnServerWithIntake:(Intake *)intake
                                      withProvider:(Provider *)provider // optional
                                             start:(NSDate *)startDate
                                               end:(NSDate *)endDate
                                           success:(void (^)(Visit *))successBlock
                                           failure:(void (^)(NSError *))failureBlock;

- (NSURLSessionDataTask *)cancelOnServerSuccess:(void (^)())successBlock
                                        failure:(void (^)(NSError *))failureBlock;

- (NSURLSessionDataTask *)createWalkInOnServerSuccess:(void (^)(Visit *))successBlock
                                              failure:(void (^)(NSError *))failureBlock;

- (NSURLSessionDataTask *)closeWalkInOnServerForReason:(WalkInCloseReason)reason
                                               success:(void (^)())successBlock
                                               failure:(void (^)(NSError *))failureBlock;

@end

@interface WalkInVisit : Visit

+ (NSURLSessionDataTask *)createOnServerWithIntake:(Intake *)intake
                                           success:(void (^)(Visit *))successBlock
                                           failure:(void (^)(NSError *))failureBlock;

- (NSURLSessionDataTask *)closeOnServerForReason:(WalkInCloseReason)reason
                                         success:(void (^)())successBlock
                                         failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)retrieveInProgressVisitSuccess:(void (^)(Visit *))successBlock
                                                 failure:(void (^)(NSError *))failureBlock;
@end

@interface PostVisitInfo : FSModel

@property (nonatomic, strong, readonly) NSString *physicalExam;
@property (nonatomic, strong, readonly) NSString *assessmentPlan;
@property (nonatomic, strong, readonly) NSString *diagnosis;
@property (nonatomic, strong, readonly) NSString *patientInstructions;
@property (nonatomic, strong, readonly) NSString *disposition;

@property (nonatomic, strong, readonly) Visit *visit;

@property (nonatomic, strong, readonly) FSNestedModelCollection *attachments;

@end


@interface MeetingInfo : NSObject

@property (nonatomic, strong, readonly) NSString *meetingId;
@property (nonatomic, strong, readonly) NSString *conferencePin;
@property (nonatomic, strong, readonly) NSArray *phoneNumbers;
@property (nonatomic, assign, readonly) BOOL disabled;

- (instancetype)initWithJson:(NSDictionary *)json;

@end

@interface EConsult: Visit

+ (NSURLSessionDataTask *)createOnServerWithIntake:(Intake * _Nonnull)intake
                                          provider:(Provider * _Nullable)provider
                                           success:(void (^_Nullable)(Visit *_Nullable))successBlock
                                           failure:(void (^_Nonnull)(NSError *_Nonnull))failureBlock;

@end
