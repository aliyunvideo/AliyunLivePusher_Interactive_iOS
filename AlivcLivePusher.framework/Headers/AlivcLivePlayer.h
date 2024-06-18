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
 *  @ingroup live
 *  直播连麦播放功能的主要接口类
 *  @{
 */

/****
 * @defgroup AlivcLivePlayer Live interaction player engine
 * @ingroup live
 *  The main interface class of the live interaction  player function
 *  @{
 */

/**
 * @brief 互动直播模式下拉流类，暂只支持互动模式下的拉流URL
 * @attention 当前API只能用于拉取实时互动流（RTC流）；如果拉取普通直播CDN流（旁路直播流），请使用标准协议的播放器
 * @see <a href="https://help.aliyun.com/zh/live/developer-reference/push-sdk/">推流SDK文档</a>
 * @see <a href="https://help.aliyun.com/zh/live/user-guide/co-streaming/">直播连麦文档</a>
 * @see <a href="https://help.aliyun.com/zh/live/developer-reference/integrate-a-push-sdk-license">推流SDK License文档</a>
 */

/****
 * @brief The class for stream pulling in interactive mode. Only source URLs in interactive mode are supported
 * @attention The current API can only be used to pull real-time interactive streams (RTC streams); If pulling a regular live CDN stream (bypass live stream), please use a standard protocol player
 * @see <a href="https://help.aliyun.com/zh/live/developer-reference/push-sdk/">推流SDK文档</a>
 * @see <a href="https://help.aliyun.com/zh/live/user-guide/co-streaming/">直播连麦文档</a>
 * @see <a href="https://help.aliyun.com/zh/live/developer-reference/integrate-a-push-sdk-license">推流SDK License文档</a>

 */
@interface AlivcLivePlayer : NSObject

/**
 * @brief 设置播放回调 {@link AliLivePlayerDelegate}
 * @param delegate 播放回调
 */

/****
 * @brief Set the callback for playback {@link AliLivePlayerDelegate}
 * @param delegate callback
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

/****
 * @brief Set the playback view. (This method is supported only in interactive mode.)
 * @details This method is used to set the playback control of remote streams in interaction scenarios such as interactive and battle.
 * In co-streaming scenarios, the streamer sets the playback view of the video for viewers by using the setPlayView method,
 * and the viewers set the playback view of the streamer by using the setPlayView method.
 * In battle scenarios, streamer A and streamer B who start a battle call setPlayView to set the playback view of the other streamer.
 * @param view view
 * @param playConfig play configuration {@link AlivcLivePlayConfig}
 * @return
 *  0:success
 *  != 0:failure
 */
- (int)setPlayView:(UIView *)view  playCofig:(AlivcLivePlayConfig *)playConfig;

/**
 * @brief 更新远端用户的视频渲染控件
 * @details 该接口用于设置互动场景下(连麦或者PK)场景下更新远端流的渲染控件
 * 可能的使用场景是先调用setPlayView来设置一个播放view，后面需要更新该流的渲染控件
 * @param view 视频显示view
 */

/****
 * @brief Update video rendering controls for end users
 * @details This method is used to set the playback control of remote streams in interaction scenarios such as interactive and battle.
 * A possible usage scenario is to first call setPlayView to set a playback view, and later need to update the rendering control of the stream.
 * @param view view
 */
- (void)updateRenderView:(UIView *)view;


/**
 * @brief 更新播放配置信息
 * @param playConfig 播放配置信息 {@link AlivcLivePlayConfig}
 */

/****
 * @brief Update play configuration
 * @param playConfig play configuration {@link AlivcLivePlayConfig}
 */
- (void)updatePlayConfig:(AlivcLivePlayConfig *)playConfig;
/**
 * @brief 开始播放音视频流（当前接口只在互动模式下生效）
 * @details 该接口用于互动场景下(连麦或者PK)场景下播放连麦观众或者PK主播的音视频流
 * 在连麦场景下，主播通过startPlayWithURL接口播放连麦观众实时音视频流，连麦观众通过startPlayWithURL播放主播实时音视频流
 * 在PK场景下，主播A和主播B PK,主播A和主播B分别调用startPlayWithURL来播放要PK的另一个主播的音视频流
 * @note 停止播放，对应接口： AlivcLivePlayer::stopPlay
 * @note 该接口对应回调： AliLivePlayerDelegate::onPlayStarted:
 * @param url 主播或连麦观众的拉流(播放)地址
 */

/****
 * @brief Start playing audio and video streams. (This method is supported only in interactive mode.)
 * @details This method is used to play the audio and video streams of the co-streamer or battling streamer in interaction scenarios (interactive and battle).
 * In co-streaming scenarios, the streamer plays the audio and video streams of the interactive by using the startPlayWithURL method,
 * and the co-streamer plays the audio and video streams of the streamer by using the startPlayWithURL method.
 * In battle scenarios, streamer A and streamer B who start a battle call startPlayWithURL to play the audio and video streams of the other streamer.
 * @note stopPlay, corresponding to the interface: AlivcLivePlayer::stopPlay
 * @note This interface corresponds to the callback: AliLivePlayerDelegate::onPlayStarted:
 * @param url The streaming URL of the streamer or co-streamer.
 */
- (void)startPlayWithURL:(NSString *)url;

/**
 * @brief 停止播放音视频流（当前接口只在互动模式下生效）
 * @details 该接口和startPlayWithURL接口相对应
 * @note 该接口对应回调： AliLivePlayerDelegate::onPlayStopped:
 */

/****
 * @brief Stop playing audio and video streams. (This method is supported only in interactive mode.)
 * @details This method corresponds to the startPlayWithURL method.
 * @note This interface corresponds to the callback: AliLivePlayerDelegate::onPlayStopped:
 */
- (void)stopPlay;

/**
 * @brief 暂停播放音频流(静音)
 * * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Pause playback of an audio stream(audio mute).
 */
- (int)pauseAudioPlaying;

/**
 * @brief 恢复播放音频流(取消静音)
 * * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Resume playback of an audio stream(audio unmute).
 */
- (int)resumeAudioPlaying;

/**
 * @brief 暂停播放视频流
 * * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Pause playback of a video stream.
 */
- (int)pauseVideoPlaying;

/**
 * @brief 恢复播放视频流
 * * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief Resume playback of a video stream.
 */
- (int)resumeVideoPlaying;

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

/****
 * @brief Set the playback volume.
 * @param volume playback volume，value range [0,400]
 * - 0：muted
 * - <100：Decrease the volume
 * - >100：Increase the volume
 * @return
 * - 0: success
 * - !=0: failure
 */
- (int)setPlayoutVolume:(NSInteger)volume;

/**
 * @brief  截取播放过程中的视频画面
 * * @return
 * - 0: 成功
 * - 非0: 失败
 */

/****
 * @brief snapshot the video screen during playback
 */
- (int)snapshot:(AlivcLivePlayVideoStreamType)videoStreamType;

/**
 * @brief  获取当前播放成员的UserId
 */

/****
 * @brief Get the UserId of the currently playing member
 */
@property (nonatomic, copy, readonly) NSString *userId;

@end

/** @} */

/**** @} */

/**
 * @defgroup AliLivePlayerDelegate 直播连麦播放回调
 * @ingroup live
 *  直播连麦播放回调
 *  @{
 */

/****
 * @defgroup AliLivePlayerDelegate Live interaction player engine callbacks
 * @ingroup live
 *  Live interaction player engine callbacks
 *  @{
 */

/**
 * @brief 直播连麦播放回调
 */

/****
 * @brief Live interaction player engine callbacks
 */
@protocol AliLivePlayerDelegate <NSObject>

@optional

/**
 * @brief 播放错误回调
 * @param player 连麦播放引擎对象
 * @param code 错误码 {@link AlivcLivePlayerError }
 * @param msg 错误信息
 */

/****
 * @brief The callback for playback errors
 * @param player  Live interaction player engine object
 * @param code errorCode {@link AlivcLivePlayerError }
 * @param msg error msg
 */
- (void)onError:(AlivcLivePlayer *)player code:(AlivcLivePlayerError)code message:(NSString *)msg;

/**
 * @brief 开始播放回调，表示播放音视频成功
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for playback start
 * @param player Live interaction player engine object
 */
- (void)onPlayStarted:(AlivcLivePlayer *)player;

/**
 * @brief 结束播放回调
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for playback end
 * @param player Live interaction player engine object
 */
- (void)onPlayStoped:(AlivcLivePlayer *)player;

/**
 * @brief 音频流订阅情况变更回调
 * @param player 连麦播放引擎对象
 * @param oldState 之前的订阅状态，详见  AliLiveSubscribeState
 * @param newState 当前的订阅状态，详见 AliLiveSubscribeState
 */

/****
 * @brief Audio stream subscription change callback
 * @param player Live interaction player engine object
 * @param oldState Previous subscription status, see AliLiveSubscribeState for details
 * @param newState Current subscription status, see AliLiveSubscribeState for details
 */
- (void)onAudioSubscribeStateChanged:(AlivcLivePlayer *)player oldState:(AliLiveSubscribeState)oldState newState:(AliLiveSubscribeState)newState;

/**
 * @brief 相机流订阅情况变更回调
 * @param player 连麦播放引擎对象
 * @param oldState 之前的订阅状态，详见  AliLiveSubscribeState
 * @param newState 当前的订阅状态，详见 AliLiveSubscribeState
 */

/****
 * @brief Camera stream subscription change callback
 * @param player Live interaction player engine object
 * @param oldState Previous subscription status, see AliLiveSubscribeState for details
 * @param newState Current subscription status, see AliLiveSubscribeState for details
 */
- (void)onVideoSubscribeStateChanged:(AlivcLivePlayer *)player oldState:(AliLiveSubscribeState)oldState newState:(AliLiveSubscribeState)newState;

/**
 * @brief 屏幕分享流订阅情况变更回调
 * @param player 连麦播放引擎对象
 * @param oldState 之前的订阅状态，详见  AliLiveSubscribeState
 * @param newState 当前的订阅状态，详见 AliLiveSubscribeState
 */

/****
 * @brief Screen stream subscription change callback
 * @param player Live interaction player engine object
 * @param oldState Previous subscription status, see AliLiveSubscribeState for details
 * @param newState Current subscription status, see AliLiveSubscribeState for details
 */
- (void)onScreenShareSubscribeStateChanged:(AlivcLivePlayer *)player oldState:(AliLiveSubscribeState)oldState newState:(AliLiveSubscribeState)newState;

/**
 * @brief 音频首包接收回调
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for first audio frame received.
 * @param player Live interaction player engine object
 */
- (void)onFirstAudioFrameReceived:(AlivcLivePlayer*)player;

/**
 * @brief 已解码远端音频首帧回调
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for first audio frame received.
 * @param player Live interaction player engine object
 */
- (void)onFirstAudioFrameDecoded:(AlivcLivePlayer*)player;

/**
 * @brief 视频首包接收回调
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for first video frame received.
 * @param player Live interaction player engine object
 */
- (void)onFirstVideoFrameReceived:(AlivcLivePlayer*)player;

/**
 * @brief 视频首帧渲染回调
 * @param player 连麦播放引擎对象
 */

/****
 * @brief The callback for first frame rendering.
 * @param player Live interaction player engine object
 */
- (void)onFirstVideoFrameDrawn:(AlivcLivePlayer*)player;
/**
 * @brief 网络质量变化时发出的消息
 * @param player 连麦播放引擎对象
 * @param upQuality  上行网络质量
 * @param downQuality 下行网络质量
 * @note 当对端网络质量发生变化时触发
 */

/****
 * @brief The message that is sent when the network quality changes.
 * @param player Live interaction player engine object
 * @param upQuality  up network quality
 * @param downQuality down network quality
 * @note Triggered when peer network quality changes.
 */
- (void)onNetworkQualityChanged:(AlivcLivePlayer*)player upNetworkQuality:(AlivcLiveNetworkQuality)upQuality downNetworkQuality:(AlivcLiveNetworkQuality)downQuality;

/**
 * @brief 播放统计数据回调
 * @param player 连麦播放引擎对象
 * @param statistics 统计数据
 * @note statistics中的videoBitrate是总的视频接收码率
 */

/****
 * @brief The callback for playback statistics.
 * @param player Live interaction player engine object
 * @param statistics statistics
 * @note videoBitrate in statistics is the total video receiving bit rate
 */
- (void)onPlayerStatistics:(AlivcLivePlayer *)player statsInfo:(AlivcLivePlayerStatsInfo*)statistics;


/**
 * @brief SEI回调
 * @param player 连麦播放引擎对象
 * @param payloadType 类型
 * @param data 数据
 */

/****
 * @brief SEI callback
 * @param player Live interaction player engine object
 * @param payloadType Type
 * @param data Data
 */
- (void)onReceiveSeiMessage:(AlivcLivePlayer *)player payloadType:(int)payloadType data:(NSData *)data;


/**
 * @brief 播放音量和是否正在说话的反馈回调
 * @param player 连麦播放引擎对象
 * @param volume 音量大小
 * @param isSpeaking 是否正在说话
 */

/****
 * @brief  callback for playback volume and whether is speaking
 * @param player player Live interaction player engine object
 * @param volume volume
 * @param isSpeaking is speaking
 */
- (void)onPlayoutVolumeUpdate:(AlivcLivePlayer *)player volume:(int)volume speechState:(BOOL)isSpeaking;

/**
 * @brief 截图回调
 * @param player 连麦播放引擎对象
 * @param image 截图
 */

/****
 * @brief Snapshot callbacks
 * @param player player Live interaction player engine object
 * @param image snap image
 */
- (void)onSnapshot:(AlivcLivePlayer *)player image:(UIImage *)image;

/**
 * @brief 播放器分辨率变化通知
 *
 * @param player 连麦播放引擎对象
 * @param width     视频宽。
 * @param height    视频高。
 */

/****
 * @brief video resolution change notification
 *
 * @param player Live interaction player engine object
 * @param width     video width
 * @param height    video height
 */
- (void)onVideoResolutionChanged:(AlivcLivePlayer *)player width:(int)width height:(int)height;

/**
 * @brief 静音/取消静音回调
 *
 * @param player 连麦播放引擎对象
 * @param isMute 是否静音
 * - YES: 静音
 * - NO: 取消静音
 */

/****
 * @brief  mute/unmute callback
 *
 * @param player Live interaction player engine object
 * @param isMute
 * - YES: mute
 * - NO: unmute
 */
- (void)onAudioMuted:(AlivcLivePlayer *)player muted:(BOOL)isMute;

/**
 * @brief 对端用户打开/关闭视频通知(调用了AlivcLivePusher->muteLocalCamera)
 *
 * @param player 连麦播放引擎对象
 * @param isMute
 * - YES: 关闭视频
 * - NO: 打开视频
 */

/****
 * @brief Turn video notifications on/off
 *
 * @param player Live interaction player engine object
 * @param isMute
 * - YES: Close video
 * - NO: Open video
 */
- (void)onVideoMuted:(AlivcLivePlayer *)player muted:(BOOL)isMute;

/**
 * @brief 对端用户关闭相机流采集发送通知(调用了AlivcLivePusher->enableLocalCamera)
 * @param player 连麦播放引擎对象
 * @param isEnable
 * - YES: 打开相机流采集
 * - NO: 关闭相机流采集
 * @note 该接口用于对端用户关闭相机流采集时的回调
 */

/****
 * @brief The peer user closes camera capture and sends notification (AlivcLivePusher->enableLocalCamera is called)
 * @param player Live interaction player engine object
 * @param isEnable
 * - YES: open camera
 * - NO: close camera
 * @note This interface is used to call back when the peer user closes camera capture .
 */
- (void)onVideoEnabled:(AlivcLivePlayer *)player enabled:(BOOL)isEnable;

/**
 * @brief 远端用户离开
 * @param player 连麦播放引擎对象
 * @param reason 用户离线的原因，详见AliLiveUserOfflineReason
 * @note 当前SDK内部在收到远端用户离开消息后，会自动调用AlivcLivePlayer->stopPlay来结束播放，但是在某些特殊场景，不希望SDK内部自动调用结束播放，可以
 *  在AlivcLivePlayConfig中设置autoStoppedPlayWhenUserLeaved为false，SDK内部收到远端用户离开消息后不再自动调用结束播放，需要业务层自行调用stopPlay。
 */

/**
 * @brief Remote user leaves
 * @param player Live interaction player engine object
 * @param reason The reason why the user is offline, see AliLiveUserOfflineReason for details
 * @note After receiving the message that the remote user has left, the current SDK will automatically call AlivcLivePlayer->stopPlay to end playback. However, in some special scenarios, if you do not want the SDK to automatically call to end playback, you can set autoStoppedPlayWhenUserLeaved to false in AlivcLivePlayConfig, SDK After receiving the remote user leave message internally, it will no longer automatically call to end playback. The business layer needs to call stopPlay by itself.
 */
- (void)onRemoteUserLeave:(AlivcLivePlayer *)player leaveReason:(AliLiveUserOfflineReason)reason;

/**
 * @brief DataChannel自定义消息回调
 * @param player 连麦播放引擎对象
 * @param data 数据
 */

/****
 * @brief Data channel message callback
 * @param player Live interaction player engine object
 * @param data Data
 */
- (void)onReceiveDataChannelMessage:(AlivcLivePlayer *)player data:(NSData *)data;

 /**
  * @brief 远端视频数据回调
  * @param player 连麦播放引擎对象
  * @param videoSample 视频裸数据
  * @return
  * - YES: 需要写回SDK
  * - NO: 不需要写回SDK
  * @note 默认不回调，需要通过AlivcLivePushConfig.enableRemoteVideoFrameObserver开启，开启后，可回调远端视频裸数据
 */

 /****
  * @brief Remote video data callback
  * @param player Live interaction player engine object
  * @param videoSample video raw data
  * @return
  * - YES: Need to write back to SDK
  * - NO: No need to write back to SDK
  * @note There is no callback by default. It needs to be enabled through AlivcLivePushConfig.enableRemoteVideoFrameObserver. After it is enabled, the remote video raw data can be called back.
 */
 - (BOOL)onRemoteVideoSample:(AlivcLivePlayer *)player videoSample:(AlivcLiveVideoDataSample *_Nonnull)videoSample;


 /**
  * @brief 远端拉流数据回调
  * @details 默认关闭，需要通过enableAudioFrameObserver : YES audioSource: AliLiveAudioSourceRemoteUser 开启
  *
  *  - 该接口支持设置采样率、声道数
  *  - 该接口支持读写模式
  *
  * @param pusher 推流引擎对象
  * @param audioSample 音频数据sample, {@link AlivcLivePusherAudioDataSample}
  * @note 请不要在此回调函数中做任何耗时操作，否则可能导致声音异常
  */

 /****
  * @brief The remote original audio data  callback
  * @details It is turned off by default and needs to be turned on by enableAudioFrameObserver: YES audioSource: AliLiveAudioSourceRemoteUser
  *  - This interface supports setting the sampling rate and number of channels
  *  - This interface supports read and write modes
  * @param pusher The live pusher engine object
  * @param audioSample audio sample data {@link AlivcLivePusherAudioDataSample}
  * @note Please do not do any time-consuming operations in this callback function, otherwise it may cause abnormal sound
  */
 - (void)onRemoteAudioSampleCallback:(AlivcLivePlayer *)player audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

@end

/** @} */

/**** @} */
