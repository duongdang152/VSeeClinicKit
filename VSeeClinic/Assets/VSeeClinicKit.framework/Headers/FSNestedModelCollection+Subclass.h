//
//  FSNestedModelCollection+Subclass.h
//  CEP
//
//  Created by Ken on 8/16/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "FSNestedModelCollection.h"

typedef FSModel* (^FSNestedModelJsonParser)(id);
typedef FSModel* (^FSNestedModelParentParser)(FSModel *);
typedef NSArray* (^FSNestedModelJsonArrayParser)(id);
typedef NSArray* (^FSNestedModelArrayParentParser)(NSArray *);
typedef NSString* (^FSNestedModelUrlResolver)(NSString *, NSString*);

@interface FSNestedModelCollection (Subclass)

@property (nonatomic, weak, readonly) FSModel *parent; // usually it's better to use parentInContext: instead
                                                       // since it handles retrieving from a different context
@property (nonatomic, weak, readonly) NSManagedObjectContext *parentContext;
@property (nonatomic, strong, readonly) FSModelRelation *childrenRelation;
@property (nonatomic, readonly) Class childClass;
@property (nonatomic, copy, readonly) FSModelNetworkUrlResolver urlResolver;

- (FSModel *)parentInContext:(NSManagedObjectContext *)context;
- (FSNestedModelJsonParser)jsonParser;
- (FSNestedModelParentParser)parentParser;
- (FSNestedModelJsonArrayParser)jsonArrayParser:(BOOL)removeMissingIntances
                                      predicate:(NSPredicate *)predicate; // only missing old instances satisfying predicate will be removed
- (FSNestedModelArrayParentParser)arrayParentParser:(BOOL)removeMissingIntances
                                          predicate:(NSPredicate *)predicate; // only missing old instances satisfying predicate will be removed

@end
