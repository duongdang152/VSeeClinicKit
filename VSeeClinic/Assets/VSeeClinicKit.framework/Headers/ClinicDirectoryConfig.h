//
//  ClinicDirectoryConfig.h
//  VSeeClinicKit
//
//  Created by dang huu duong on 8/18/20.
//  Copyright © 2020 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ClinicDirectoryConfig : NSObject

@property (assign, nonatomic, readonly) BOOL enabled;
@property (strong, nonatomic, readonly) NSString* _Nullable clinicDescription;
@property (assign, nonatomic, readonly) BOOL showSearchRoom;
@property (assign, nonatomic, readonly) BOOL publicAccessClinic;


- (instancetype _Nonnull)initWithJson:(NSDictionary * _Nullable)json;


@end

NS_ASSUME_NONNULL_END
