//
//  GoalMilestone.h
//  VSeeClinicKit
//
//  Created by Ken on 12/14/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

@class Goal;

@interface GoalMilestone : FSModel

@property (nonatomic, strong, readonly) NSString *milestoneId;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSDate *dueDate;
@property (nonatomic, strong, readonly) NSDate *startDate;
@property (nonatomic, strong, readonly) NSDate *completionDate;
@property (nonatomic, strong, readonly) NSNumber *done;

@property (nonatomic, strong, readonly) Goal *goal;

- (NSURLSessionDataTask *)updateOnServerCompleted:(BOOL)completed success:(void (^)())successBlock failure:(void (^)(NSError *))failureBlock;

@end
