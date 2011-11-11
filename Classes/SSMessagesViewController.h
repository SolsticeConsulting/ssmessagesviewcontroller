//
//  SSMessagesViewController.h
//  Messages
//
//  Created by Sam Soffes on 3/10/10.
//  Copyright 2010-2011 Sam Soffes. All rights reserved.
//
//	This is an abstract class for displaying a UI similar to Apple's SMS application. A subclass should override the
//  messageStyleForRowAtIndexPath: and textForRowAtIndexPath: to customize this class.
//

#import "SSMessageTableViewCell.h"

@class SSTextField;

@interface SSMessagesViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UITextFieldDelegate> {

@private
	CGFloat initY, initHeight;
	UITableView *_tableView;
	UIImageView *_inputBackgroundView;
	SSTextField *_textField;
	UIButton *_sendButton;
	
	UIImage *_leftBackgroundImage;
	UIImage *_rightBackgroundImage;
}

@property (nonatomic, retain, readonly) UITableView *tableView;
@property (nonatomic, retain, readonly) UIImageView *inputBackgroundView;
@property (nonatomic, retain, readonly) SSTextField *textField;
@property (nonatomic, retain, readonly) UIButton *sendButton;
@property (nonatomic, retain) UIImage *leftBackgroundImage;
@property (nonatomic, retain) UIImage *rightBackgroundImage;

- (SSMessageStyle)messageStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)textForRowAtIndexPath:(NSIndexPath *)indexPath;

// This is called before the text field updates its text property so do not depend on the text field for this result.
- (BOOL) shouldEnableSendButton;
// Called to manually update the send button (results in a call to shouldEnableSendButton)
- (void) updateSendButton;

@end
