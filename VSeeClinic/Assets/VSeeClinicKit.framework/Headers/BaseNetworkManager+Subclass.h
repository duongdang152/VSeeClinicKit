//
//  BaseNetworkManager+Subclass.h
//  CEP
//
//  Created by Ken on 7/15/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "BaseNetworkManager.h"

@class AFHTTPSessionManager, FSModel, VSeeNetworkError;

@interface NetworkError ()

+ (instancetype)networkErrorWithVSeeNetworkError:(VSeeNetworkError *)vseeNetworkError;

@end

@interface APIToken ()

- (instancetype)initWithToken:(NSString *)token
                   expiryDate:(NSDate *)expiryDate
                 refreshToken:(NSString *)refreshToken;

@end


@interface BaseNetworkManager ()

@property (nonatomic, strong, readonly) AFHTTPSessionManager *afhttpSessionManager;
@property (nonatomic, strong, readwrite) User *currentUser;
@property (nonatomic, assign, readonly, getter=isRestoringSavedSession) BOOL restoringSavedSession;
@property (nonatomic, assign) BOOL autoSavingSession;

+ (NSString *)networkResponseDataKey; // default to @"data"
+ (NSString *)apiTokenHeaderField; // default to @"X-ApiToken"
+ (BOOL)allowInvalidSSLCertificates; // FIXME: should be refactored into a NetworkConfiguration object
+ (NSString *)userAgent;

- (instancetype)initWithBaseURL:(NSString *)baseURL;

- (void)clearCurrentSession;

// perform automatically when isUserLoggedIn changes from NO to YES, except when restoring current session
- (void)saveCurrentSessionToDisk;
- (void)saveCurrentTokenToDisk;
// perform automatically when isUserLoggedIn changes from YES to NO
- (void)clearSavedSessionFromDisk;
- (BOOL)checkHasStoredSessionOnDisk;
- (BOOL)restoreSavedSessionFromDisk;
// subclass should override this instead of restoreSavedSessionFromDisk so that this class know whether a session is being restored
// (& disable session saving while restoring)
- (BOOL)performRestoreSavedSession;

- (void)saveModelPrimaryKeyToDisk:(FSModel *)model uniqueName:(NSString *)name;
- (id)restoreModelFromDiskWithPrimaryKeyName:(NSString *)name ofClass:(Class)fsModelSubclass;

- (void)cancelPendingRequests;
- (BOOL)shouldCancelTaskWhenLogOut:(NSURLSessionTask *)task;
- (void)clearHTTPCookies;

- (void)sessionExpired:(NSString *)requestUrl;

@end
