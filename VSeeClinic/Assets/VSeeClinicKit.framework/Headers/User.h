//
//  User.h
//  FruitStreet
//
//  Created by Cong Bach on 2/6/15.
//  Copyright (c) 2015 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "FSModel.h"
#import "FSNestedModelCollection.h"

@class FoodEntry, Comment, Room, Visit, MedicalRecord, MultiStepFormSchema, Pharmacy, Goal, EMRUserInfo, ActiveMinuteSyncInfo, Attachment;
@class FSNestedModelCollection, UserNotificationCollection, UserHealthDataCollection;

typedef NS_ENUM(NSUInteger, UserType) {
    UserTypePatient = 200,
    UserTypeProvider = 400,
    UserTypeGuest = 600,
    UserTypeOther
};

typedef enum {
    kUserGenderMale = 1,
    kUserGenderFemale = 2
} UserGender;

typedef NS_ENUM(NSUInteger, UserStatus) {
    UserStatusInactive = 10,
    UserStatusActive = 20
};

@interface UserMedicalRecordCollection : FSNestedModelCollection

- (nonnull NSURLSessionDataTask *)updateOnServer:(nonnull NSString *)medicalRecordName
                                            code:(nonnull NSString *)medicalRecordCode
                                            data:(nullable id)jsonMedicalRecordData
                                      initParams:(nullable NSMutableDictionary*)initParams
                                         success:(nullable void (^)())successBlock
                                         failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

@end

@interface UserHealthDeviceCollection : FSNestedModelCollection

- (nonnull NSURLSessionDataTask *)addAppleHealthDevice:(NSString * _Nullable) deviceId
                                            deviceName:(NSString * _Nullable) deviceName
                                            deviceType:(NSString * _Nullable) deviceType
                                               success:(void (^_Nullable)(NSDictionary *_Nullable))successBlock
                                               failure:(void (^_Nullable)(NSError *_Nullable))failureBlock;

- (nonnull NSURLSessionDataTask *)removeDevice:(NSString * _Nullable) deviceId
                                    deviceType:(NSString * _Nullable) deviceType
                                       success:(void (^_Nullable)(NSDictionary *_Nullable))successBlock
                                       failure:(void (^_Nullable)(NSError *_Nullable))failureBlock;

- (nonnull NSURLSessionDataTask *)getConnectBrowserUrl:(NSString * _Nullable) deviceType
                                           redirectUrl:(NSString * _Nullable) redirectUrl
                                               success:(void (^_Nullable)(NSDictionary *_Nullable))successBlock
                                               failure:(void (^_Nullable)(NSError *_Nullable))failureBlock;

@end

@interface UserVisitCollection : FSNestedModelCollection

- (nonnull NSArray *)listUpcoming;
- (nonnull NSArray *)listHistory;

- (nonnull NSURLSessionDataTask *)listUpcomingFromServerWithParams:(nullable NSDictionary *)params
                                                           success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                           failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;
// convenient method with params = nil
- (nonnull NSURLSessionDataTask *)listUpcomingFromServerSuccess:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                        failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)listHistoryFromServerWithParams:(nullable NSDictionary *)params
                                                          success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                          failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;
// convenient method with params = nil
- (nonnull NSURLSessionDataTask *)listHistoryFromServerSuccess:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                       failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (nonnull NSPredicate *)upcomingPredicate;
- (nonnull NSPredicate *)historyPredicate;


@end

@interface UserFoodEntryCollection : FSNestedModelCollection

// FIXME: server should have unified way for paginations that takes count, offset, pk, etc. as parameters
- (nonnull NSURLSessionDataTask *)listNextFromServer:(NSUInteger)count
                                      fromPrimaryKey:(nullable id)primaryKey
                                             success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                             failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

@end

@interface User : FSModel

@property (nonatomic, strong, readonly, nonnull) NSNumber *userid;
@property (nonatomic, strong, readonly, nonnull) NSString *username;
@property (nonatomic, strong, readonly, nullable) NSNumber *userType;
@property (nonatomic, strong, readonly, nonnull) NSString *vseeid;
@property (nonatomic, strong, readonly, nonnull) NSString *vseePassword;
@property (nonatomic, strong, readonly, nullable) NSString *name;
@property (nonatomic, strong, readonly, nullable) NSString *firstName;
@property (nonatomic, strong, readonly, nullable) NSString *lastName;
@property (nonatomic, strong, readonly, nullable) NSString *email;
@property (nonatomic, strong, readonly, nullable) NSString *dateOfBirth;
@property (nonatomic, strong, readonly, nullable) NSString *gender;
@property (nonatomic, strong, readonly, nullable) NSString *imageURL;
@property (nonatomic, strong, readonly, nullable) NSNumber *status;
@property (nonatomic, strong, readonly, nullable) NSNumber *active;
@property (nonatomic, strong, readwrite, nullable) NSNumber *notificationBadgeCount;
@property (nonatomic, strong, readonly, nullable) NSNumber *profileCompleteStatus;
@property (nonatomic, strong, readonly, nullable) NSNumber *emailVerified;
@property (nonatomic, strong, readonly, nullable) NSString *timezone;

