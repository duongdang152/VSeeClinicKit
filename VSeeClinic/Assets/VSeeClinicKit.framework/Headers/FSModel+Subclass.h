//
//  FSModel+Subclass.h
//  CEP
//
//  Created by Ken on 7/23/16.
//  Copyright © 2016 vsee. All rights reserved.
//

#import "FSModel.h"

extern NSString *FSModelFieldOptionPrimaryKey;
extern NSString *FSModelFieldOptionRequired;
extern NSString *FSModelFieldOptionAllowBlank;
extern NSString *FSModelFieldOptionDefaultValue;

extern NSString *FSModelRelationOptionRequired;
extern NSString *FSModelRelationOptionAllowBlank;

extern NSString *const CoreDataDefaultRelationshipPrefix;


typedef NS_ENUM(NSUInteger, FSModelFieldType) {
    FSModelFieldTypeString = 0,
    FSModelFieldTypeInt,
    FSModelFieldTypeBool,
    FSModelFieldTypeDecimal,
    FSModelFieldTypeDate,
    FSModelFieldTypeTransformable,
};

typedef NS_ENUM(NSUInteger, FSModelRelationType) {
    FSModelRelationTypeStringPrimaryKey = 0,
    FSModelRelationTypeIntPrimaryKey,
    FSModelRelationTypeNestedObject
};


@interface FSModelField : NSObject

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSAttributeDescription *attributeDescription;

@property (nonatomic, copy, readonly) NSString *jsonName;
@property (nonatomic, assign, readonly) FSModelFieldType type;
@property (nonatomic, assign, readonly, getter=isRequired) BOOL required; // if required is YES, field must be supplied when parsing (parsed as nil if missing); if required is NO, field will be skipped when missing; default to NO
@property (nonatomic, assign, readonly, getter=isIgnored) BOOL ignored; // should be ignored in automatic parsing
@property (nonatomic, assign, readonly, getter=isPrimaryKey) BOOL primaryKey; // if primary key is YES, required is forced to YES and allowBlank is forced to NO
@property (nonatomic, assign, readonly) BOOL allowBlank; // whether blank/nil value is allowed; default to YES
@property (nonatomic, copy, readonly) id defaultValue; // default value to use when blank/nil, optional; default to nil

@end


@interface FSModelRelation : NSObject

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSRelationshipDescription *relationshipDescription;

@property (nonatomic, copy, readonly) NSString *jsonName; // if jsonName = nil, relation will not be processed during json parsing, but it can still be manually triggered
@property (nonatomic, assign, readonly) FSModelRelationType type;
@property (nonatomic, assign, readonly) Class relatedClass; // must be subclass of FSModel
@property (nonatomic, assign, readonly, getter=isRequired) BOOL required; // if required is NO, relation will be skipped when missing; default is NO
@property (nonatomic, assign, readonly, getter=isIgnored) BOOL ignored; // should be ignored in automatic parsing
@property (nonatomic, assign, readonly) BOOL allowBlank; // default to YES
@property (nonatomic, assign, readonly, getter=isToMany) BOOL toMany;
@property (nonatomic, assign, readonly) BOOL hasInverseRelation;

@end


@interface FSModel ()

+ (NSArray *)fields; // default implementations simply returns cached [self buildFieldsFromAttributeDescription]
+ (NSArray *)buildFieldsFromAttributeDescription;
+ (NSArray *)relations; // default implementations simply returns cached [self buildRelationsFromRelationshipDescription]
+ (NSArray *)buildRelationsFromRelationshipDescription;

+ (BOOL)hasPrimaryKeyField; // default to YES, must be explicitly set to NO even if fields return no pk field
+ (FSModelField *)primaryKeyField; // raise NSAssertionError if hasPrimaryKeyField is NO
+ (BOOL)hasPrimaryKeyRelation; // default to NO, for fallback use when the model doesn't have primary key field but has 1-1 relationship with a model that has
                               // only used to retrieve the instance, not in syncing
+ (FSModelRelation *)primaryKeyRelation;

+ (BOOL)hasLocalId; // default to NO, local id is stored locally only, and is different from primary key (which is synced with server)
+ (FSModelField *)localIdField; // raise NSAssertionError if hasLocalId is NO
//+ (NSNumber *)nextLocalId;

+ (FSModelField *)fieldWithName:(NSString *)name;
+ (FSModelRelation *)relationWithName:(NSString *)name;
+ (FSModelField *)fieldWithSelector:(SEL)selector;
+ (FSModelRelation *)relationWithSelector:(SEL)selector;

+ (BOOL)isSupportedJSON:(NSDictionary *)json; // some json objects are to be excluded from iOS clients, default to YES
+ (BOOL)areMissingInstancesRemovedWhenSyncingList; // default to YES

