//
//  FSModel+NetworkSubclass.h
//  CEP
//
//  Created by Ken on 7/21/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "FSModel+Network.h"
#import "BaseNetworkManager.h"

@class VCNetworkManager, FSNestedModelCollection;

typedef NS_ENUM(NSUInteger, FSModelNetworkOperation) {
    FSModelNetworkOperationList = 1 << 0,
    FSModelNetworkOperationCreate = 1 << 1,
    FSModelNetworkOperationRetrieve = 1 << 2,
    FSModelNetworkOperationUpdate = 1 << 3,
    FSModelNetworkOperationDelete = 1 << 4,
    
    FSModelNetworkOperationNone = 0,
    FSModelNetworkOperationAll = ~0,
    FSModelNetworkOperationReadOnly = FSModelNetworkOperationList | FSModelNetworkOperationRetrieve
};

NSString* NSStringFromFSModelNetworkOperation(FSModelNetworkOperation networkOperation);

@interface FSModelNetwork : NSObject

@property (nonatomic, weak, readonly) FSModel *model;
@property (nonatomic, copy, readonly) NSString *urlPrefix;

- (instancetype)initWithModel:(FSModel *)model;
- (instancetype)initWithUrlPrefix:(NSString *)urlPrefix;

- (NSURLSessionDataTask *)GET:(NSString *)url
 parameters:(id)parameters
     parser:(id (^)(id responseData))parser
urlResolver:(FSModelNetworkUrlResolver)urlResolver
    success:(void (^)(id parsedResult))success
    failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)POST:(NSString *)url
  parameters:(id)parameters
constructingBodyWithBlock:(void(^)(id<AFMultipartFormData> formData))constructBodyBlock
      parser:(id (^)(id responseData))parser
 urlResolver:(FSModelNetworkUrlResolver)urlResolver
     success:(void (^)(id parsedResult))success
     failure:(void (^)(NSError *))failure;

// convenient method with constructBodyBlock = nil
- (NSURLSessionDataTask *)POST:(NSString *)url
  parameters:(id)parameters
      parser:(id (^)(id responseData))parser
 urlResolver:(FSModelNetworkUrlResolver)urlResolver
     success:(void (^)(id parsedResult))success
     failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)PUT:(NSString *)url
 parameters:(id)parameters
     parser:(id (^)(id responseData))parser
urlResolver:(FSModelNetworkUrlResolver)urlResolver
    success:(void (^)(id parsedResult))success
    failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)DELETE:(NSString *)url
    parameters:(id)parameters
        parser:(id (^)(id responseData))parser
   urlResolver:(FSModelNetworkUrlResolver)urlResolver
       success:(void (^)(id parsedResult))success
       failure:(void (^)(NSError *))failure;


// Convenient methods with urlResolver simply returns finalUrl
- (NSURLSessionDataTask *)GET:(NSString *)url
 parameters:(id)parameters
     parser:(id (^)(id responseData))parser
    success:(void (^)(id parsedResult))success
    failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)POST:(NSString *)url
  parameters:(id)parameters
constructingBodyWithBlock:(void(^)(id<AFMultipartFormData> formData))constructBodyBlock
      parser:(id (^)(id responseData))parser
     success:(void (^)(id parsedResult))success
     failure:(void (^)(NSError *))failure;

// convenient method with constructBodyBlock = nil
- (NSURLSessionDataTask *)POST:(NSString *)url
  parameters:(id)parameters
      parser:(id (^)(id responseData))parser
     success:(void (^)(id parsedResult))success
     failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)PUT:(NSString *)url
 parameters:(id)parameters
     parser:(id (^)(id responseData))parser
    success:(void (^)(id parsedResult))success
    failure:(void (^)(NSError *))failure;

- (NSURLSessionDataTask *)DELETE:(NSString *)url
    parameters:(id)parameters
        parser:(id (^)(id responseData))parser
       success:(void (^)(id parsedResult))success
       failure:(void (^)(NSError *))failure;

