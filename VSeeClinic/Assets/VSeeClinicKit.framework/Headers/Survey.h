//
//  Survey.h
//  CEP
//
//  Created by Ken on 8/24/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Survey : NSObject

+ (NSURLSessionDataTask *)fetchFormSchemasSuccess:(void (^)(NSDictionary<NSString*, NSDictionary*> *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;
+ (NSDictionary *)formSchemaWithCode:(NSString *)code; // might be nil if not yet fetched

// if retrieved from cache, nil will be returned
+ (NSURLSessionDataTask *)fetchFormSchemaWithCode:(NSString *)code
                                          success:(void (^)(NSDictionary *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)saveSurveyResults:(NSDictionary *)results
                                 surveyCode:(NSString *)code
                                    success:(void (^)())successBlock
                                    failure:(void (^)(NSError *))failureBlock;

@end
