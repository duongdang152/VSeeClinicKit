//
//  FoodEntry.h
//  FruitStreet
//
//  Created by Cong Bach on 2/10/15.
//  Copyright (c) 2015 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "FSModel.h"

@class Comment, User, FSNestedModelCollection;

typedef enum { kFoodEntryRatingNoRating = 0, kFoodEntryRatingGood = 1, kFoodEntryRatingBad = -1 } FoodEntryRating;

@interface FoodEntry : FSModel

@property (nonatomic, strong, readonly) NSNumber *entryId;
@property (nonatomic, strong, readonly) NSString *imageURL;
@property (nonatomic, strong, readonly) NSString *caption;
@property (nonatomic, strong, readonly) NSDate *date;
@property (nonatomic, strong, readonly) NSDate *created;
@property (nonatomic, strong, readonly) NSDate *modified;
@property (nonatomic, strong, readonly) NSNumber *rating;
@property (nonatomic, strong, readonly) NSString *dateString;
@property (nonatomic, strong, readonly) NSNumber *fruitCount;
@property (nonatomic, strong, readonly) NSNumber *vegCount;
@property (nonatomic, strong, readonly) NSNumber *localImageId;
@property (nonatomic, strong, readonly) NSNumber *isSyncedCommentWithServer;
@property (nonatomic, strong, readonly) NSNumber *isSyncedWithServer;
@property (nonatomic, strong, readonly) NSString *uuid;

@property (nonatomic, strong) NSNumber *isSyncingWithServer;

@property (nonatomic, strong, readonly) User *author;
@property (nonatomic, strong, readonly) FSNestedModelCollection *comments;
@property (nonatomic, strong, readonly) FSNestedModelCollection *notifications;

@end
