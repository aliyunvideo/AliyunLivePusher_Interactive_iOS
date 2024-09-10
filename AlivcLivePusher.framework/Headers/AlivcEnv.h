//
// Created by Geeker Aven on 2024/4/15.
//
#import <Foundation/Foundation.h>


OBJC_EXPORT
@interface AlivcEnv : NSObject

/**
 * @brief 环境定义
 *  ENV_GLOBAL_DEFAULT 全球环境，寻找最佳环境
 *  ENV_CN 中国大陆
 *  ENV_SEA 东南亚
 */
/**
 * Env define
 * ENV_GLOBAL_DEFAULT : Global environment, looking for the best environment
 * ENV_CN : Chinese mainland.
 *  ENV_SEA : Southeast Asia
 */
typedef NS_ENUM(NSInteger, AlivcGlobalEnv) {
    AlivcGlobalEnv_GLOBAL_DEFAULT = 0,
    AlivcGlobalEnv_CN,
    AlivcGlobalEnv_SEA
};

/**
     * @brief 设置特定功能选项
     * @param key 选项key
     * @param value 选项的值
     * @return true:成功 false：失败
     */
    /****
     * @brief Set specific option
     * @param key key option
     * @param value value of key
     * @return true false
     */
- (BOOL) setOption:(NSString *)key value:(NSString *)value;

/**
 * 全球环境
 */
/****
 * GlobalEnv
 */
- (BOOL) setGlobalEnvironment:(AlivcGlobalEnv)env;

- (AlivcGlobalEnv) globalEnvironment;

+ (instancetype)getInstance;

@end
