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
 互动直播模式下拉流类，暂只支持互动模式下的拉流URL
 */
@interface AlivcLivePlayer : NSObject

/**
 设置播放回调
 @param delegate 播放回调
 */
- (void)setLivePlayerDelegate:(id<AliLivePlayerDelegate>)delegate;

/**
 设置播放View （当前接口只在互动模式下生效）
 该接口用于设置互动场景下(连麦或者PK)场景下设置远端流的播放控件
 在连麦场景下，主播通过setPlayView接口设置连麦观众视频的播放view，连麦观众通过setPlayView接口设置主播的视频播放view
 在PK场景下，主播A和主播B PK,主播A和主播B分别调用setPlayView设置要PK的另一个主播的视频播放view
 @param view 视频显示view
 @param playConfig 播放配置信息
 */
- (int)setPlayView:(UIView *)view  playCofig:(AlivcLivePlayConfig *)playConfig;

/**
 开始播放音视频流（当前接口只在互动模式下生效）
 该接口用于互动场景下(连麦或者PK)场景下播放连麦观众或者PK主播的音视频流
 在连麦场景下，主播通过startPlayWithURL接口播放连麦观众实时音视频流，连麦观众通过startPlayWithURL播放主播实时音视频流
 在PK场景下，主播A和主播B PK,主播A和主播B分别调用startPlayWithURL来播放要PK的另一个主播的音视频流
 @param url 主播或连麦观众的拉流(播放)地址
 */
- (void)startPlayWithURL:(NSString *)url;

/**
 停止播放音视频流（当前接口只在互动模式下生效）
 该接口和startPlayWithURL接口相对应
 */
- (void)stopPlay;

/**
 暂停播放音频流
 */
- (void)pauseAudioPlaying;

/**
 恢复播放音频流
 */
- (void)resumeAudioPlaying;

/**
 暂停播放视频流
 */
- (void)pauseVideoPlaying;

/**
 恢复播放视频流
 */
- (void)resumeVideoPlaying;

/**
  设置播放音量
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

@protocol AliLivePlayerDelegate <NSObject>

@optional

- (void)onError:(AlivcLivePlayer *)player code:(AlivcLivePlayerError)code message:(NSString *)msg;

/**
 开始播放回调
 */
- (void)onPlayStarted:(AlivcLivePlayer *)player;

/**
 结束播放回调
 */
- (void)onPlayStoped:(AlivcLivePlayer *)player;

/**
 视频播放事件
 */
- (void)onFirstVideoFrameDrawn:(AlivcLivePlayer*)player;


@end
