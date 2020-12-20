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

extern NSString *MedicalRecordNameAllergy;
extern NSString *MedicalRecordNameCondition;
extern NSString *MedicalRecordNameMedication;
extern NSString *MedicalRecordNameSurgery;
extern NSString *MedicalRecordNameFamilyHistory;
extern NSString *MedicalRecordNameSocialHistory;
extern NSString *MedicalRecordNameHealthHabit;

extern NSString *EMRCodeNameAllergy;
extern NSString *EMRCodeNameCondition;
extern NSString *EMRCodeNameMedication;
extern NSString *EMRCodeNameSurgery;
extern NSString *EMRCodeNameFamilyHistory;
extern NSString *EMRCodeNameSocialHistory;
extern NSString *EMRCodeNameHealthHabit;

@interface MedicalRecord : FSModel

@property (nonatomic, strong, readwrite) User *user;

+ (Class)subclassForName:(NSString *)name;
+ (NSDictionary *)formSchemas; // might be nil if not yet fetched from server

// if retrieved from cache, nill will be returned
+ (NSURLSessionDataTask *)fetchSchemasFromServerSuccess:(void (^)(NSDictionary *))successBlock // dictionary of name -> section
                                                failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)searchServerQuery:(NSString *)query // nil/blank query will return all results
                      forMedicalRecordNamed:(NSString *)name
                                    success:(void (^)(NSArray *))successBlock
                                    failure:(void (^)(NSError *))failureBlock;

@end

@interface MedicalRecordAllergy : MedicalRecord

@property (nonatomic, strong, readonly) NSString *substance;

@end

@interface MedicalRecordCondition : MedicalRecord

@property (nonatomic, strong, readonly) NSString *details;

@end

@interface MedicalRecordMedication : MedicalRecord

@property (nonatomic, strong, readonly) NSString *name;

@end

@interface MedicalRecordSurgery : MedicalRecord

@property (nonatomic, strong, readonly) NSString *procedure;

@end

@interface MedicalRecordFamilyHistory : MedicalRecord

@property (nonatomic, strong, readonly) NSString *condition;
@property (nonatomic, strong, readonly) NSArray *relations; // Mother/Father

@end

@interface MedicalRecordSocialHistory : MedicalRecord

@property (nonatomic, strong, readonly) NSString *maritalStatus;
@property (nonatomic, strong, readonly) NSString *highestEducation;
@property (nonatomic, strong, readonly) NSString *occupation;
@property (nonatomic, strong, readonly) NSNumber *kidsCount;

@end

@interface MedicalRecordHealthHabit : MedicalRecord

@property (nonatomic, strong, readonly) NSString *smoking;
@property (nonatomic, strong, readonly) NSString *alcohol;
@property (nonatomic, strong, readonly) NSString *drugs;
@property (nonatomic, strong, readonly) NSString *exercise;

@end
