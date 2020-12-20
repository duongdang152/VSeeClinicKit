//
//  EligibilityConfig.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 19/10/18.
//  Copyright © 2018 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlertPopUpConfig.h"

@interface EligibilityConfig : NSObject

@property (assign, nonatomic, readonly) BOOL enabled;
@property (strong, nonatomic, readonly) NSString* _Nullable fallbackAccountCode;
@property (strong, nonatomic, readonly) AlertPopUpConfig* _Nullable fallbackExistAlertConfig;
@property (strong, nonatomic, readonly) AlertPopUpConfig* _Nullable fallbackNotExistAlertConfig;

- (instancetype _Nonnull)initWithJson:(NSDictionary * _Nullable)json;

@end
