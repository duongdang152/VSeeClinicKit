//
//  Dependant.h
//  VSeeClinicKit
//
//  Created by Ken on 1/9/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import "User.h"

@interface Dependant : User

- (nonnull NSURLSessionDataTask *)loginSuccess:(nullable void (^)(NSDictionary * _Nonnull responseData))successBlock
                                       failure:(nullable void (^)(NSError * _Nonnull))failureBlock;

@end
