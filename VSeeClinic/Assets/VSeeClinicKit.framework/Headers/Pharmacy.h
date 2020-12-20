//
//  Pharmacy.h
//  CEP
//
//  Created by Ken on 8/11/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class Address;

@interface Pharmacy : FSModel

@property (nonatomic, strong, readonly) NSString *code;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) Address *address;

@end
