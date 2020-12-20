//
//  PaymentMethod.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 14/11/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class Provider;

@interface PaymentMethod : FSModel

@property (nonatomic, strong, readonly) NSString *cardId;
@property (nonatomic, strong, readonly) NSString *brand;
@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *last4Digits;
@property (nonatomic, strong, readonly) NSString *expMonth;
@property (nonatomic, strong, readonly) NSString *expYear;
@property (nonatomic, strong, readonly) NSNumber *isDefault;

+ (NSURLSessionDataTask *)createOnServerWithToken:(NSString *)token
                                             type:(NSString *)type
                                         provider:(Provider *)provider
                                          success:(void (^)(PaymentMethod *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;

@end
