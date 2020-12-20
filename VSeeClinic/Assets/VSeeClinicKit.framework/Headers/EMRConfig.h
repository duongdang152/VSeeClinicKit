//
//  EMRConfig.h
//  VSeeClinicKit
//
//  Created by dat on 5/8/18.
//  Copyright © 2018 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EMRConfig : NSObject

@property (assign, nonatomic, readonly) BOOL enabled;
@property (assign, nonatomic, readonly) BOOL pmhxRequired;
@property (assign, nonatomic, readonly) BOOL allergiesRequired;
@property (assign, nonatomic, readonly) BOOL medicationsRequired;

- (instancetype _Nonnull)initWithJson:(NSDictionary * _Nullable)json;
+ (NSString * _Nonnull)getDataNotReportedTitle:(NSString * _Nonnull)code;
+ (NSString * _Nonnull)keyToCode:(NSString * _Nonnull)key;
+ (NSString * _Nonnull)getSectionTitle:(NSString * _Nonnull)key;

@end
