//
//  ClinicSettings.h
//  VSeeClinicKit
//
//  Created by Ken on 6/6/17.
//  Copyright © 2017 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VSeeNetworkManagerAdapter.h"

@interface ClinicSettings : NSObject

@property (class, nonatomic, copy, readonly, nonnull) ClinicSettings *settings;

@property (nonatomic, copy, readonly, nonnull) NSString *apiKey;
@property (nonatomic, copy, readonly, nonnull) NSString *networkBaseUrl;
@property (nonatomic, copy, readonly, nonnull) NSString *vseekitAPIKey;
@property (nonatomic, copy, readonly, nonnull) NSString *vseekitSecretKey;
@property (nonatomic, assign) VSeeLoginSettingsAdapter vseeLoginSettings;

+ (void)registerSettingsClass:(nonnull Class)settingsClass;

// Use by CEP
@property (nonatomic, assign, readonly) BOOL useServerAccountCode;
@property (nonatomic, assign, readonly) BOOL waitingTimeStyleMinutes;

@end