+ (BOOL)syncClassByTypeField; // default to NO, whether to sync json to correct class/subclass by checking type field
                              // if no class if found for the given type, current class/superclass will be used
+ (FSModelField *)classTypeField; // must not be nil if is YES
+ (void)registerSubClass:(Class)subclass forType:(id)type;
+ (Class)classForType:(id)type;

+ (instancetype)createWithJSON:(NSDictionary *)json inContext:(NSManagedObjectContext *)context;
+ (instancetype)syncWithJSON:(NSDictionary *)json inContext:(NSManagedObjectContext *)context;
+ (NSArray *)syncWithJSONArray:(NSArray *)jsons inContext:(NSManagedObjectContext *)context;
+ (instancetype)instanceWithPrimaryKey:(id)primaryKey inContext:(NSManagedObjectContext *)context;

+ (FSModelJsonParser)jsonParserInContext:(NSManagedObjectContext *)context;
+ (FSModelJsonArrayParser)jsonArrayParserInContext:(NSManagedObjectContext *)context
                           missingInstancesRemoved:(BOOL)missingIntancesRemoved;
// convenient method with missingInstancesRemoved set to [self areMissingInstancesRemovedWhenSyncingList]
+ (FSModelJsonArrayParser)jsonArrayParserInContext:(NSManagedObjectContext *)context;

+ (id (^)(id))combineJsonParsers:(NSArray *)jsonParsers;
+ (id)parseField:(FSModelField *)field inJson:(NSDictionary *)json instance:(FSModel *)instance;
+ (id)parseField:(FSModelField *)field rawValue:(id)rawValue instance:(FSModel *)instance isUpdating:(BOOL)isUpdating; // class method so that it can be used in create/sync with JSON to parse pk field
+ (id)getJSONRawValue:(NSDictionary *)json key:(NSString *)key; // works with nested key: obj1.obj2.property

- (id)parseRelation:(FSModelRelation *)relation rawValue:(id)rawValue;

- (void)createWithJSON:(NSDictionary *)json;
- (void)updateWithJSON:(NSDictionary *)json;
- (id)getFieldValue:(FSModelField *)field;
- (id)getRelationValue:(FSModelRelation *)relation;
- (void)setField:(FSModelField *)field rawValue:(id)rawValue;
- (void)setField:(FSModelField *)field parsedValue:(id)parsedValue;
- (void)setRelation:(FSModelRelation *)relation rawValue:(id)rawValue;
- (void)setRelation:(FSModelRelation *)relation parsedValue:(id)parsedValue;

- (void)setFieldValue:(id)value forName:(NSString *)name;
- (void)setRelationValue:(FSModel *)instance forName:(NSString *)name;
- (void)setRelationSetValue:(NSSet *)relatedInstances forName:(NSString *)name predicate:(NSPredicate *)predicate; // update relation 'name' with value of relatedInstances: new instances will be added, missing old instances satisfying predicate will be removed; 
- (void)setRelationArrayValue:(NSArray *)relatedInstances forName:(NSString *)name predicate:(NSPredicate *)predicate;
// convenient methods with predicate = nil
- (void)setRelationSetValue:(NSSet *)relatedInstances forName:(NSString *)name;
- (void)setRelationArrayValue:(NSArray *)relatedInstances forName:(NSString *)name;

- (void)addRelationSetValue:(NSSet *)addedObjects forName:(NSString *)name;
- (void)addRelationArrayValue:(NSArray *)addedObjects forName:(NSString *)name;
- (void)addRelationValue:(FSModel *)addedObject forName:(NSString *)name;
- (void)removeRelationSetValue:(NSSet *)removedObjects forName:(NSString *)name;
- (void)removeRelationArrayValue:(NSArray *)removedObjects forName:(NSString *)name;
- (void)removeRelationValue:(FSModel *)removedObject forName:(NSString *)name;

- (FSModel* (^)(FSModel *relatedInstance))jsonParserForRelation:(FSModelRelation *)relation;
- (NSArray* (^)(NSArray *relatedInstances))jsonArrayParserForRelation:(FSModelRelation *)relation;

- (instancetype)copyInContext:(NSManagedObjectContext *)context deepCopy:(BOOL)shouldDeepCopy; // deepCopy: whether to propagate changes in relations as well
                                                                                               // only support 1 level of nested relations
                                                                                               // usually used within [MagicalRecord saveWithBlock:]
- (void)copy:(FSModel *)instance deepCopy:(BOOL)shouldDeepCopy; // instance is usually in a diffent context, usually used for propagate changes from editing context to saving context

- (void)onDeletion; // called BEFORE the entity is deleted

- (NSDictionary *)debugDescriptionProperties:(BOOL)includeRelations;
@end
