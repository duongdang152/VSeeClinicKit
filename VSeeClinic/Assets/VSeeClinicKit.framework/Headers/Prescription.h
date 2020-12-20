//
//  Prescription.h
//  CEP
//
//  Created by Ken on 9/8/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class User;

@interface Prescription : FSModel

@property (strong, nonatomic, readonly) NSString *drug;
@property (strong, nonatomic, readonly) NSString *directions;
@property (strong, nonatomic, readonly) NSString *refills;
@property (strong, nonatomic, readonly) NSString *daysSupply;
@property (strong, nonatomic, readonly) NSString *prescriptionDate;
@property (strong, nonatomic, readonly) NSString *prescriberName;

@property (strong, nonatomic, readonly) User *user;

@end
