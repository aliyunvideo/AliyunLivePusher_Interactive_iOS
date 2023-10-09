//
//  AliVCSDKInfo.h
//  AliVCSDK
//
//  Created by mengyehao on 2022/6/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliVCSDKInfo : NSObject

/**
 获取版本号

 @return 版本号
 */
/****
 Gets the SDK version.

 @return The SDK version.
 */
+ (NSString *)version;


/**
获取sdk 构建id
版本build相关，开发者无需关心
@return alivc commit id
*/
/****
Gets the alivc commit id.

@return The alivc commit id.
*/
+ (NSString *)buildId;


/**
获取sdk commit id
版本build相关，开发者无需关心
@return sdk commit id
*/
/****
Gets the SDK commit id.

@return The SDK commit id.
*/
+ (NSString *)commitId;

/**
获取sdk 所有组件名
版本build相关，开发者无需关心
@return 组件名
*/
/****
Gets the SDK commit id.

@return The SDK commit id.
*/
+ (NSString *)componentName;

/**
获取sdk 所有组件ID
版本build相关，开发者无需关心
@return 组件id
*/
/****
Gets the SDK commit id.

@return The SDK commit id.
*/
+ (NSString *)componentId;



@end

NS_ASSUME_NONNULL_END
