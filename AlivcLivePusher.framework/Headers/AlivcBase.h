//
// Created by Pi on 2023/06/07.
//

#import <Foundation/Foundation.h>

/**
 * 一体化基础接口
 */
/****
 * BaseAPI for AIO
 */
OBJC_EXPORT
@interface AlivcBase : NSObject

/**
 * SDK版本号
 */
/****
 * SDK VERSION
 */
@property (nonatomic, class, readonly) NSString *SDKVersion;

/**
 * SDK构建ID
 */
/****
 * SDK BuildId
 */
@property (nonatomic, class, readonly) NSString *SDKBuildId;

/**
 * SDK构建时间
 */
/****
 * SDK Build Time
 */
@property (nonatomic, class, readonly) NSString *SDKBuildTime;

/**
 * 集成方式
 */
/****
 * The integration way
 */
@property (nonatomic, class) NSString *IntegrationWay;

/**
 * 埋点开关
 */
/****
 * The switch of stat
 */
@property (nonatomic, class) BOOL EnabledStat;
@end
