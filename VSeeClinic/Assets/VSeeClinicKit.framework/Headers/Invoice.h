//
//  Invoice.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 15/12/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InvoiceItem : NSObject

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *itemDescription;
@property (nonatomic, strong, readonly) NSNumber *quantity;
@property (nonatomic, strong, readonly) NSNumber *unitPrice;
@property (nonatomic, strong, readonly) NSNumber *total;

- (instancetype)initWithJson:(NSDictionary *)json;

@end

@interface Invoice : NSObject

@property (nonatomic, strong, readonly) NSString *currency;
@property (nonatomic, strong, readonly) NSNumber *amountDue;
@property (nonatomic, strong, readonly) NSArray<InvoiceItem *> *items;

- (instancetype)initWithJson:(NSDictionary *)json;

@end

