//
//  Account.h
//  CEP
//
//  Created by Ken on 7/25/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

extern NSString *AccountFormSchemasSignUpKey;
extern NSString *AccountFormSchemasSignUpVerifyEmailKey;
extern NSString *AccountFormSchemasSignUpUpdateProfileKey;
extern NSString *AccountFormSchemasBasicProfileKey;
extern NSString *AccountFormSchemasExtendedProfileKey;
extern NSString *AccountFormSchemasGuestSignInKey;
extern NSString *AccountFormSchemasVisitCompleteProfileKey;
extern NSString *AccountFormSchemasIntakeKey;
extern NSString *AccountFormSchemasIntakeChooseVisitTypeKey;
extern NSString *AccountFormSchemasIntakeChooseCalendarSlotTypeKey;
extern NSString *AccountFormSchemasIntakePromptUserConsentKey;
extern NSString *AccountFormSchemasPostIntakeKey;
extern NSString *AccountFormSchemasCancelIntakeKey;
extern NSString *AccountFormSchemasPostCallKey;
extern NSString *AccountFormSchemasCancelCallKey;
extern NSString *AccountFormSchemasConsultationTypeKey;
extern NSString *AccountFormSchemasHomeKey;
extern NSString *AccountFormSchemasWaitingRoomKey;
extern NSString *AccountFormSchemasGuestSignUpKey;
extern NSString *AccountFormSchemasPaymentKey;
extern NSString *AccountFormSchemasDependantSignUp;
extern NSString *AccountFormSchemasProviderSelect;
extern NSString *AccountFormSchemasEConsult;

extern NSString *AccountPageVerifyAccountKey;

@class MultiStepFormSchema, Attachment, HealthDataConfig, EMRConfig, FormSchema, EligibilityConfig, Eprescribe, ClinicDirectoryConfig;

@interface Account : FSModel

@property (nonatomic, strong, readonly) NSString *code;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *waitingRoomTitle;
@property (nonatomic, strong, readonly) NSString *emergencyMessage;
@property (nonatomic, strong, readonly) NSString *logoImageUrl;
@property (nonatomic, strong, readonly) NSString *minRequirementsVersion;
@property (nonatomic, strong, readonly) NSNumber *maxWaitTime;
@property (nonatomic, strong, readonly) NSNumber *appUpdateRequired;
@property (nonatomic, strong, readonly) NSString *supportText;
@property (nonatomic, strong, readonly) NSString *supportPhone;
@property (nonatomic, strong, readonly) NSNumber *paymentEnabled;
@property (nonatomic, strong, readonly) NSNumber *paymentMethodRequired;
@property (nonatomic, strong, readonly) NSNumber *paymentSelectionOptional;
@property (nonatomic, strong, readonly) NSNumber *paymentSkipDuringSchedule;
@property (nonatomic, strong, readonly) NSNumber *cardInfoOptionnal;
@property (nonatomic, strong, readonly) NSNumber *dependantEnabled;
@property (nonatomic, strong, readonly) NSNumber *vseePriorityMessageSendEnabled;
@property (nonatomic, strong, readonly) NSNumber *vseeSystemMessageEnabled;
@property (nonatomic, strong, readonly) EMRConfig *emrConfig;
@property (nonatomic, strong, readonly) NSNumber *healthSourcesEnabled;
@property (nonatomic, strong, readonly, nullable) NSNumber *pharmacyEnabled;
@property (nonatomic, strong, readonly, nullable) NSNumber *pharmacyRequired;
@property (nonatomic, strong, readonly) HealthDataConfig *healthDataConfig;
@property (nonatomic, strong, readonly) NSNumber *facebookLoginEnabled;
@property (nonatomic, strong, readonly) NSNumber *googleLoginEnabled;
@property (nonatomic, strong, readonly) NSNumber *appleLoginEnabled;
@property (nonatomic, strong, readonly) NSNumber *deferredVerification;
@property (nonatomic, strong, readonly) NSNumber *deferredVerificationAllowWalkIn;
@property (nonatomic, strong, readonly) NSNumber *deferredVerificationAllowSchedule;
@property (nonatomic, strong, readonly) NSNumber *consultationDurationIsHidden;
@property (nonatomic, strong, readonly) NSNumber *consultationAmountIsHidden;
@property (nonatomic, strong, readonly) NSString *consultationAmountFreeText;
@property (nonatomic, strong, readonly) NSNumber *idleTimeOut;
@property (nonatomic, strong, readonly) NSNumber *idleWarningPeriod;
@property (nonatomic, strong, readonly) NSNumber *internationalAddressEnabled;
@property (nonatomic, strong, readonly) EligibilityConfig *eligibilityConfig;
@property (nonatomic, strong, readonly) Eprescribe *eprescribeConfig;
@property (nonatomic, strong, readonly) NSString *accountDescription;
@property (nonatomic, strong, readonly) NSNumber *visitSummaryChatEnabled;
@property (nonatomic, strong, readonly) NSString *customEndpoint;
@property (nonatomic, strong, readonly) NSNumber *pollingCurrentVisitInterval;
@property (nonatomic, strong, readonly) NSNumber *pollingVisitDetailInterval;
@property (nonatomic, strong, readonly) NSNumber *pollingKeepAliveInterval;
@property (nonatomic, strong, readonly, nullable) ClinicDirectoryConfig *clinicDirectoryConfig;
@property (nonatomic, strong, readonly, nullable) NSString *clinicThemeCode;

@property (nonatomic, strong, readonly) NSDictionary *jsonData;

@property (nonatomic, assign) BOOL helpScreenAvailable;

// if retrieved from cache, nil will be returned
- (NSURLSessionDataTask *)fetchFormSchemasWithKey:(NSString *)formSchemasKey
                                          success:(void (^)(MultiStepFormSchema *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;
// if retrieved from cache, nil will be returned
- (NSURLSessionDataTask *)fetchTermOfServiceUrlSuccess:(void (^)(NSString *termOfServiceUrl))successBlock
                                               failure:(void (^)(NSError *))failureBlock;
// if retrieved from cache, nil will be returned
- (NSURLSessionDataTask *)fetchConsentFileUrlSuccess:(void (^)(NSString *consentFileUrl))successBlock
                                             failure:(void (^)(NSError *))failureBlock;
// if retrieved from cache, nil will be returned
- (NSURLSessionDataTask *)fetchHomeTabSuccess:(void (^)(NSArray<NSDictionary *> *tabtems))successBlock
                                      failure:(void (^)(NSError *))failureBlock;

- (BOOL)hasSchemaForKey:(NSString *)formSchemasKey;
- (MultiStepFormSchema *)formSchemasWithKey:(NSString *)key;

- (FormSchema *)formSchemaForPage:(NSString *)page;

// Only use when account is loaded
- (FormSchema *)formSchemaForBasicProfile;
- (NSArray<FormSchema *> *)formSchemasForExtendedProfile;
- (BOOL)oneClickStyle;

@end
