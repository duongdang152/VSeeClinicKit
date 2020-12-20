//
//  Provider.h
//  CEP
//
//  Created by Ken on 8/7/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "User.h"

@interface Provider : User

@property (nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) NSString *suffix;
@property (nonatomic, strong, readonly) NSString *shortBio;
@property (nonatomic, strong, readonly) NSString *languages;
@property (nonatomic, strong, readonly) NSString *specialities;
@property (nonatomic, strong, readonly) NSString *certifications;
@property (nonatomic, strong, readonly) NSString *eduMedical; // FIXME: check w server team and rename properly
@property (nonatomic, strong, readonly) NSString *eduInternship; // FIXME: check w server team and rename properly
@property (nonatomic, strong, readonly) NSString *eduResidency; // FIXME: check w server team and rename properly
@property (nonatomic, strong, readonly) NSString *eduTraining;
@property (nonatomic, strong, readonly) NSString *licensedStates;
@property (nonatomic, strong, readonly) NSString *servicedStates;
@property (nonatomic, strong, readonly) NSString *professionalInterests;
@property (nonatomic, strong, readonly) NSString *personalInterests;
@property (nonatomic, strong, readonly) NSString *specialties;
@property (nonatomic, strong, readonly) NSString *specialties_data;
@property (nonatomic, strong, readonly) NSNumber *online;
@property (nonatomic, strong, readonly) NSNumber *hidden;
@property (nonatomic, strong, readonly) NSNumber *notificationEnabled;
@property (nonatomic, strong, readonly) NSNumber *autoAcceptVSeeCalls;
@property (nonatomic, strong, readonly) NSNumber *forceHidden;
@property (nonatomic, strong, readonly) NSString *fullBio;
@property (nonatomic, strong, readonly) NSNumber *disableSelection;

@property (nonatomic, strong, readonly) NSString *displayName;

@end
