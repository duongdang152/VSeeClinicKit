//
//  Eprescribe.h
//  VSeeClinicKit
//
//  Created by danghuuduong on 7/1/19.
//  Copyright © 2019 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Eprescribe : NSObject

@property (assign, nonatomic, readonly) BOOL enabled;
@property (assign, nonatomic, readonly) BOOL pharmacyRequired;
@property (assign, nonatomic, readonly) BOOL mailOrderDisable;

- (instancetype _Nonnull)initWithJson:(NSDictionary * _Nullable)json;

@end

NS_ASSUME_NONNULL_END
