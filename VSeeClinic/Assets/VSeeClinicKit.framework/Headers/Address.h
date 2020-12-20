//
//  Address.h
//  CEP
//
//  Created by Ken on 8/7/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@interface Address : FSModel

@property (nonatomic, strong, readonly) NSString *line1;
@property (nonatomic, strong, readonly) NSString *line2;
@property (nonatomic, strong, readonly) NSString *city;
@property (nonatomic, strong, readonly) NSString *state;
@property (nonatomic, strong, readonly) NSString *country;
@property (nonatomic, strong, readonly) NSNumber *zipCode;
@property (nonatomic, strong, readonly) NSString *phoneNumer;
@property (nonatomic, strong, readonly) NSString *faxNumber;
@property (nonatomic, strong, readonly) NSNumber *latitude;
@property (nonatomic, strong, readonly) NSNumber *longitude;

@end
