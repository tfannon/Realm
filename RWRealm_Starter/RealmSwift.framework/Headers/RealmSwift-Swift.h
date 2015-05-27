// Generated by Apple Swift version 1.2 (swiftlang-602.0.49.6 clang-602.0.49)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import Realm;
@import Realm.Private;
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class RLMRealm;
@class RLMObjectSchema;
@class RLMSchema;


/// In Realm you define your model classes by subclassing <code>Object</code> and adding properties to be persisted.
/// You then instantiate and use your custom subclasses instead of using the RLMObject class directly.
///
/// ```swift
/// class Dog: Object {
///
/// <blockquote><p>dynamic var name: String = ""
/// dynamic var adopted: Bool = false
/// let siblings = List<Dog></p></blockquote>
/// }
/// ```
///
/// ### Supported property types
///
/// <ul><li><p><code>String</code></p></li><li><p><code>Int</code></p></li><li><p><code>Float</code></p></li><li><p><code>Double</code></p></li><li><p><code>Bool</code></p></li><li><p><code>NSDate</code></p></li><li><p><code>NSData</code></p></li><li><p><code>Object</code> subclasses for to-one relationships</p></li><li><p><code>List<T: Object></code> for to-many relationships</p></li></ul>
/// ### Querying
///
/// You can gets <code>Results</code> of an Object subclass via tha <code>objects(_:)</code> free function or
/// the <code>objects(_:)</code> instance method on <code>Realm</code>.
///
/// ### Relationships
///
/// See our [Cocoa guide](http://realm.io/docs/cocoa) for more details.
SWIFT_CLASS("_TtC10RealmSwift6Object")
@interface Object : RLMObjectBase

/// Initialize a standalone (unpersisted) Object.
/// Call <code>add(_:)</code> on a <code>Realm</code> to add standalone objects to a realm.
///
/// <dl><dt>see</dt><dd><p>Realm().add(_:)</p></dd></dl>
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;

/// Initialize a standalone (unpersisted) <code>Object</code> with values from an <code>Array<AnyObject></code> or <code>Dictionary<String, AnyObject></code>.
/// Call <code>add(_:)</code> on a <code>Realm</code> to add standalone objects to a realm.
///
/// \param value The value used to populate the object. This can be any key/value coding compliant
/// object, or a JSON object such as those returned from the methods in <code>NSJSONSerialization</code>,
/// or an <code>Array</code> with one object for each persisted property. An exception will be
/// thrown if any required properties are not present and no default is set.
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithValue:(id __nonnull)value OBJC_DESIGNATED_INITIALIZER;

/// Indicates if an object can no longer be accessed.
@property (nonatomic, readonly, getter=isInvalidated) BOOL invalidated;

/// Returns a human-readable description of this object.
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;

/// Override to designate a property as the primary key for an <code>Object</code> subclass. Only properties of
/// type String and Int can be designated as the primary key. Primary key
/// properties enforce uniqueness for each value whenever the property is set which incurs some overhead.
/// Indexes are created automatically for string primary key properties.
/// :returns: Name of the property designated as the primary key, or <code>nil</code> if the model has no primary key.
+ (NSString * __nullable)primaryKey;

/// Override to return an array of property names to ignore. These properties will not be persisted
/// and are treated as transient.
///
/// \returns <code>Array</code> of property names to ignore.
+ (NSArray * __nonnull)ignoredProperties;

/// Return an array of property names for properties which should be indexed. Only supported
/// for string properties.
/// :returns: <code>Array</code> of property names to index.
+ (NSArray * __nonnull)indexedProperties;

/// WARNING: This is an internal initializer not intended for public use.
/// :nodoc:
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithRealm:(RLMRealm * __nonnull)realm schema:(RLMObjectSchema * __nonnull)schema OBJC_DESIGNATED_INITIALIZER;

/// WARNING: This is an internal initializer not intended for public use.
/// :nodoc:
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithValue:(id __nonnull)value schema:(RLMSchema * __nonnull)schema OBJC_DESIGNATED_INITIALIZER;

/// Returns the value for the property identified by the given key.
/// :param: key The name of one of the receiver's properties.
/// :returns: The value for the property identified by <code>key</code>.
- (id __nullable)valueForKey:(NSString * __nonnull)key;

/// Sets the property of the receiver specified by the given key to the given value.
/// :param: value The value for the property identified by <code>key</code>.
/// :param: key   The name of one of the receiver's properties.
- (void)setValue:(id __nullable)value forKey:(NSString * __nonnull)key;
- (id __nullable)objectForKeyedSubscript:(NSString * __nonnull)key;
- (void)setObject:(id __nullable)value forKeyedSubscript:(NSString * __nonnull)key;
@end



/// Object interface which allows untyped getters and setters for Objects.
SWIFT_CLASS("_TtC10RealmSwift13DynamicObject")
@interface DynamicObject : Object

/// <dl><dt>nodoc</dt><dd></dd></dl>
- (id __nullable)valueForUndefinedKey:(NSString * __nonnull)key;

/// <dl><dt>nodoc</dt><dd></dd></dl>
- (void)setValue:(id __nullable)value forUndefinedKey:(NSString * __nonnull)key;
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithValue:(id __nonnull)value OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithRealm:(RLMRealm * __nonnull)realm schema:(RLMObjectSchema * __nonnull)schema OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithValue:(id __nonnull)value schema:(RLMSchema * __nonnull)schema OBJC_DESIGNATED_INITIALIZER;
@end

@class RLMArray;


/// <dl><dt>nodoc</dt><dd></dd></dl>
/// Internal class. Do not use directly.
SWIFT_CLASS("_TtC10RealmSwift8ListBase")
@interface ListBase : RLMListBase

/// Returns a human-readable description of the objects contained in the list.
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;

/// Returns the number of objects in this list.
@property (nonatomic, readonly) NSInteger count;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)initWithArray:(RLMArray * __null_unspecified)array OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



/// <code>List<T></code> is the container type in Realm used to define to-many relationships.
///
/// Lists hold a single <code>Object</code> subclass (<code>T</code>) which defines the "type" of the list.
///
/// Lists can be filtered and sorted with the same predicates as <code>Results<T></code>.
///
/// When added as a property on <code>Object</code> models, the property must be declared as <code>let</code> and cannot be <code>dynamic</code>.
SWIFT_CLASS("_TtC10RealmSwift4List")
@interface List : ListBase

/// Creates a <code>List</code> that holds objects of type <code>T</code>.
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;

/// Returns an Array containing the results of invoking <code>valueForKey:</code> using key on each of the collection's objects.
///
/// \param key The name of the property.
///
/// \returns Array containing the results of invoking <code>valueForKey:</code> using key on each of the collection's objects.
- (id __nullable)valueForKey:(NSString * __nonnull)key;

/// Invokes <code>setValue:forKey:</code> on each of the collection's objects using the specified value and key.
///
/// <dl><dt>warning</dt><dd><p>This method can only be called during a write transaction.</p></dd></dl>
/// \param value The object value.
///
/// \param key The name of the property.
- (void)setValue:(id __nullable)value forKey:(NSString * __nonnull)key;
@end


@interface List (SWIFT_EXTENSION(RealmSwift))
@end



@interface NSDate (SWIFT_EXTENSION(RealmSwift))
@end




/// <dl><dt>nodoc</dt><dd></dd></dl>
/// Internal class. Do not use directly.
SWIFT_CLASS("_TtC10RealmSwift10ObjectUtil")
@interface ObjectUtil : NSObject
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
