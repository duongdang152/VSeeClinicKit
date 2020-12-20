//
//  Comment.h
//  FruitStreet
//
//  Created by Cong Bach on 2/6/15.
//  Copyright (c) 2015 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "FSModel.h"

@class FoodEntry, User;

@interface Comment : FSModel

@property (nonatomic, strong, readonly) NSNumber *commentId;
@property (nonatomic, strong, readonly) NSNumber *commentLocalId;
@property (nonatomic, strong, readonly) NSNumber *isSyncedWithServer;
@property (nonatomic, strong, readonly) NSString *content;
@property (nonatomic, strong, readonly) NSDate *created;
@property (nonatomic, strong, readonly) FoodEntry *foodEntry;
@property (nonatomic, strong, readonly) User *author;

@end
