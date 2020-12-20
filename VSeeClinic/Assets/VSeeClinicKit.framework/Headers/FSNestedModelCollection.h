//
//  FSNestedModelCollection.h
//  CEP
//
//  Created by Ken on 7/31/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel+NetworkSubclass.h"

@protocol AFMultipartFormData;
@class FSModel, FSModelRelation;

@interface FSNestedModelCollection : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *name;
@property (nonatomic, copy, readonly, nullable) FSModelNetworkUrlResolver urlResolver;

- (nullable instancetype)initWithName:(nonnull NSString *)name
                               parent:(nonnull FSModel *)parent
                     childrenRelation:(nullable FSModelRelation *)childrenRelation
                          urlResolver:(nullable FSModelNetworkUrlResolver)urlResolver
           supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations;

- (nonnull NSArray *)list;
- (nonnull NSArray *)listSortedBy:(nullable NSString *)sortTerm ascending:(BOOL)ascending;
- (nonnull NSArray *)listWithPredicate:(nullable NSPredicate *)predicate;
- (nonnull NSArray *)listWithPredicate:(nullable NSPredicate *)predicate
                              sortedBy:(nullable NSString *)sortTerm
                             ascending:(BOOL)ascending;

- (nonnull NSPredicate *)parentPredicateInContext:(nullable NSManagedObjectContext *)context;
- (nonnull NSFetchRequest *)fetchRequestSortedBy:(nullable NSString *)sortTerm
                                       ascending:(BOOL)ascending
                                   withPredicate:(nullable NSPredicate *)searchTerm
                                       inContext:(nullable NSManagedObjectContext *)context;

// convenient method with predicate = nil
- (nonnull NSFetchRequest *)fetchRequestSortedBy:(nullable NSString *)sortTerm
                                       ascending:(BOOL)ascending
                                       inContext:(nullable NSManagedObjectContext *)context;

// this method must be used to get NSFetchedResultsController
// for retrieveFromNetworkWithPrimaryKey:success:failure: to work on instance
- (nonnull NSFetchedResultsController *)fetchResultsControllerWithFetchRequest:(nonnull NSFetchRequest *)fetchRequest
                                                          managedObjectContext: (nullable NSManagedObjectContext *)context
                                                            sectionNameKeyPath:(nullable NSString *)sectionNameKeyPath
                                                                     cacheName:(nullable NSString *)name;

- (nonnull NSURLSessionDataTask *)listFromServerWithParams:(nullable NSDictionary *)params
                                                   success:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

// convenient method with params = nil
- (nonnull NSURLSessionDataTask *)listFromServerSuccess:(nullable void (^)(NSArray * _Nonnull instances))successBlock
                                                failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;


- (nonnull NSURLSessionDataTask *)createOnServerWithParams:(nullable NSDictionary *)params
                                 constructingBodyWithBlock:(nullable void(^)(id<AFMultipartFormData> _Nonnull formData))constructBodyBlock
                                                   success:(nullable void (^)(id _Nonnull createdInstance))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)createOnServerWithParams:(nullable NSDictionary *)params
                                 constructingBodyWithBlock:(nullable void(^)(id<AFMultipartFormData> _Nonnull formData))constructBodyBlock
                                                    parser:(BaseNetworkManagerJsonParserBlock _Nullable )parser
                                                   success:(nullable void (^)(id _Nonnull createdInstance))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (void)createOnLocalWithParams:(nullable NSDictionary *)params
                        success:(nullable void (^)(id _Nonnull createdInstance))successBlock;

// convenient method with constructBodyBlock = nil
- (nonnull NSURLSessionDataTask *)createOnServerWithParams:(nullable NSDictionary *)params
                                                   success:(nullable void (^)(id _Nonnull createdInstance))successBlock
                                                   failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

- (nonnull NSURLSessionDataTask *)retrieveFromServerWithPrimaryKey:(nonnull id)primaryKey
                                                           success:(nullable void (^)(id _Nonnull retrievedInstance))successBlock
                                                           failure:(nullable void (^)(NSError * _Nonnull error))failureBlock;

@end
