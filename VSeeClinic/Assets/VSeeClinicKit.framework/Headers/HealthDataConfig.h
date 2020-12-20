//
//  HealthDataConfig.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 5/10/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HealthData.h"

@interface HealthDataConfig : NSObject


@property (assign, nonatomic, readonly) BOOL weightEnabled;
@property (assign, nonatomic, readonly) BOOL weightManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL activeMinutesEnabled;
@property (assign, nonatomic, readonly) BOOL activeMinutesManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL bloodGlucoseEnabled;
@property (assign, nonatomic, readonly) BOOL bloodGlucoseManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL bloodPressureEnabled;
@property (assign, nonatomic, readonly) BOOL bloodPressureManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL heartRateEnabled;
@property (assign, nonatomic, readonly) BOOL heartRateManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL oxygenSaturationEnabled;
@property (assign, nonatomic, readonly) BOOL oxygenSaturationManualLoginEnabled;
@property (assign, nonatomic, readonly) BOOL temperatureEnabled;
@property (assign, nonatomic, readonly) BOOL temperatureManualLoginEnabled;

// non manual logging supported
@property (assign, nonatomic, readonly) BOOL stepsEnabled;
@property (assign, nonatomic, readonly) BOOL caloriesEnabled;
@property (assign, nonatomic, readonly) BOOL sleepEnabled;


- (instancetype)initWithJson:(NSDictionary *)json;

- (BOOL)manualLoggingEnableFor:(HealthDataType)type;

@end
