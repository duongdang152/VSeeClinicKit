//
//  FSModel.h
//  FruitStreet
//
//  Created by Ken on 6/17/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import <CoreData/CoreData.h>

@class FSModel;

typedef FSModel* (^FSModelJsonParser)(NSDictionary *json);
typedef NSArray* (^FSModelJsonArrayParser)(id json);

@interface FSModel : NSManagedObject

@property (nonatomic, copy, readonly) id primaryKey; // synced with server, will raise NSAssertionFailure if hasPrimaryKeyField is NO
@property (nonatomic, copy, readonly) NSNumber *localId; // store locally only 

+ (instancetype)createWithJSON:(NSDictionary *)json;
+ (instancetype)syncWithJSON:(NSDictionary *)json;  // update if existed, otherwise create
+ (NSArray *)syncWithJSONArray:(NSArray *)jsons; // update if existed, otherwise create; will NOT delete existing elements that are not in the array
+ (instancetype)instanceWithPrimaryKey:(id)primaryKey;
+ (nullable instancetype)firstInstanceWithPredicate:(NSPredicate *)predicate;

+ (NSArray *)list; // list local instances
+ (NSArray *)listSortedBy:(NSString *)sortTerm ascending:(BOOL)ascending;
+ (NSArray *)listWithPredicate:(NSPredicate *)predicate;
+ (NSArray *)listWithPredicate:(NSPredicate *)predicate sortedBy:(NSString *)sortTerm ascending:(BOOL)ascending;

+ (NSException *)parsingDictionaryErrorException:(NSString *)description;

+ (FSModelJsonParser)jsonParser;
+ (FSModelJsonArrayParser)jsonArrayParser;

+ (void)saveInstancesToPersistentStore:(NSArray *)instances completionHandler:(void (^)(BOOL success, NSError *error))completionHandler;
+ (void)saveReadContext;
+ (void)clearCache;

- (void)saveToPersistentStore:(void (^)(BOOL success, NSError *error))completionHandler;
- (NSDictionary *)jsonValue;
- (void)updatePrivarykey;

- (void)deleteEntity;

@end
