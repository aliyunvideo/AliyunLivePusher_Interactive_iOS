//
//  AlivcLivePlayer.h
//  AlivcLivePusher
//
//  Created by aliyun on 2022/8/22.
//  Copyright © 2022 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AlivcLivePushDef.h"


@protocol AliLivePlayerDelegate;
/**
 * @defgroup AlivcLivePlayer 直播连麦播放引擎
 *  直播连麦播放功能的主要接口类
 *  @{
 */

/**
 * @brief 互动直播模式下拉流类，暂只支持互动模式下的拉流URL
 */
@interface AlivcLivePlayer : NSObject

/**
 * @brief 设置播放回调 {@link AliLivePlayerDelegate}
 * @param delegate 播放回调
 */
- (void)setLivePlayerDelegate:(id<AliLivePlayerDelegate>)delegate;

/**
 * @brief 设置播放View （当前接口只在互动模式下生效）
 * @details 该接口用于设置互动场景下(连麦或者PK)场景下设置远端流的播放控件
 * 在连麦场景下，主播通过setPlayView接口设置连麦观众视频的播放view，连麦观众通过setPlayView接口设置主播的视频播放view
 * 在PK场景下，主播A和主播B PK,主播A和主播B分别调用setPlayView设置要PK的另一个主播的视频播放view
 * @param view 视频显示view
 * @param playConfig 播放配置信息 {@link AlivcLivePlayConfig}
 * @return 0:success  非0:failure
 */
- (int)setPlayView:(UIView *)view  playCofig:(AlivcLivePlayConfig *)playConfig;

/**
 * @brief 开始播放音视频流（当前接口只在互动模式下生效）
 * @details 该接口用于互动场景下(连麦或者PK)场景下播放连麦观众或者PK主播的音视频流
 * 在连麦场景下，主播通过startPlayWithURL接口播放连麦观众实时音视频流，连麦观众通过startPlayWithURL播放主播实时音视频流
 * 在PK场景下，主播A和主播B PK,主播A和主播B分别调用startPlayWithURL来播放要PK的另一个主播的音视频流
 * @param url 主播或连麦观众的拉流(播放)地址
 */
- (void)startPlayWithURL:(NSString *)url;

/**
 * @brief 停止播放音视频流（当前接口只在互动模式下生效）
 * @details 该接口和startPlayWithURL接口相对应
 */
- (void)stopPlay;

/**
 * @brief 暂停播放音频流
 */
- (void)pauseAudioPlaying;

/**
 * @brief 恢复播放音频流
 */
- (void)resumeAudioPlaying;

/**
 * @brief 暂停播放视频流
 */
- (void)pauseVideoPlaying;

/**
 * @brief 恢复播放视频流
 */
- (void)resumeVideoPlaying;

/**
 * @brief 设置播放音量
 * @param volume 播放音量，取值范围[0,400]
 * - 0：静音
 * - <100：减小音量
 * - >100：放大音量
 * @return
 * - 0: 成功
 * - 非0: 失败
 */
- (int)setPlayoutVolume:(NSInteger)volume;

@end

/** @} */

/**
 * @defgroup AliLivePlayerDelegate 直播连麦播放回调
 *  直播连麦播放回调
 *  @{
 */
@protocol AliLivePlayerDelegate <NSObject>

@optional

/**
 * @brief 播放错误回调
 * @param player 连麦播放引擎对象
 * @param code 错误码 {@link AlivcLivePlayerError }
 * @param msg 错误信息
 */
- (void)onError:(AlivcLivePlayer *)player code:(AlivcLivePlayerError)code message:(NSString *)msg;

/**
 * @brief 开始播放回调
 * @param player 连麦播放引擎对象
 */
- (void)onPlayStarted:(AlivcLivePlayer *)player;

/**
 * @brief 结束播放回调
 * @param player 连麦播放引擎对象
 */
- (void)onPlayStoped:(AlivcLivePlayer *)player;

/**
 * @brief 视频首帧渲染回调
 * @param player 连麦播放引擎对象
 */
- (void)onFirstVideoFrameDrawn:(AlivcLivePlayer*)player;
/**
 * @brief 网络质量变化时发出的消息
 * @param player 连麦播放引擎对象
 * @param quality  网络质量
 * @note 当对端网络质量发生变化时触发
 */
- (void)onNetworkQualityChanged:(AlivcLivePlayer*)player quality: (AlivcLiveNetworkQuality)quality;

/**
 * @brief 播放统计数据回调
 * @param player 连麦播放引擎对象
 * @param statistics 统计数据
 * @note statistics中的videoBitrate是总的视频接收码率
 */
- (void)onPlayerStatistics:(AlivcLivePlayer *)player statsInfo:(AlivcLivePlayerStatsInfo*)statistics;

@end

/** @} */
