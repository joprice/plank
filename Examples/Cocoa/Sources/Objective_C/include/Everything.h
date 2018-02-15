//
//  Everything.h
//  Autogenerated by plank
//
//  DO NOT EDIT - EDITS WILL BE OVERWRITTEN
//  @generated
//

#import <Foundation/Foundation.h>
#import "PlankModelRuntime.h"
@class Board;
@class Everything;
@class EverythingBuilder;
@class Image;
@class Pin;
@class User;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EverythingMapPolymorphicValuesInternalType) {
    EverythingMapPolymorphicValuesInternalTypeUser = 1,
    EverythingMapPolymorphicValuesInternalTypeBoard = 2,
    EverythingMapPolymorphicValuesInternalTypeImage = 3,
    EverythingMapPolymorphicValuesInternalTypePin = 4,
    EverythingMapPolymorphicValuesInternalTypeEverything = 5
};

@interface EverythingMapPolymorphicValues : NSObject<NSCopying, NSSecureCoding>

+ (instancetype)objectWithUser:(User *)user;
+ (instancetype)objectWithBoard:(Board *)board;
+ (instancetype)objectWithImage:(Image *)image;
+ (instancetype)objectWithPin:(Pin *)pin;
+ (instancetype)objectWithEverything:(Everything *)everything;
- (void)matchUser:(nullable PLANK_NOESCAPE void (^)(User * user))userMatchHandler orBoard:(nullable PLANK_NOESCAPE void (^)(Board * board))boardMatchHandler orImage:(nullable PLANK_NOESCAPE void (^)(Image * image))imageMatchHandler orPin:(nullable PLANK_NOESCAPE void (^)(Pin * pin))pinMatchHandler orEverything:(nullable PLANK_NOESCAPE void (^)(Everything * everything))everythingMatchHandler;
- (BOOL)isEqualToEverythingMapPolymorphicValues:(EverythingMapPolymorphicValues *)anObject;
@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EverythingPolymorphicPropInternalType) {
    EverythingPolymorphicPropInternalTypeUser = 1,
    EverythingPolymorphicPropInternalTypeBoard = 2,
    EverythingPolymorphicPropInternalTypeImage = 3,
    EverythingPolymorphicPropInternalTypePin = 4,
    EverythingPolymorphicPropInternalTypeEverything = 5,
    EverythingPolymorphicPropInternalTypeString = 6,
    EverythingPolymorphicPropInternalTypeBoolean = 7,
    EverythingPolymorphicPropInternalTypeInteger = 8,
    EverythingPolymorphicPropInternalTypeFloat = 9,
    EverythingPolymorphicPropInternalTypeDate = 10,
    EverythingPolymorphicPropInternalTypeURL = 11
};

@interface EverythingPolymorphicProp : NSObject<NSCopying, NSSecureCoding>

+ (instancetype)objectWithUser:(User *)user;
+ (instancetype)objectWithBoard:(Board *)board;
+ (instancetype)objectWithImage:(Image *)image;
+ (instancetype)objectWithPin:(Pin *)pin;
+ (instancetype)objectWithEverything:(Everything *)everything;
+ (instancetype)objectWithString:(NSString *)string;
+ (instancetype)objectWithBoolean:(BOOL)boolean;
+ (instancetype)objectWithInteger:(NSInteger)integer;
+ (instancetype)objectWithFloat:(double)floatProperty;
+ (instancetype)objectWithDate:(NSDate *)date;
+ (instancetype)objectWithURL:(NSURL *)uRL;
- (void)matchUser:(nullable PLANK_NOESCAPE void (^)(User * user))userMatchHandler orBoard:(nullable PLANK_NOESCAPE void (^)(Board * board))boardMatchHandler orImage:(nullable PLANK_NOESCAPE void (^)(Image * image))imageMatchHandler orPin:(nullable PLANK_NOESCAPE void (^)(Pin * pin))pinMatchHandler orEverything:(nullable PLANK_NOESCAPE void (^)(Everything * everything))everythingMatchHandler orString:(nullable PLANK_NOESCAPE void (^)(NSString * string))stringMatchHandler orBoolean:(nullable PLANK_NOESCAPE void (^)(BOOL boolean))booleanMatchHandler orInteger:(nullable PLANK_NOESCAPE void (^)(NSInteger integer))integerMatchHandler orFloat:(nullable PLANK_NOESCAPE void (^)(double float))floatMatchHandler orDate:(nullable PLANK_NOESCAPE void (^)(NSDate * date))dateMatchHandler orURL:(nullable PLANK_NOESCAPE void (^)(NSURL * uRL))uRLMatchHandler;
- (BOOL)isEqualToEverythingPolymorphicProp:(EverythingPolymorphicProp *)anObject;
@end

NS_ASSUME_NONNULL_END

typedef NS_ENUM(NSInteger, EverythingIntEnum) {
    EverythingIntEnumIntCase1 = 1,
    EverythingIntEnumIntCase2 = 2,
    EverythingIntEnumIntCase3 = 3
};

typedef NS_ENUM(NSInteger, EverythingStringEnum) {
    EverythingStringEnumCase1 /* case1 */,
    EverythingStringEnumCase2 /* case2 */,
    EverythingStringEnumCase3 /* case3 */
};

extern NSString * _Nonnull EverythingStringEnumToString(EverythingStringEnum enumType);

extern EverythingStringEnum EverythingStringEnumFromString(NSString * _Nonnull str);

NS_ASSUME_NONNULL_BEGIN

