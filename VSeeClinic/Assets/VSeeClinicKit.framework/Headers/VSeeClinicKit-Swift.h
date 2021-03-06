// Generated by Apple Swift version 5.2.4 effective-4.2 (swiftlang-1103.0.32.9 clang-1103.0.32.53)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
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
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Eureka;
@import Foundation;
@import ImagePicker;
@import ObjectiveC;
@import Stripe;
@import TTTAttributedLabel;
@import UIKit;
@import VSeeKit;
@import WebKit;
@import XLPagerTabStrip;
#endif

#import <VSeeClinicKit/VSeeClinicKit.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="VSeeClinicKit",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class UITableView;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC13VSeeClinicKit20VCFormViewController")
@interface VCFormViewController : FormViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (CGFloat)tableView:(UITableView * _Nonnull)tableView heightForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit24SignUpFormViewController")
@interface SignUpFormViewController : VCFormViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit28ActivateSignUpViewController")
@interface ActivateSignUpViewController : SignUpFormViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class STPPaymentCardTextField;

SWIFT_CLASS("_TtC13VSeeClinicKit24AddPaymentViewController")
@interface AddPaymentViewController : UIViewController <STPPaymentCardTextFieldDelegate>
- (void)viewDidLoad;
- (void)paymentCardTextFieldDidChange:(STPPaymentCardTextField * _Nonnull)textField;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit16AnalyticsWrapper")
@interface AnalyticsWrapper : NSObject
+ (void)startNewSession;
+ (void)setUserIDWithUserID:(NSString * _Nullable)userID;
+ (void)setAccountCodeWithAccountCode:(NSString * _Nullable)accountCode;
+ (void)setRoomCodeWithRoomCode:(NSString * _Nullable)roomCode;
+ (void)logEventWithCode:(NSString * _Nonnull)code type:(NSString * _Nonnull)type parametters:(NSDictionary<NSString *, id> * _Nullable)parametters;
+ (void)forceUploadEventWithCompletion:(void (^ _Nullable)(BOOL))completion;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class Account;

SWIFT_CLASS("_TtC13VSeeClinicKit17AppVersionChecker")
@interface AppVersionChecker : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) AppVersionChecker * _Nonnull defaultChecker;)
+ (AppVersionChecker * _Nonnull)defaultChecker SWIFT_WARN_UNUSED_RESULT;
- (void)checkAppVersionSupported:(Account * _Nullable)newAccount :(void (^ _Nonnull)(BOOL))completionHandler;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit8CardCell")
@interface CardCell : UITableViewCell
@property (nonatomic, getter=isSelected) BOOL selected;
- (nonnull instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString * _Nullable)reuseIdentifier OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=3.0);
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit10ClinicAuth")
@interface ClinicAuth : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class VCNetworkManager;
@class VSeeNetworkError;

@interface ClinicAuth (SWIFT_EXTENSION(VSeeClinicKit)) <VCNetworkManagerDelegate>
- (void)networkManagerSessionDidExpire:(VCNetworkManager * _Nonnull)networkManager requestUrl:(NSString * _Nullable)requestUrl;
- (void)vseeLoginDidFail:(VCNetworkManager * _Nonnull)networkManager error:(VSeeNetworkError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit13DependantCell")
@interface DependantCell : UITableViewCell
- (nonnull instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString * _Nullable)reuseIdentifier OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=3.0);
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit20ComplexDependantCell")
@interface ComplexDependantCell : DependantCell
@property (nonatomic, getter=isSelected) BOOL selected;
- (void)awakeFromNib;
- (nonnull instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString * _Nullable)reuseIdentifier OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=3.0);
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class WKWebView;
@class WKNavigation;

SWIFT_CLASS("_TtC13VSeeClinicKit21ConsentViewController")
@interface ConsentViewController : UIViewController <WKNavigationDelegate>
- (void)viewDidLoad;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)webView:(WKWebView * _Nonnull)webView didFinishNavigation:(WKNavigation * _Null_unspecified)navigation;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC13VSeeClinicKit27DependantListViewController")
@interface DependantListViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIColor;

IB_DESIGNABLE
SWIFT_CLASS("_TtC13VSeeClinicKit14DottedLineView")
@interface DottedLineView : UIView
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull lineColor;
@property (nonatomic) IBInspectable CGFloat lineWidth;
@property (nonatomic) IBInspectable BOOL round;
@property (nonatomic) IBInspectable BOOL horizontal;
@property (nonatomic) IBInspectable CGFloat spacing;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)prepareForInterfaceBuilder;
- (void)drawRect:(CGRect)rect;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit17EMRFormController")
@interface EMRFormController : FormViewController
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (void)viewDidLoad;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit27FamilyHistoryFormController")
@interface FamilyHistoryFormController : FormViewController
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil SWIFT_UNAVAILABLE;
- (void)viewDidLoad;
- (void)viewWillDisappear:(BOOL)animated;
@end

