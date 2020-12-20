//
//  BaseNetworkManager.h
//  CEP
//
//  Created by Ken on 7/11/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

//extern NSString * _Nonnull const NetworkFailureErrorMessageKey __attribute__((deprecated));
//extern NSString * _Nonnull const NetworkFailureStatusCodeKey __attribute__((deprecated));
extern NSString * _Nonnull const NetworkDateFormat;

extern NSString * _Nonnull HttpContentTypePdf;

@class User, NetworkError;
@protocol AFMultipartFormData;

typedef id _Nonnull (^BaseNetworkManagerJsonParserBlock)(id _Nullable responseData);  // response data can be NSDictionary or NSArray
typedef void (^BaseNetworkManagerSuccessBlock)(id _Nullable parsedResult);  // if parser is nil, parsedResult will be responseData
typedef void (^BaseNetworkManagerFailureBlock)(NetworkError * _Nonnull error);

typedef NS_ENUM(NSUInteger, HttpStatusCode) {
    HttpStatusCodeNoStatus = NSNotFound, // request never reached the server
    HttpStatusCodeOK = 200,
    HttpStatusCodeUnauthorized = 401,
    HttpStatusCodeNotFound = 404,
    HttpStatusCodeUnknown = NSUIntegerMax
};

typedef NS_ENUM(NSUInteger, HttpMethod) {
    HttpMethodGET = 0,
    HttpMethodPOST,
    HttpMethodPUT,
    HttpMethodDELETE
};

NSString * _Nonnull NSStringFromHttpMethod(HttpMethod httpMethod);

@interface VSeeClinicKitError : NSError

@end

@interface NetworkError : VSeeClinicKitError

@property (nonatomic, copy, readonly, nonnull) NSString *errorMessage;
@property (nonatomic, assign, readonly) HttpStatusCode statusCode;
@property (nonatomic, assign, readonly) BOOL isSessionExpired;
@property (nonatomic, assign, readonly) BOOL isCancelled;
@property (nonatomic, assign, readonly) BOOL isConnectionLost;
@property (nonatomic, assign, readonly) BOOL isInvalid;
@property (nonatomic, assign, readonly) BOOL isServerError;
@property (nonatomic, assign, readonly) BOOL isSSLError;

+ (NSString *_Nullable)getErrorMessageFromError:(NSError *_Nullable)error;

@end

@interface APIToken : NSObject <NSCopying>

@property (nonatomic, copy, readonly, nonnull) NSString *token;
@property (nonatomic, copy, readonly, nonnull) NSString *refreshToken;
@property (nonatomic, strong, readonly, nonnull) NSDate *expiryDate;
@property (nonatomic, readonly) BOOL hasExpired;

@end

@interface BaseNetworkManager : NSObject

@property (nonatomic, strong, nullable) APIToken *apiToken;
@property (nonatomic, strong, readonly, nullable) User *currentUser;
@property (nonatomic, assign, readonly, getter=isUserLoggedIn) BOOL userLoggedIn;
@property (nonatomic, assign) BOOL ignoreSessionExpiredHandler; // use for guest sign up at verify code step, otherwise session expired will be called when code entered wrong

+ (nonnull NSString *)networkDateFormat; // default to @"yyyy-MM-dd"


- (void)updateEndpoint:(nonnull NSString *)urlString;

// refresh token if token is expired
- (void)refreshToken:(nullable void (^)())successBlock
       previousError:(nullable NSError *)previousError
             failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

- (nonnull NSURLSessionDataTask *)POST:(nullable NSString *)url
                            parameters:(nullable id)parameters
             constructingBodyWithBlock:(nullable void(^)(id<AFMultipartFormData> _Nullable formData))constructBodyBlock
                                parser:(nullable BaseNetworkManagerJsonParserBlock)parser
                               success:(nullable BaseNetworkManagerSuccessBlock)successBlock
                               failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

// convenient method with constructingBodyWithBlock = nil
- (nonnull NSURLSessionDataTask *)POST:(nullable NSString *)url
                            parameters:(nullable id)parameters
                                parser:(nullable BaseNetworkManagerJsonParserBlock)parser
                               success:(nullable BaseNetworkManagerSuccessBlock)successBlock
                               failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

- (nonnull NSURLSessionDataTask *)PUT:(nullable NSString *)url
                           parameters:(nullable id)parameters
                               parser:(nullable BaseNetworkManagerJsonParserBlock)parser
                              success:(nullable BaseNetworkManagerSuccessBlock)successBlock
                              failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

- (nonnull NSURLSessionDataTask *)GET:(nullable NSString *)url
                           parameters:(nullable id)parameters
                               parser:(nullable BaseNetworkManagerJsonParserBlock)parser
                              success:(nullable BaseNetworkManagerSuccessBlock)successBlock
                              failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

- (nonnull NSURLSessionDataTask *)DELETE:(nullable NSString *)url
                              parameters:(nullable id)parameters
                                  parser:(nullable BaseNetworkManagerJsonParserBlock)parser
                                 success:(nullable BaseNetworkManagerSuccessBlock)successBlock
                                 failure:(nullable BaseNetworkManagerFailureBlock)failureBlock;

@end
