//
//  AlertPopUpConfig.h
//  VSeeClinicKit
//
//  Created by Ken Tran on 19/10/18.
//  Copyright © 2018 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AlertPopUpConfig : NSObject

@property (nonatomic, strong, readonly) NSString* _Nonnull title;
@property (nonatomic, strong, readonly) NSString* _Nonnull message;
@property (nonatomic, strong, readonly) NSString* _Nonnull cancelButtonTitle;
@property (nonatomic, strong, readonly) NSString* _Nullable confirmButtonTitle;

- (instancetype _Nonnull)initWithJson:(NSDictionary * _Nullable)json;

@end