@end

@interface FSModel (Network_Subclass)

@property (nonatomic, strong, readonly) FSModelNetwork *classNetwork; // convenient method for [[self class] network]
@property (nonatomic, strong, readonly) FSModelNetwork *network; // url prefix will be self.networkUrl; for instance related network activity (retrieve/update/delete)

@property (nonatomic, strong, readwrite) FSNestedModelCollection *nestedModelCollection; // if support retrieve/update, then retrieve/update url will be formed
                                                                                         // via nestedModelCollection

+ (FSModelNetwork *)network; // url prefix will be <baseNetworkUrl>; for non-instance related network activity (list/create)

+ (FSModelNetworkOperation)supportedNetworkOperations; // default return operations: list, create, retrieve, update, delete

+ (void (^)(id))addAutoSaveToSuccessBlock:(void (^)(id))successBlock; // automatically save the instance to persistent store in success block

+ (NSURLSessionDataTask *)listFromServerWithParams:(id)params
                     urlResolver:(FSModelNetworkUrlResolver)urlResolver
                          parser:(BaseNetworkManagerJsonParserBlock)parser
                         success:(void (^)(NSArray *))successBlock
                         failure:(void (^)(NSError *))failureBlock;

+ (NSURLSessionDataTask *)createOnServerWithParams:(id)params
       constructingBodyWithBlock:(void(^)(id<AFMultipartFormData> formData))constructBodyBlock
                     urlResolver:(FSModelNetworkUrlResolver)urlResolver
                          parser:(BaseNetworkManagerJsonParserBlock)parser
                         success:(void (^)(id createdInstance))successBlock
                         failure:(void (^)(NSError *error))failureBlock;

+ (NSURLSessionDataTask *)retrieveFromServerWithPrimaryKey:(id)primaryKey
                             urlResolver:(FSModelNetworkUrlResolver)urlResolver
                                  parser:(BaseNetworkManagerJsonParserBlock)parser
                                 success:(void (^)(id retrieveInstance))successBlock
                                 failure:(void (^)(NSError *error))failureBlock;

- (NSURLSessionDataTask *)retrieveFromServerWithUrlResolver:(FSModelNetworkUrlResolver)urlResolver
                                   parser:(BaseNetworkManagerJsonParserBlock)parser
                                  success:(void (^)())successBlock
                                  failure:(void (^)(NSError *error))failureBlock;

- (NSURLSessionDataTask *)updateOnServerWithParams:(id)params
       constructingBodyWithBlock:(void(^)(id<AFMultipartFormData> formData))constructBodyBlock
                     urlResolver:(FSModelNetworkUrlResolver)urlResolver
                          parser:(BaseNetworkManagerJsonParserBlock)parser
                         success:(void (^)())successBlock
                         failure:(void (^)(NSError *error))failureBlock;

// Subclasses can override the following methods for customization
+ (NSString *)networkListUrl; // will not prefix base url when overriden in subclass
+ (NSString *)networkCreateUrl;
- (NSString *)networkRetrieveUrl;
- (NSString *)networkUpdateUrl;
- (NSString *)networkDeleteUrl;

- (HttpMethod)networkUpdateHttpMethod; // default to POST

+ (FSModelNetworkUrlResolver)networkListUrlResolver;
- (FSModelNetworkUrlResolver)networkCreateUrlResolver;
- (FSModelNetworkUrlResolver)networkRetrieveUrlResolver;
- (FSModelNetworkUrlResolver)networkUpdateUrlResolver;
- (FSModelNetworkUrlResolver)networkDeleteUrlResolver;

+ (FSModelJsonArrayParser)jsonListParser;
+ (FSModelJsonParser)jsonCreateParser;
+ (FSModelJsonParser)jsonRetrieveParser;
+ (FSModelJsonParser)jsonUpdateParser;
+ (FSModelJsonParser)jsonDeleteParser;

@end
