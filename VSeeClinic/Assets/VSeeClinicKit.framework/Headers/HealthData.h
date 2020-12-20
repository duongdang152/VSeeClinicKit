//
//  HealthData.h
//  VSeeClinicKit
//
//  Created by Ken on 3/8/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"
#import "FSNestedModelCollection.h"

@class User, NetworkError, HealthDevice;

typedef NS_ENUM(NSUInteger, HealthDataType) {
    HealthDataTypeWeight,
    HealthDataTypeSteps,
    HealthDataTypeSleep,
    HealthDataTypeCaloriesBurned,
    HealthDataTypeTemperature,
    HealthDataTypePulse,
    HealthDataTypeSystolicBloodPressure,
    HealthDataTypeDiastolicBloodPressure,
    HealthDataTypeBloodPressure,
    HealthDataTypeBloodGlucose,
    HealthDataTypeActiveMinutes,
    HealthDataTypeOxygenSaturation // SpO2
};

NSString *_Nonnull NSStringFromHealthDataType(HealthDataType type);
NSString *_Nonnull NSEnglishStringFromHealthDataType(HealthDataType type);

@interface NSString (DurationString)

+ (nonnull NSString *)durationStringForSeconds:(NSUInteger)seconds;

@end

@interface HealthData : FSModel

@property (nonatomic, strong, readonly, nonnull) User *user;

@property (nonatomic, strong, readonly, nonnull) NSDate *date;
@property (nonatomic, strong, readonly, nullable) NSNumber *weight;
@property (nonatomic, strong, readonly, nullable) NSString *weightUnit;
@property (nonatomic, strong, readonly, nullable) NSNumber *steps;
@property (nonatomic, strong, readonly, nullable) NSNumber *sleep;
@property (nonatomic, strong, readonly, nullable) NSNumber *caloriesBurned;
@property (nonatomic, strong, readonly, nullable) NSNumber *temperature;
@property (nonatomic, strong, readonly, nullable) NSString *temperatureUnit;
@property (nonatomic, strong, readonly, nullable) NSNumber *pulse;
@property (nonatomic, strong, readonly, nullable) NSString *pulseUnit;
@property (nonatomic, strong, readonly, nullable) NSNumber *systolicBloodPressure;
@property (nonatomic, strong, readonly, nullable) NSNumber *diastolicBloodPressure;
@property (nonatomic, strong, readonly, nullable) NSString *bloodPressureUnit;
@property (nonatomic, strong, readonly, nullable) NSNumber *bloodGlucose;
@property (nonatomic, strong, readonly, nullable) NSString *bloodGlucoseUnit;
@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutesFairly;
@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutesLightly;
@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutesVery;
@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutes;
@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutesManual;
@property (nonatomic, strong, readonly, nullable) NSNumber *oxygenSaturation; // SpO2

@property (nonatomic, strong, readonly, nullable) NSNumber *activeMinutesFitbit;

+ (nullable instancetype)healthDataForDate:(nonnull NSDate *)date
                                   forUser:(nullable User *)user;

+ (NSString *)defaultUnitForHealthType:(HealthDataType)type;

- (BOOL)hasDataForType:(HealthDataType)type;
- (nullable NSNumber *)dataForType:(HealthDataType)type; // does not work with HealthDataTypeBloodPressure, use stringDataForType: instead
- (nullable NSString *)stringDataForType:(HealthDataType)type; // does not work with HealthDataTypeBloodPressure
//+ (nullable NSString *)stringForData:(nullable NSNumber *)data type:(HealthDataType)type;
- (nullable NSString *)unitForType:(HealthDataType)type; // return nil if type has no unit

@end

@interface UserHealthDataCollection : FSNestedModelCollection

- (nonnull NSURLSessionDataTask *)retrieveFromServerForDate:(nonnull NSDate *)date
                                                    forUser:(nullable User *)user
                                                    success:(nullable void (^)(HealthData * _Nonnull healthData))successBlock
                                                    failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)retrieveFromServerFromDate:(nonnull NSDate *)fromDate
                                                      toDate:(nonnull NSDate *)toDate
                                                     success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                     failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)retrieveAllStatisticFromServerFromDate:(nonnull NSDate *)fromDate
                                                                 toDate:(nonnull NSDate *)toDate
                                                            urlResolver:(FSModelNetworkUrlResolver _Nullable )urlResolver
                                                                success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                             failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)logHealthData:(nonnull NSNumber *)data
                                           type:(HealthDataType)type
                                           unit:(nonnull NSString *)unit
                                           date:(nonnull NSDate *)date
                                        success:(nullable void (^)())successBlock
                                        failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)logBloodSystolic:(nonnull NSNumber *)systolic
                                         diastolic:(nonnull NSNumber *)diastolic
                                              unit:(nonnull NSString *)unit
                                              type:(HealthDataType)type
                                              date:(nonnull NSDate *)date
                                           success:(nullable void (^)())successBlock
                                           failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)logActiveMinutes:(NSInteger)activeMinutes
                                              date:(nonnull NSDate *)date
                                           success:(nullable void (^)())successBlock
                                           failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;


//- (nonnull NSURLSessionDataTask *)syncListDeviceHealthData:(NSArray *_Nonnull)data
//                                                   success:(nullable void (^)())successBlock
//                                                   failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)syncDeviceActiveMinutes:(double)activeMinutes
                                     activeMinuteFieldKey:(NSString *_Nonnull)activeMinuteFieldKey
                                             healthDevice:(HealthDevice *_Nonnull)healthDevice
                                                     date:(nonnull NSDate *)date
                                                  success:(nullable void (^)())successBlock
                                                  failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)syncListDeviceActiveMinutes:(NSArray *_Nonnull)activeMinutes
                                                      success:(nullable void (^)())successBlock
                                                      failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)syncListDeviceStepsCounts:(NSArray *_Nonnull)stepsCounts
                                                    success:(nullable void (^)())successBlock
                                                    failure:(nullable void (^)(NetworkError * _Nonnull error))failureBlock;


@end
