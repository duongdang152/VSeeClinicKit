//
//  DataManager.h
//  FruitStreet
//
//  Created by Cong Bach on 2/10/15.
//  Copyright (c) 2015 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VCDataManager : NSObject

+ (instancetype)sharedManager;

- (void)setUpDatabase;
- (void)resetDatabase;

@end
