//
//  VCNetworkManager.h
//  FS
//
//  Created by Ken on 9/9/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "BaseNetworkManager+Subclass.h"
#import "VSeeNetworkManagerAdapter.h"
@import SDWebImage;

extern NSString * _Nonnull const VCNetworkManagerErrorDomain;
extern const NSInteger VCNetworkManagerRestoreLoginFailureNoExistingSessionErrorCode;
extern const NSInteger VCNetworkManagerLoginFailureProviderNotAllowedErrorCode;
extern const NSInteger VCNetworkManagerLoginFailureUnknownUserTypeErrorCode;

extern const NSString * _Nonnull AccountCodeHeaderField;
extern const NSString * _Nonnull RoomCodeHeaderField;

extern const NSString * _Nullable VCNetworkManagerLogoutReasonVSeeKitLoginFailed;
extern const NSString * _Nullable VCNetworkManagerLogoutReasonRefreshTokenFailed;

@class User, Dependant, Account, Room, VCNetworkManager, Provider, Intake, Invoice;
@protocol VCNetworkManagerDelegate;

@interface VCNetworkManager : BaseNetworkManager

@property (nonatomic, assign, nullable) id<VCNetworkManagerDelegate> delegate;
@property (nonatomic, strong, nullable) Account *currentAccount;
@property (nonatomic, strong, nullable) Room *defaultRoom;
@property (nonatomic, strong, nullable) Room *currentRoom;
@property (nonatomic, assign, readonly) BOOL autoManagesVSeeLogin; // default to NO
@property (nonatomic, assign, readonly) SDWebImageOptions sdImageDownloadOptions;
@property (nonatomic, copy, nullable) NSString *pushNotificationToken;

@property (nonatomic, assign, readonly, getter=isMemberLoggedIn) BOOL memberLoggedIn;
@property (nonatomic, assign, readonly, getter=isGuestLoggedIn) BOOL guestLoggedIn;
@property (nonatomic, assign, readonly) BOOL wasGuestLoggedIn;

@property (nonatomic, strong, readonly, nullable) User *mainUser; // mainly for dependant login session, otherwise will be the same as current user
@property (nonatomic, assign, readonly, getter=isDependantLogin) BOOL dependantLogin;


+ (nonnull instancetype)sharedNetworkManager;


// will send an activation code to email
- (void)startSignUpWithParams:(nonnull NSDictionary *)params
                      success:(nullable void (^)())successBlock
                      failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// activate and log in as user if successful
- (void)activateEmail:(nonnull NSString *)email
     verificationCode:(nonnull NSString *)verificationCode
              success:(nullable void (^)())successBlock
              failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)completeSignUpWithParams:(nonnull NSDictionary *)params
                         success:(nullable void (^)())successBlock
                         failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// only user type patient is allowed, otherwise failure block will be called
- (void)loginWithUsernameOrEmail:(nonnull NSString *)usernameOrEmail
                        password:(nonnull NSString *)password
                         success:(nullable void (^)())successBlock
                         failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)loginWithAccessToken:(nonnull NSString *)accessToken
                      expiry:(nullable NSDate *)expiry
                     success:(nullable void (^)())successBlock
                     failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)loginWithAccessToken:(nonnull NSString *)accessToken
                      expiry:(nullable NSDate *)expiry
                refreshToken:(nullable NSString *)refreshToken
           autoSavingSession:(BOOL)autoSavingSession
                     success:(nullable void (^)())successBlock
                     failure:(nullable void (^)(NSError * _Nonnull))failureBlock;


- (void)facebookLoginWithToken:(nonnull NSString *)token
                       success:(nullable void(^)())successBlock
                       failure:(nullable void(^)(NSError * _Nonnull))failureBlock;

- (void)googleLoginWithToken:(nonnull NSString *)token
                     success:(nullable void(^)())successBlock
                     failure:(nullable void(^)(NSError * _Nonnull))failureBlock;

- (void)appleLoginWithToken:(nonnull NSString *)token
             userIdentifier:(nonnull NSString *)userIdentifier
                  givenName:(nonnull NSString *)givenName
                 familyName:(nonnull NSString *)familyName
                      email:(nonnull NSString *)email
                    success:(nullable void(^)())successBlock
                    failure:(nullable void(^)(NSError * _Nonnull))failureBlock;

