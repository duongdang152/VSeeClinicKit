//
//  FSModel+Network.h
//  FruitStreet
//
//  Created by Ken on 6/24/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@protocol AFMultipartFormData;
@class FSModel;

// original url: url passed to this method
// final url: url prefixed by <baseUrl> and <primary_key>, if any
// Note: base_url is this class's resource url (i.e. users, rooms)
// does not contain network manager's base url (https://api.fruitstreet.com/api_v3)
typedef NSString * _Nonnull (^FSModelNetworkUrlResolver)(NSString * _Nonnull originalUrl, NSString * _Nonnull finalUrl);

FSModelNetworkUrlResolver _Nonnull FSModelNetworkUrlResolverOriginal();

@interface FSModel (Network)

+ (nonnull NSString *)networkBaseUrl;
- (nonnull NSString *)networkUrl; // for specific instance; default implementation returns <baseNetworkUrl>/<primaryKey>
// raises NSAssertionError if model doesn't have primary key field

+ (nonnull NSURLSessionDataTask *)listFromServerWithParams:(nullable id)params
                                                   success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

// convenient method with params = nil
+ (nonnull NSURLSessionDataTask *)listFromServerSuccess:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

+ (nonnull NSURLSessionDataTask *)createOnServerWithParams:(nullable id)params
                                 constructingBodyWithBlock:(nullable void(^)(id<AFMultipartFormData> _Nullable formData))constructBodyBlock
                                                   success:(nullable void (^)(id _Nonnull createdInstance))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

// convenient method with constructBodyBlock = nil
+ (nonnull NSURLSessionDataTask *)createOnServerWithParams:(nullable id)params
                                                   success:(nullable void (^)(id _Nonnull createdInstance))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

+ (nonnull NSURLSessionDataTask *)retrieveFromServerWithPrimaryKey:(nonnull id)primaryKey
                                                           success:(nullable void (^)(id _Nonnull retrieveInstance))successBlock
                                                           failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

//- (void)saveToServerSuccess:(void (^)())successBlock
//                    failure:(void (^)(NSError *error))failureBlock;

- (nonnull NSURLSessionDataTask *)retrieveFromServerSuccess:(nullable void (^)())successBlock
                                                    failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)deleteFromServerSuccess:(nullable void (^)())successBlock
                                                  failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (void)deleteFromLocalSuccess:(nullable void (^)())successBlock;

- (nonnull NSURLSessionDataTask *)updateOnServerWithParams:(nullable id)params
                                 constructingBodyWithBlock:(nullable void(^)(id<AFMultipartFormData> _Nullable formData))constructBodyBlock
                                                   success:(nullable void (^)())successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

// convenient method with constructBodyBlock = nil
- (nonnull NSURLSessionDataTask *)updateOnServerWithParams:(nullable id)params
                                                   success:(nullable void (^)())successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

@end
