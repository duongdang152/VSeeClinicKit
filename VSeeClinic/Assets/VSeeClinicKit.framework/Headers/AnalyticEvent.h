//
//  AnalyticEvent.h
//  VSeeClinicKit
//
//  Created by dang huu duong on 11/18/20.
//  Copyright © 2020 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface AnalyticEvent : FSModel

@property (strong, nonatomic, readonly, nonnull) NSString *code;
@property (strong, nonatomic, readonly, nonnull) NSString *type;
@property (strong, nonatomic, readonly, nonnull) NSString *name;
@property (strong, nonatomic, readonly, nullable) NSDictionary *parametters;
@property (strong, nonatomic, readonly, nullable) NSDate *timestamp;
@property (strong, nonatomic, readonly, nonnull) NSString *sessionID;
@property (strong, nonatomic, readonly, nullable) NSString *userID;
@property (strong, nonatomic, readonly, nullable) NSString *accountCode;
@property (strong, nonatomic, readonly, nullable) NSString *roomCode;


-(instancetype _Nonnull)initWithCode:(NSString *)code
                                 type:(NSString *)type
                               params:(NSDictionary * _Nullable)parametters
                            sessionID:(NSString *)sessionID
                               userID: (NSString * _Nullable)userID
                          accountCode:(NSString * _Nullable)accountCode
                             roomCode:(NSString * _Nullable)roomCode ;

+(int)count;

-(NSDictionary<NSString *, id> *)toDictionary;




@end

NS_ASSUME_NONNULL_END