// refresh token if token is expired
- (void)refreshToken:(void (^ _Nullable)())successBlock
             failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

- (BOOL)checkHasStoredLoginSession;

// raise NSAssertionError if there's already a session in place, i.e. log out first
// if there's no session on disk, failure block will be called with
// error code = VCNetworkManagerNoLoginSessionErrorCode
// error domain = VCNetworkManagerRestoreLoginFailureNoExistingSessionErrorCode
- (void)restoreLoginSessionSuccess:(nullable void (^)())successBlock
                           failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

// must be called on main account, otherwise NSAssertionError will be thrown
// will also log out of all dependant accounts
- (void)logoutSuccess:(nullable void (^)())successBlock
              failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// raise NSAssertionError if user is not logged in
// will check cache token for fast login if possible
// can be called while logged in as another dependant
- (void)loginAsDependant:(nonnull Dependant *)dependant
                 success:(nullable void (^)())successBlock
                 failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// will raise NSAssertionError if called on main account
- (void)logoutAsDependantSuccess:(nullable void (^)())successBlock
                         failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)restoreMainUserLoginSuccess:(nullable void (^)())successBlock
                            failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// will raise NSAssertionError if given user is not currently logged in
- (void)performNetworkRequestsAsUser:(nonnull User *)user
                             handler:(nonnull void (^)())networkRequestsBlock;

// clear local credentials even if network call might fail
// must be called on main account, otherwise NSAssertionError will be thrown
// will also log out of all dependant accounts
- (void)forceLogout;
- (void)forceLogout:(NSString *)reason;
- (void)forceLogoutAppleSignInRevoked;

- (void)registerForPushNotificationsSuccess:(nullable void (^)())successBlock
                                    failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;
- (void)unregisterFromPushNotificationsSuccess:(nullable void (^)())successBlock
                                       failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (void)resetPasswordForEmail:(nonnull NSString *)email
                      success:(nullable void (^)())successBlock
                      failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)guestLoginWithParams:(nonnull NSDictionary *)params
                     success:(nullable void (^)())successBlock
                     failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)keepUserAliveWithHeartBeat:(int)heartBeat
                           success:(nullable void (^)())successBlock
                           failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)processPromoCode:(nullable NSString *)code
                  intake:(nullable Intake *)intake
                 success:(nullable void(^)(Invoice * _Nullable))successBlock
                 failure:(nullable void (^)(NSError * _Nullable))failureBlock;

- (void)setStripePublishableKeyWithRoom:(nullable Room *)room
                               provider:(nullable Provider *)provider
                                success:(nullable void(^)())successBlock
                                failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)checkUserActiveSuccess:(nullable void(^)(BOOL))successBlock
                       failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)loginVSeeSuccess:(nullable void(^)())successBlock
                 failure:(nullable void (^)(VSeeNetworkError * _Nonnull))failureBlock;

- (void)logoutVSeeSuccess:(nullable void (^)())successBlock
                  failure:(nullable void (^)(VSeeNetworkError * _Nonnull))failureBlock;

- (void)setUpLanguage;

- (void)resendEmailVerificationSuccess:(nullable void (^)())successBlock
                               failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)retrieveCurrentUserSuccess:(nullable void (^)())successBlock
                           failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)setHTTPHeader:(nonnull NSString *)header withValue:(nonnull NSString *)value;

- (void)loadCurrentUserAssignedAccountSuccess:(nullable void (^)())successBlock
                                      failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)sendSupportTicketWithParams:(nullable NSDictionary *)params
                            success:(nullable void (^)())successBlock
                            failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

// Use by CEP
- (void)checkEligibilityWithParams:(nullable NSDictionary *)params
                           success:(nullable void (^)(NSString * _Nonnull))successBlock
                           failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

- (void)setTemporaryRoomCodeHeader:(nullable NSString *)roomCode;
- (void)revertTemporaryRoomCodeHeader;

@end


@protocol VCNetworkManagerDelegate <NSObject>

// called after all users are logged out (forcefully)
- (void)networkManagerSessionDidExpire:(nonnull VCNetworkManager *)networkManager requestUrl:(nullable NSString *)requestUrl;

@optional
// called after all users are logged out (forcefully)
- (void)vseeLoginDidFail:(nonnull VCNetworkManager *)networkManager error:(nonnull VSeeNetworkError *)error;

@end
