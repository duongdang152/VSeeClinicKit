//
//  Attachment.h
//  CEP
//
//  Created by Ken on 7/19/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FSModel.h"
#import "FSModel+Network.h"

typedef NS_ENUM(NSUInteger, AttachmentCategory) {
    AttachmentCategoryIntake,
    AttachmentCategoryUserConsent,
    AttachmentCategoryUserAvatar,
    AttachmentCategoryUserDocument,
    AttachmentCategoryUnknown       // For upload photo without sending meta.category
};

@interface Attachment : FSModel

@property (nonatomic, strong, readonly) NSString *attachmentId;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *ext;
@property (nonatomic, strong, readonly) NSString *fullUrl; // url points to downloadable content file of attachment
@property (nonatomic, strong, readonly) NSString *category;
@property (nonatomic, strong, readonly) NSString *creatorName;
@property (nonatomic, strong, readonly) NSDate *date;

+ (NSURLSessionDataTask *)createOnServerWithData:(NSData *)data
                                        mimeType:(NSString *)mimeType // for use when uploading
                                            name:(NSString *)name
                                         success:(void (^)(id))successBlock
                                         failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)createOnServerWithData:(NSData *)data
                                        mimeType:(NSString *)mimeType // for use when uploading
                                            name:(NSString *)name
                                        category:(AttachmentCategory)category
                                         success:(void (^)(id))successBlock
                                         failure:(void (^)(NSError *))failureBlock;

// will also cache image by fullUrl after creation (using SDWebImage)
+ (NSURLSessionDataTask *)createOnServerWithImage:(UIImage *)image
                                             name:(NSString *)name
                                          success:(void (^)(Attachment *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)createOnServerWithImage:(UIImage *)image
                                             name:(NSString *)name
                                         category:(AttachmentCategory)category
                                          success:(void (^)(Attachment *))successBlock
                                          failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)listFromServerWithCategory:(AttachmentCategory)category
                                             success:(void (^)(NSArray *))successBlock
                                             failure:(void (^)(NSError *))failureBlock;

- (void)downloadFileToTempDirSuccess:(void (^)(NSURL *fileURL))successBlock
                                               failure:(void (^)(NSError *))failureBlock;



@end