@class UIImage;

/// Utility for accessing local files (save/load)
/// @author Diazz
/// @version 1.0
SWIFT_CLASS("_TtC13VSeeClinicKit8FileUtil")
@interface FileUtil : NSObject
+ (NSURL * _Nullable)saveLocalImage:(NSInteger)localId image:(UIImage * _Nonnull)image SWIFT_WARN_UNUSED_RESULT;
+ (void)removeLocalImageFile:(NSInteger)localId;
+ (NSData * _Nullable)getLocalImageFile:(NSInteger)localId SWIFT_WARN_UNUSED_RESULT;
+ (NSURL * _Nonnull)getLocalImageFileURL:(NSInteger)localId SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit14FlowFormHeader")
@interface FlowFormHeader : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class TTTAttributedLabel;

@interface FlowFormHeader (SWIFT_EXTENSION(VSeeClinicKit)) <TTTAttributedLabelDelegate>
- (void)attributedLabel:(TTTAttributedLabel * _Null_unspecified)label didSelectLinkWithURL:(NSURL * _Null_unspecified)url;
- (void)attributedLabel:(TTTAttributedLabel * _Null_unspecified)label didSelectLinkWithPhoneNumber:(NSString * _Null_unspecified)phoneNumber;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit22FlowFormViewController")
@interface FlowFormViewController : VCFormViewController
- (void)viewDidLoad;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)submit;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit25ProfileFormViewController")
@interface ProfileFormViewController : VCFormViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit29FlowProfileFormViewController")
@interface FlowProfileFormViewController : ProfileFormViewController
- (void)viewDidLoad;
- (void)viewWillDisappear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit30HealthDataViewerViewController")
@interface HealthDataViewerViewController : UITableViewController <UIPopoverPresentationControllerDelegate>
- (void)viewDidLoad;
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithStyle:(UITableViewStyle)style OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit25HealthHabitFormController")
@interface HealthHabitFormController : EMRFormController
- (void)viewDidLoad;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
@end

@class UIStoryboardSegue;
@class UICollectionView;
@class UICollectionViewCell;
@class UICollectionViewLayout;

SWIFT_CLASS("_TtC13VSeeClinicKit34HealthRateCollectionViewController")
@interface HealthRateCollectionViewController : UICollectionViewController <UICollectionViewDelegateFlowLayout>
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidLayoutSubviews;
- (void)prepareForSegue:(UIStoryboardSegue * _Nonnull)segue sender:(id _Nullable)sender;
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView * _Nonnull)collectionView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)collectionView:(UICollectionView * _Nonnull)collectionView numberOfItemsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UICollectionViewCell * _Nonnull)collectionView:(UICollectionView * _Nonnull)collectionView cellForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView didSelectItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (CGSize)collectionView:(UICollectionView * _Nonnull)collectionView layout:(UICollectionViewLayout * _Nonnull)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithCollectionViewLayout:(UICollectionViewLayout * _Nonnull)layout OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end




SWIFT_CLASS("_TtC13VSeeClinicKit28HealthRateDataViewController")
@interface HealthRateDataViewController : UITableViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)tableView:(UITableView * _Nonnull)tableView willDisplayCell:(UITableViewCell * _Nonnull)cell forRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithStyle:(UITableViewStyle)style OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end




SWIFT_CLASS("_TtC13VSeeClinicKit18HelpViewController")
@interface HelpViewController : UIViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit32ManageConsultationViewController")
@interface ManageConsultationViewController : VCFormViewController
- (void)viewDidLoad;
- (void)viewWillDisappear:(BOOL)animated;
- (void)submit;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit27ManagePaymentViewController")
@interface ManagePaymentViewController : VCFormViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)buttonTapped;
- (void)submit;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end






