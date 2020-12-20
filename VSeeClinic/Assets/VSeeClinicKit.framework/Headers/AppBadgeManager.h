//
//  AppBadgeManager.h
//  VSeeClinicKit
//
//  Created by Ken on 4/24/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppBadgeManager : NSObject

+ (instancetype)sharedManager;

- (void)updateAppBadgeCount;
- (NSUInteger)calculateBadgeCount;
- (NSUInteger)getUserNotificationBadgeCount;
- (NSUInteger)getVSeeKitBadgeCount;

@end
