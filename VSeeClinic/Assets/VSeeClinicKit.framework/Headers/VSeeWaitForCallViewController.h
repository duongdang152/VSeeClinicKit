//
//  VSeeWaitForCallViewController.h
//  FruitStreet
//
//  Created by Ken on 3/28/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Room.h"

@interface VSeeWaitForCallViewController : UIViewController

@property (nonatomic, strong, readonly) NSString *message;
@property (nonatomic, strong, readonly) NSString *emergencyMessage;
@property (nonatomic, assign, readonly) RoomQueueDisplayStyle queueDisplayStyle;

- (instancetype)initWithMessage:(NSString *)message
              queueDisplayStyle:(RoomQueueDisplayStyle)queueDisplayStyle
               emergencyMessage:(NSString *)emergencyMessage;

@end
