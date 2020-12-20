//
//  VSeeChatListCell.h
//  CEP
//
//  Created by Ken on 9/2/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VSeeChatListCell : UITableViewCell

@property (nonatomic, weak) IBOutlet UIView *bubbleView;
@property (nonatomic, weak) IBOutlet UIImageView *avatarImageView;
@property (nonatomic, weak) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak) IBOutlet UILabel *messageLabel;
@property (nonatomic, weak) IBOutlet UILabel *timeLabel;
@property (weak, nonatomic) IBOutlet UILabel *unreadCountLabel;
@property (weak, nonatomic) IBOutlet UIView *unreadCountView;

@end