SWIFT_CLASS("_TtC13VSeeClinicKit22PharmacyViewController")
@interface PharmacyViewController : UIViewController
- (void)viewDidLoad;
- (void)viewWillLayoutSubviews;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)prepareForSegue:(UIStoryboardSegue * _Nonnull)segue sender:(id _Nullable)sender;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@interface PharmacyViewController (SWIFT_EXTENSION(VSeeClinicKit)) <UITableViewDataSource, UITableViewDelegate>
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit34PopOverDependantListViewController")
@interface PopOverDependantListViewController : DependantListViewController
@property (nonatomic) CGSize preferredContentSize;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewDidLoad;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC13VSeeClinicKit29SelectDependantViewController")
@interface SelectDependantViewController : DependantListViewController
- (void)viewDidLoad;
- (UIView * _Nullable)tableView:(UITableView * _Nonnull)tableView viewForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit27SelectPaymentViewController")
@interface SelectPaymentViewController : UIViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@interface SelectPaymentViewController (SWIFT_EXTENSION(VSeeClinicKit)) <UITableViewDataSource, UITableViewDelegate>
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (UIView * _Nullable)tableView:(UITableView * _Nonnull)tableView viewForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit25SelectVisitTypeController")
@interface SelectVisitTypeController : UIViewController
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC13VSeeClinicKit19SimpleDependantCell")
@interface SimpleDependantCell : DependantCell
@property (nonatomic, getter=isSelected) BOOL selected;
- (nonnull instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString * _Nullable)reuseIdentifier OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=3.0);
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit27SocialHistoryFormController")
@interface SocialHistoryFormController : EMRFormController
- (void)viewDidLoad;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit25StartSignUpViewController")
@interface StartSignUpViewController : SignUpFormViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface UIAlertController (SWIFT_EXTENSION(VSeeClinicKit))
+ (void)forceShowAppUpdateAlertWithVc:(UIViewController * _Nonnull)vc :(NSString * _Nonnull)appStoreId;
+ (UIAlertController * _Nonnull)forceAppUpdateAlert:(NSString * _Nonnull)appStoreId SWIFT_WARN_UNUSED_RESULT;
@end


@interface UIButton (SWIFT_EXTENSION(VSeeClinicKit))
- (void)applySubmitButtonTheme;
@end








@interface UINavigationController (SWIFT_EXTENSION(VSeeClinicKit))
- (void)applyNavigationControllerTheme;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit31UIStoryboardSegueWithCompletion")
@interface UIStoryboardSegueWithCompletion : UIStoryboardSegue
- (void)perform;
- (nonnull instancetype)initWithIdentifier:(NSString * _Nullable)identifier source:(UIViewController * _Nonnull)source destination:(UIViewController * _Nonnull)destination OBJC_DESIGNATED_INITIALIZER;
@end


@interface UITabBar (SWIFT_EXTENSION(VSeeClinicKit))
- (void)applyTabBarTheme;
@end












@interface UIView (SWIFT_EXTENSION(VSeeClinicKit))
@property (nonatomic, readonly, strong) UIColor * _Nonnull backgroundPrimaryColor;
@property (nonatomic, readonly, strong) UIColor * _Nonnull backgroundSecondaryColor;
@property (nonatomic, readonly, strong) UIColor * _Nonnull backgroundHighlightedColor;
@property (nonatomic, readonly, strong) UIColor * _Nonnull primaryColor;
@property (nonatomic, readonly, strong) UIColor * _Nonnull secondaryColor;
@property (nonatomic, readonly, strong) UIColor * _Nonnull highlightedColor;
@end


@interface UIViewController (SWIFT_EXTENSION(VSeeClinicKit))
- (void)promptCancelFlow:(id _Nonnull)sender;
@end


@interface UIViewController (SWIFT_EXTENSION(VSeeClinicKit))
- (void)showHelp;
@end


@interface UIViewController (SWIFT_EXTENSION(VSeeClinicKit))
+ (void)puPhotoPickerHostSwizzling;
@end

@class UIAlertAction;
@class AlertPopUpConfig;

@interface UIViewController (SWIFT_EXTENSION(VSeeClinicKit))
- (void)showMissingFieldsAlert;
- (void)showInvalidEmailAlert;
- (void)showGenericErrorAlertWithHandler:(void (^ _Nullable)(UIAlertAction * _Nonnull))handler;
- (void)showGenericNetWorkErrorAlertWithHandler:(void (^ _Nullable)(UIAlertAction * _Nonnull))handler;
- (void)showErrorAlert:(NSString * _Nullable)title message:(NSString * _Null_unspecified)message;
- (void)showDebugErrorAlert:(NSString * _Nullable)title message:(NSString * _Null_unspecified)message;
- (void)showErrorAlert:(NSString * _Nullable)title message:(NSString * _Null_unspecified)message handler:(void (^ _Nullable)(UIAlertAction * _Nonnull))handler;
- (void)showErrorAlert:(NSError * _Nullable)error;
- (void)showErrorAlert:(NSError * _Nullable)error handler:(void (^ _Nullable)(UIAlertAction * _Nonnull))handler;
- (void)showConfirmAlert:(NSString * _Nonnull)title message:(NSString * _Nonnull)message cancelTitle:(NSString * _Nonnull)cancelTitle confirmTitle:(NSString * _Nullable)confirmTitle confirmHandler:(void (^ _Nullable)(void))confirmHandler;
- (void)showErrorAlert:(NSString * _Nullable)title message:(NSString * _Nonnull)message forceRetry:(BOOL)forceRetry retry:(void (^ _Nonnull)(void))retry;
- (void)showErrorAlert:(NSError * _Nonnull)error forceRetry:(BOOL)forceRetry retry:(void (^ _Nonnull)(void))retry;
- (void)showNetworkFailureAlert:(NSError * _Nullable)error forceRetry:(BOOL)forceRetry retry:(void (^ _Nonnull)(void))retry;
- (void)showAlertWithConfig:(AlertPopUpConfig * _Nullable)config confirmHandler:(void (^ _Nullable)(void))confirmHandler;
- (void)hideKeyboardWhenTapped;
- (void)dismissKeyboard;
- (void)dismissToRootViewControllerAnimated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;
- (void)applyAlertControllerTheme;
@end


