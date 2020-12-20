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

@interface ActiveMinuteSyncInfo : FSModel

@property (nonatomic, strong, readonly) NSNumber *endDate;
@property (nonatomic, strong, readonly) NSNumber *startDate;
@property (nonatomic, strong, readonly) NSNumber *value;

@end
