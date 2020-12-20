//
//  VCNetworkManager+Subclass.h
//  CEP
//
//  Created by Ken on 9/12/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "VCNetworkManager.h"

extern NSString *const KeyChainCurrentRoomPkKey;
extern NSString *const KeyChainCurrentAccountPkKey;
extern NSString *const KeyChainDefaultRoomPkKey;

@interface VCNetworkManager (Subclass)

+ (void)registerSharedNetworkManagerClass:(Class)sharedNetworkManagerClass;

@end