@interface NSUserDefaults (SWIFT_EXTENSION(VSeeClinicKit))
/// increasePhotoLocalId
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSInteger increasePhotoLocalId;)
+ (NSInteger)increasePhotoLocalId SWIFT_WARN_UNUSED_RESULT;
/// increaseCommentLocalId
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSInteger increaseCommentLocalId;)
+ (NSInteger)increaseCommentLocalId SWIFT_WARN_UNUSED_RESULT;
@end


@class UIScrollView;

@interface VCFormViewController (SWIFT_EXTENSION(VSeeClinicKit))
- (void)scrollViewDidScroll:(UIScrollView * _Nonnull)scrollView;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit24VCHelpFormViewController")
@interface VCHelpFormViewController : VCFormViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class Configuration;

SWIFT_CLASS("_TtC13VSeeClinicKit13VCImagePicker")
@interface VCImagePicker : ImagePickerController
- (nonnull instancetype)initWithConfiguration:(Configuration * _Nonnull)configuration OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit22VCNavigationController")
@interface VCNavigationController : VSeeNavigationController
- (void)viewDidLoad;
- (void)viewDidLayoutSubviews;
- (nonnull instancetype)initWithNavigationBarClass:(Class _Nullable)navigationBarClass toolbarClass:(Class _Nullable)toolbarClass OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=5.0);
- (nonnull instancetype)initWithRootViewController:(UIViewController * _Nonnull)rootViewController OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit21VCPagerViewController")
@interface VCPagerViewController : ButtonBarPagerTabStripViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIPickerView;

SWIFT_CLASS("_TtC13VSeeClinicKit22VCStateSelectTextField")
@interface VCStateSelectTextField : UITextField <UIPickerViewDataSource, UIPickerViewDelegate, UITextFieldDelegate>
- (void)awakeFromNib;
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView * _Nonnull)pickerView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)pickerView:(UIPickerView * _Nonnull)pickerView numberOfRowsInComponent:(NSInteger)component SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)pickerView:(UIPickerView * _Nonnull)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component SWIFT_WARN_UNUSED_RESULT;
- (void)pickerView:(UIPickerView * _Nonnull)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
- (void)textFieldDidBeginEditing:(UITextField * _Nonnull)textField;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit14VCSubmitButton")
@interface VCSubmitButton : UIButton
@property (nonatomic, getter=isEnabled) BOOL enabled;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit34VisitGuestSignInFormViewController")
@interface VisitGuestSignInFormViewController : VCFormViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit17WebViewController")
@interface WebViewController : UIViewController <WKNavigationDelegate>
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)viewDidLoad;
- (void)webView:(WKWebView * _Nonnull)webView didFinishNavigation:(WKNavigation * _Null_unspecified)navigation;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC13VSeeClinicKit13WhisperBridge")
@interface WhisperBridge : NSObject
+ (void)whisper:(NSString * _Nonnull)text backgroundColor:(UIColor * _Nonnull)backgroundColor toNavigationController:(UINavigationController * _Nonnull)toNavigationController silenceAfter:(NSTimeInterval)silenceAfter;
+ (void)shout:(NSString * _Nonnull)title subtitle:(NSString * _Nullable)subtitle image:(UIImage * _Nullable)image duration:(NSTimeInterval)duration target:(UIViewController * _Nonnull)target action:(void (^ _Nullable)(void))action;
+ (void)whistle:(NSString * _Nonnull)title backgroundColor:(UIColor * _Nonnull)backgroundColor titleColor:(UIColor * _Nonnull)titleColor;
+ (void)hideWhistle;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
