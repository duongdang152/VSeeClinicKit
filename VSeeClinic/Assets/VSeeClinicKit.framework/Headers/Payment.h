//
//  Payment.h
//  FruitStreet
//
//  Created by Ken on 3/21/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "FSModel.h"

@class Visit;

@interface Payment : FSModel

@property (nonatomic, strong, readonly) NSNumber *amount;
@property (nonatomic, strong, readonly) NSNumber *duration;
@property (nonatomic, strong, readonly) NSNumber *charged;
@property (nonatomic, strong, readonly) NSString *paymentDescription;
@property (nonatomic, strong, readonly) Visit *visit;

@end
