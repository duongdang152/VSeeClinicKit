//
//  NSString+Utilities.h
//  CEP
//
//  Created by Ken on 8/4/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Utilities)

+ (nonnull instancetype)stringWithBOOL:(BOOL)boolValue;

- (BOOL)isNumericString; // only works for non-negative integers
- (nonnull NSString *)snakeCaseString;
- (NSDictionary *)parseQueryString;

- (nonnull NSString *)urlStringByAddingPrefix:(nonnull NSString *)prefix; // forward slash '/' at end of prefix or start of self will be properly handled
- (nonnull NSString *)urlStringByAddingSuffix:(nonnull NSString *)suffix; // forward slash '/' at end of self or start of suffix will be properly handled

- (nonnull NSString *)shortenedVersionNumberString;
- (NSComparisonResult)compareVersionNumber:(nonnull NSString *)versionNumber;
+ (NSString *)sha256HashFor:(NSString*)input;

@end