// FIXME: address should be in separate object/property, however server returns json
// format not matching Address model json, making serializing non-trivial
@property (nonatomic, strong, readonly, nullable) NSString *streetAddress;
@property (nonatomic, strong, readonly, nullable) NSString *state;
@property (nonatomic, strong, readonly, nullable) NSString *city;
@property (nonatomic, strong, readonly, nullable) NSString *zipCode;
@property (nonatomic, strong, readonly, nullable) NSString *phoneNumber;

@property (nonatomic, strong, readonly, nullable) NSString *pcpName;
@property (nonatomic, strong, readonly, nullable) NSString *pcpPhoneNumber;

@property (nonatomic, strong, readonly, nullable) Pharmacy *defaultPharmacy; // might be outdated, call retrieveDefaultPharmacySuccess:failure: to for current value

@property (nonatomic, strong, readonly, nullable) ActiveMinuteSyncInfo *activeMinuteSyncInfo;

@property (nonatomic, strong, readonly, nonnull) UserFoodEntryCollection *foodEntries;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *comments;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *providers;
@property (nonatomic, strong, readonly, nonnull) UserVisitCollection *visits;
@property (nonatomic, strong, readonly, nonnull) UserMedicalRecordCollection *medicalRecords;
@property (nonatomic, strong, readonly, nonnull) UserHealthDeviceCollection *healthDevices;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *pharmacies;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *prescriptions;
@property (nonatomic, strong, readonly, nonnull) UserNotificationCollection *notifications;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *goals;
@property (nonatomic, strong, readonly, nonnull) FSNestedModelCollection *dependants;
@property (nonatomic, strong, readonly, nonnull) UserHealthDataCollection *healthData;
@property (nonatomic, strong, readonly, nonnull) EMRUserInfo *emrUserInfo;
@property (nonatomic, strong, readonly) NSArray<Attachment *> * _Nullable idCards;
@property (nonatomic, strong, readonly) NSArray<Attachment *> * _Nullable insuranceCards;
@property (nonatomic, strong, readonly) NSArray<Attachment *> * _Nullable driversLicenseInsurance;

@property (nonatomic, strong, readonly, nullable) NSArray *userAccounts;

@property (nonatomic, strong, readonly, nonnull) NSArray<Room *> *associatedRooms;

@property (nonatomic, assign) BOOL isProfileCompleted;
@property (nonatomic, strong, readonly) NSDictionary * jsonData;

+ (nullable instancetype)loggedInUser;
+ (nullable instancetype)userWithVSeeId:(NSString * _Nonnull)vseeid;

+ (nonnull NSURLSessionDataTask *)getProfileSchemaFromNetworkSuccess:(nullable void (^)(MultiStepFormSchema * _Nonnull))successBlock
                                                             failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (nonnull NSURLSessionDataTask *)retrieveDefaultPharmacySuccess:(nullable void (^)(Pharmacy * _Nonnull))successBlock
                                                         failure:(nullable void (^)(NSError * _Nonnull))failureBlock;
- (nonnull NSURLSessionDataTask *)saveDefaultPharmacy:(nonnull Pharmacy *)pharmacy
                                              success:(nullable void (^)())successBlock
                                              failure:(nullable void (^)(NSError * _Nonnull))failureBlock;
- (nonnull NSURLSessionDataTask *)deleteSavedPharmacy:(nonnull Pharmacy *)pharmacy
                                              success:(nullable void (^)())successBlock
                                              failure:(nullable void (^)(NSError *))failureBlock;
- (void)clearSavedVseePassword;
- (nonnull NSURLSessionDataTask *)fetchUserAccountsSuccess:(nullable void (^)(NSArray * _Nonnull))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)syncedActiveMinuteSuccess:(NSDate *_Nonnull)startDate
                          endDate:(NSDate *_Nonnull)endDate
                activeMinuteValue:(double)activeMinuteValue;

- (void)updateTimeZone;

@end

@interface GuestUser : User

@end
