//
//  NSNumber+Utilities.h
//  FruitStreet
//
//  Created by Ken on 5/19/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNumber (Utilities)

+ (NSNumber *)numberWithNSNumberOrIntegerString:(id)object;
+ (NSNumber *)numberWithNSNumberOrDoubleString:(id)object;
+ (NSNumber *)numberWithNSNumberOrDecimalString:(id)object;
+ (NSNumber *)numberWithNSNumberOrBooleanString:(id)object;
- (NSString *)toStringWithDecimalFractionDigit:(NSInteger)fractionDigit;
- (NSString *)toStringWithCurrencyCode:(NSString *)currencyCode displaySymbol:(BOOL)displaySymbol;

@end
