//
//  FSModel+NestedCollection.h
//  CEP
//
//  Created by Ken on 8/5/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSModel.h"
#import "FSModel+NetworkSubclass.h"

@class FSNestedModelCollection;

@interface FSModel (NestedCollection)

- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                               fsModelRelationName:(NSString *)relationName
                                                       urlResolver:(FSModelNetworkUrlResolver)urlResolver
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations
                                        nestedModelCollectionClass:(Class)collectionClass; // must be subclass of FSNestedModelCollection

// convenient method with collectionClass = FSNestedModelCollection
- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                               fsModelRelationName:(NSString *)relationName
                                                       urlResolver:(FSModelNetworkUrlResolver)urlResolver
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations;

// conventions: FSNestedModelCollection property should have corresponding core data relationship with name prefixed with 'cd_'
// for example: FSNestedModelCollection property 'users' should have corresponding core data relationship named 'cd_users'
- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                                       urlResolver:(FSModelNetworkUrlResolver)urlResolver
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations
                                        nestedModelCollectionClass:(Class)collectionClass;

// convenient method with collectionClass = FSNestedModelCollection
- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                                       urlResolver:(FSModelNetworkUrlResolver)urlResolver
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations;

// convenient method with default url resolver
- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations
                                        nestedModelCollectionClass:(Class)collectionClass;

// convenient method with collectionClass = FSNestedModelCollection
- (FSNestedModelCollection *)nestedModelCollectionForPropertyNamed:(NSString *)propertyName
                                        supportedNetworkOperations:(FSModelNetworkOperation)supportedNetworkOperations;

- (FSModelNetworkUrlResolver)nestedModelCollectionUrlResolver;

@end
