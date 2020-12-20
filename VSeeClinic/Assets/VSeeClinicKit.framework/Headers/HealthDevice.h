//
//  MedicalRecord.h
//  CEP
//
//  Created by Ken on 7/28/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class User;

@interface HealthDevice : FSModel

@property (nonatomic, strong, readwrite) User *user;

@property (nonatomic, strong, readonly) NSString *device_id;
@property (nonatomic, strong, readonly) NSString *device_name;
@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong, readonly) NSNumber *last_sync;
@property (nonatomic, strong, readonly) NSNumber *invalid;

- (NSDictionary *)toJsonData;
+ (NSURLSessionDataTask *)fetchAvailableDevicesServerSuccess:(void (^)(NSArray *))successBlock
                                                     failure:(void (^)(NSError *))failureBlock;

@end