@interface Everything : NSObject<NSCopying, NSSecureCoding>
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, EverythingMapPolymorphicValues *> * mapPolymorphicValues;
@property (nonatomic, assign, readonly) BOOL booleanProp;
@property (nullable, nonatomic, strong, readonly) NSSet<NSString *> * setPropWithValues;
@property (nullable, nonatomic, copy, readonly) NSString * stringProp;
@property (nullable, nonatomic, copy, readonly) NSDate * dateProp;
@property (nullable, nonatomic, strong, readonly) NSArray * listPolymorphicValues;
@property (nullable, nonatomic, strong, readonly) NSArray<NSNumber /* Integer */ *> * listWithPrimitiveValues;
@property (nullable, nonatomic, strong, readonly) NSSet * setProp;
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> * listWithObjectValues;
@property (nullable, nonatomic, strong, readonly) User * otherModelProp;
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> * mapWithObjectValues;
@property (nullable, nonatomic, strong, readonly) NSSet<User *> * setPropWithOtherModelValues;
@property (nonatomic, assign, readonly) EverythingIntEnum intEnum;
@property (nullable, nonatomic, strong, readonly) NSArray<User *> * listWithOtherModelValues;
@property (nonatomic, assign, readonly) double numberProp;
@property (nonatomic, assign, readonly) NSInteger intProp;
@property (nullable, nonatomic, strong, readonly) NSDictionary * mapProp;
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, User *> * mapWithOtherModelValues;
@property (nullable, nonatomic, strong, readonly) NSArray * arrayProp;
@property (nonatomic, assign, readonly) EverythingStringEnum stringEnum;
@property (nullable, nonatomic, copy, readonly) NSURL * uriProp;
@property (nullable, nonatomic, strong, readonly) NSSet<NSNumber /*> Integer */ *> * setPropWithPrimitiveValues;
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSNumber /* Integer */ *> * mapWithPrimitiveValues;
@property (nullable, nonatomic, strong, readonly) EverythingPolymorphicProp * polymorphicProp;
+ (NSString *)className;
+ (NSString *)polymorphicTypeIdentifier;
+ (instancetype)modelObjectWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithModelDictionary:(NS_VALID_UNTIL_END_OF_SCOPE NSDictionary *)modelDictionary;
- (instancetype)initWithBuilder:(EverythingBuilder *)builder;
- (instancetype)initWithBuilder:(EverythingBuilder *)builder initType:(PlankModelInitType)initType;
- (instancetype)copyWithBlock:(PLANK_NOESCAPE void (^)(EverythingBuilder *builder))block;
- (BOOL)isEqualToEverything:(Everything *)anObject;
- (instancetype)mergeWithModel:(Everything *)modelObject;
- (instancetype)mergeWithModel:(Everything *)modelObject initType:(PlankModelInitType)initType;
- (NSDictionary *)dictionaryObjectRepresentation;
@end

@interface EverythingBuilder : NSObject
@property (nullable, nonatomic, strong, readwrite) NSDictionary<NSString *, EverythingMapPolymorphicValues *> * mapPolymorphicValues;
@property (nonatomic, assign, readwrite) BOOL booleanProp;
@property (nullable, nonatomic, strong, readwrite) NSSet<NSString *> * setPropWithValues;
@property (nullable, nonatomic, copy, readwrite) NSString * stringProp;
@property (nullable, nonatomic, copy, readwrite) NSDate * dateProp;
@property (nullable, nonatomic, strong, readwrite) NSArray * listPolymorphicValues;
@property (nullable, nonatomic, strong, readwrite) NSArray<NSNumber /* Integer */ *> * listWithPrimitiveValues;
@property (nullable, nonatomic, strong, readwrite) NSSet * setProp;
@property (nullable, nonatomic, strong, readwrite) NSArray<NSString *> * listWithObjectValues;
@property (nullable, nonatomic, strong, readwrite) User * otherModelProp;
@property (nullable, nonatomic, strong, readwrite) NSDictionary<NSString *, NSString *> * mapWithObjectValues;
@property (nullable, nonatomic, strong, readwrite) NSSet<User *> * setPropWithOtherModelValues;
@property (nonatomic, assign, readwrite) EverythingIntEnum intEnum;
@property (nullable, nonatomic, strong, readwrite) NSArray<User *> * listWithOtherModelValues;
@property (nonatomic, assign, readwrite) double numberProp;
@property (nonatomic, assign, readwrite) NSInteger intProp;
@property (nullable, nonatomic, strong, readwrite) NSDictionary * mapProp;
@property (nullable, nonatomic, strong, readwrite) NSDictionary<NSString *, User *> * mapWithOtherModelValues;
@property (nullable, nonatomic, strong, readwrite) NSArray * arrayProp;
@property (nonatomic, assign, readwrite) EverythingStringEnum stringEnum;
@property (nullable, nonatomic, copy, readwrite) NSURL * uriProp;
@property (nullable, nonatomic, strong, readwrite) NSSet<NSNumber /*> Integer */ *> * setPropWithPrimitiveValues;
@property (nullable, nonatomic, strong, readwrite) NSDictionary<NSString *, NSNumber /* Integer */ *> * mapWithPrimitiveValues;
@property (nullable, nonatomic, strong, readwrite) EverythingPolymorphicProp * polymorphicProp;
- (instancetype)initWithModel:(Everything *)modelObject;
- (Everything *)build;
- (void)mergeWithModel:(Everything *)modelObject;
@end

NS_ASSUME_NONNULL_END
