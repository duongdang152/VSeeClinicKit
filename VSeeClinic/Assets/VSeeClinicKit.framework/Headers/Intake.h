//
//  Intake.h
//  FruitStreet
//
//  Created by Ken on 3/24/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "FSModel.h"
#import "FSModel+Network.h"

@class Room, Consultation;

typedef NS_ENUM(NSUInteger, IntakeType) {
    IntakeTypeWalkin = 1,
    IntakeTypeScheduled = 2,
};


@interface Intake : FSModel

@property (nonatomic, strong, readonly) NSString *intakeId;
@property (nonatomic, strong, readonly) NSNumber *type;
@property (nonatomic, strong, readonly) NSNumber *bookedByProvider;
@property (nonatomic, strong, readonly) NSString *reasonForVisit;
@property (nonatomic, strong, readonly) NSString *location;
@property (nonatomic, strong, readonly) NSString *phoneNumber;

@property (nonatomic, strong, readonly) NSDictionary *jsonData;

@property (nonatomic, strong, readonly) Consultation *consultation;

+ (NSURLSessionDataTask *)createOnServerWithType:(IntakeType)type
                                  reasonForVisit:(NSString *)reasonForVisit
                                            room:(Room *)room
                                imageAttachments:(NSArray *)imageAttachments
                                         success:(void (^)(Intake *))successBlock
                                         failure:(void (^)(NSError *))failureBlock;

@end
