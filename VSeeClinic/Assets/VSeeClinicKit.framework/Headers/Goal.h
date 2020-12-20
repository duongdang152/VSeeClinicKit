//
//  Goal.h
//  VSeeClinicKit
//
//  Created by Ken on 12/14/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class FSNestedModelCollection, User;

@interface Goal : FSModel

@property (nonatomic, strong, readonly) NSString *goalId;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSDate *creationDate;
@property (nonatomic, strong, readonly) NSDate *dueDate;
@property (nonatomic, strong, readonly) NSDate *completionDate;
@property (nonatomic, strong, readonly) NSNumber *done;
@property (nonatomic, strong, readonly) NSNumber *order;

@property (nonatomic, strong, readonly) User *user;
@property (nonatomic, strong, readonly) FSNestedModelCollection *milestones;

- (NSURLSessionDataTask *)updateOnServerCompleted:(BOOL)completed success:(void (^)())successBlock failure:(void (^)(NSError *))failureBlock;

@end
