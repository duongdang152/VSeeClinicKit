//
//  Consultation.h
//  CEP
//
//  Created by Ken on 9/2/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "FSModel.h"

@class Room;

@interface Consultation : FSModel

@property (nonatomic, strong, readonly) NSString *consultationId;
@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong, readonly) NSString *currency;
@property (nonatomic, strong, readonly) NSString *consultationDescription;
@property (nonatomic, strong, readonly) NSNumber *price;
@property (nonatomic, strong, readonly) NSNumber *duration;
@property (nonatomic, assign, readonly) BOOL visibleToPatient;
@property (nonatomic, strong, readonly) Room *room;

@end
