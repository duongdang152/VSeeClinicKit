//
//  FormSchema.h
//  CEP
//
//  Created by Ken on 7/28/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *FormSchemaTitleKey;
extern NSString *FormSchemaCodeKey;
extern NSString *FormSchemaSectionsKey;
extern NSString *FormSchemaNextKey;
extern NSString *FormSchemaCancelKey;

extern NSString *FormSchemaSectionCodeKey;
extern NSString *FormSchemaSectionFormKey;
extern NSString *FormSchemaSectionSchemaKey;

extern NSString *FormSchemaSectionCodeUploadFile;
extern NSString *FormSchemaSectionCodeAskUserConsent; // show TOS and do NOT proceed until user gives permission
extern NSString *FormSchemaSectionCodeChooseVisitType; // scheduled/walk-in, see Visit class for all the types
extern NSString *FormSchemaSectionCodePickPharmacy;
extern NSString *FormSchemaSectionCodeIntakeSurvey;
extern NSString *FormSchemaSectionCodePickAppointmentSlot;
extern NSString *FormSchemaSectionCodeSubmitPayment;
extern NSString *FormSchemaSectionCodeSelectConsultation;
extern NSString *FormSchemaSectionCodeMedicalRecordPrefix;


@interface FormSchema : NSObject

@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *code;
@property (nonatomic, strong, readonly) NSArray<NSDictionary *> *sections;
@property (nonatomic, strong, readonly) NSDictionary *nextElement;
@property (nonatomic, strong, readonly) NSDictionary *cancelElement;

+ (instancetype)formSchemaWithJson:(NSDictionary *)json;

- (instancetype)initWithJson:(NSDictionary *)json;
- (NSDictionary *)sectionWithCode:(NSString *)code;

@end

@interface MultiStepFormSchema : NSObject
@property (nonatomic, strong, readonly) NSArray<FormSchema *> *steps;

+ (instancetype)formSchemaWithStepsJsons:(NSArray<NSDictionary *> *)stepJsons;
+ (MultiStepFormSchema* (^)(NSArray *))jsonParser;

- (instancetype)initWithStepJsons:(NSArray<NSDictionary *> *)stepJsons;
- (FormSchema *)stepWithCode:(NSString *)code;

@end
