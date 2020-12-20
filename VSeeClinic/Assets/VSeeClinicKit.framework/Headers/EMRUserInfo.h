//
//  HealthDataConfig.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 5/10/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EMRUserInfo : NSObject

@property (assign, nonatomic, readonly) BOOL dataNotReportedForConditions;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForSurgeries;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForFamilyHistory;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForMedications;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForAllergies;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForSocialHistory;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForHealthHabits;
@property (assign, nonatomic, readonly) BOOL dataNotReportedForFamilyConditions;

- (void)updateDataNotReportedWithCode:(NSString *)code jsonData:(id)jsonData;
- (void)updateDataNotReportedWithDataKey:(NSString *)key jsonData:(id)jsonData;
- (BOOL)dataNotReported:(NSString *)code;

@end
