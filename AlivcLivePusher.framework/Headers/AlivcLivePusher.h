//
//  AlivcLivePusher.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 17/7/13.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <UIKit/UIKit.h>
#import <ReplayKit/ReplayKit.h>
#import "AlivcLivePushConfig.h"
#import "AlivcLivePushStatsInfo.h"
#import "AlivcLivePushError.h"
#import "AlivcLivePushDef.h"

/// @note 阿里云直播推流SDK从4.4.2版本开始增加license管理，老版本升级到4.4.2及以后版本需要参照阿里云官网获取推流SDK license
///  其SDK接入流程变化：
///  1. 在Info.plist中配置licenseKey和licenseFile
///  2.调用[AlivcLiveBase registerSDK]注册推流SDK
///  3.监听onLicenceCheck回调，确保license校验通过
///  4.创建推流对象，开始直播推流
///  其相关文档参考https://help.aliyun.com/document_detail/431730.html、
///  https://help.aliyun.com/document_detail/94821.html、https://help.aliyun.com/document_detail/94828.html

/**
 错误回调, 网络回调, 状态回调, BGM回调, 滤镜回调
 */
@protocol AlivcLivePusherErrorDelegate,
AlivcLivePusherNetworkDelegate,
AlivcLivePusherInfoDelegate,
AlivcLivePusherBGMDelegate,
AlivcLivePusherCustomFilterDelegate,
AlivcLivePusherCustomDetectorDelegate,
AlivcLivePusherSnapshotDelegate,
AlivcLivePusherAudioSampleDelegate;



/**
 推流类
 */
@interface AlivcLivePusher : NSObject



/**
 显示调试悬浮窗
 * 注意 ：Debug悬浮窗会占用一定的系统资源，只可用于APP研发的Debug阶段，Release版本请勿调用此接口
 */
+ (void)showDebugView;



/**
 隐藏调试悬浮窗
 */
+ (void)hideDebugView;


/**
 init

 @param config 推流配置
 @return self:success  nil:failure
 */
- (instancetype)initWithConfig:(AlivcLivePushConfig *)config;


/**
 设置推流错误监听回调

 @param delegate AlivcLivePusherErrorDelegate
 */
- (void)setErrorDelegate:(id<AlivcLivePusherErrorDelegate>)delegate;


/**
 设置推流状态监听回调

 @param delegate AlivcLivePusherInfoDelegate
 */
- (void)setInfoDelegate:(id<AlivcLivePusherInfoDelegate>)delegate;


/**
 设置推流网络监听回调

 @param delegate AlivcLivePusherNetworkDelegate
 */
- (void)setNetworkDelegate:(id<AlivcLivePusherNetworkDelegate>)delegate;

/**
 设置用户自定义滤镜回调
 
 @param delegate AlivcLivePusherCustomFilterDelegate
 */
- (void)setCustomFilterDelegate:(id<AlivcLivePusherCustomFilterDelegate>)delegate;


/**
 设置用户自定义人脸识别回调
 
 @param delegate AlivcLivePusherCustomDetectorDelegate
 */
- (void)setCustomDetectorDelegate:(id<AlivcLivePusherCustomDetectorDelegate>)delegate;

/**
 设置背景音乐监听回调

 @param delegate AlivcLivePusherBGMDelegate
 */
- (void)setBGMDelegate:(id<AlivcLivePusherBGMDelegate>)delegate;

/**
  设置音频裸数据回调
     
   @param delegate AlivcLivePusherAudioSampleDelegate
 */
- (void)setAudioSampleDelegate:(id<AlivcLivePusherAudioSampleDelegate>)delegate;


/**
 开始预览 同步接口

 @param previewView 预览view
 @return 0:success  非0:failure
 */
- (int)startPreview:(UIView *)previewView;


/**
 停止预览

 @return 0:success  非0:failure
 */
- (int)stopPreview;


/**
 开始推流 同步接口

 @param pushURL 推流URL
 @return 0:success  非0:failure
 */
- (int)startPushWithURL:(NSString *)pushURL;


/**
 停止推流
 
 @return 0:success  非0:failure
 */
- (int)stopPush;


/**
 重新推流 同步接口

 @return 0:success  非0:failure
 */
- (int)restartPush;


/**
 暂停推流
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下暂停推流，AlivcLivePushInteractiveMode模式下暂时不支持暂停推流
 @return 0:success  非0:failure
 */
- (int)pause;



/**
 恢复推流 同步接口
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下恢复推流接口，AlivcLivePushInteractiveMode模式下暂时不支持恢复推流接口
 @return 0:success  非0:failure
 */
- (int)resume;


/**
 重连 异步接口

 @return 0:success  非0:failure
 */
- (int)reconnectPushAsync;

/**
 重连 异步接口
 
 @return 0:success  非0:failure
 */
- (int)reconnectPushAsync:(NSString *)pushURL;

/**
 销毁推流
 */
- (void)destory;



/* ***********************异步接口*********************** */
/**
 开始预览 异步接口
 
 @param preview 预览view
 @return 0:success  非0:failure
 */
- (int)startPreviewAsync:(UIView *)preview;


/**
 开始推流 异步接口
 
 @param pushURL 推流URL
 @return 0:success  非0:failure
 */
- (int)startPushWithURLAsync:(NSString *)pushURL;


/**
 重新推流 异步接口
 
 @return 0:success  非0:failure
 */
- (int)restartPushAsync;


/**
 恢复推流 异步接口
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下恢复推流，AlivcLivePushInteractiveMode模式下暂时不支持恢复推流
 @return 0:success  非0:failure
 */
- (int)resumeAsync;

/* ****************************************************** */



/**
 旋转摄像头
 
 @return 0:success  非0:failure
 */
- (int)switchCamera;


/**
 设置自动对焦
 
 @param autoFocus true:自动对焦 false:手动对焦
 @return 0:success  非0:failure
 */
- (int)setAutoFocus:(bool)autoFocus;


/**
 对焦
 
 @param point 对焦的点
 @param autoFocus 是否自动对焦
 @return 0:success  非0:failure
 */
- (int)focusCameraAtAdjustedPoint:(CGPoint)point autoFocus:(bool)autoFocus;


/**
 缩放
 
 @param zoom 缩放值[0:MaxZoom]
 @return 0:success  非0:failure
 */
- (int)setZoom:(float)zoom;


/**
 获取支持的最大变焦值
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下获取支持的最大变焦值，AlivcLivePushInteractiveMode模式下暂时不支持获取支持的最大变焦值
 @return 最大变焦值
 */
- (float)getMaxZoom;


/**
 获取当前变焦值
 
 @return 当前变焦值
 */
- (float)getCurrentZoom;


/**
 闪光灯开关
 
 @param flash true:打开闪光灯 false:关闭闪光灯
 @return 0:success  非0:failure
 */
- (int)setFlash:(bool)flash;


/**
 设置曝光度
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下设置曝光度，AlivcLivePushInteractiveMode模式下暂时不支持设置曝光度
 @param exposure 曝光度
 @return 0:success  非0:failure
 */
- (int)setExposure:(float)exposure;


/**
 获取当前曝光度
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下获取当前曝光度，AlivcLivePushInteractiveMode模式下暂时不支持获取当前曝光度
 @return  曝光度
 */
- (float)getCurrentExposure;

/**
 获取支持最小曝光度
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下获取支持最小曝光度，AlivcLivePushInteractiveMode模式下暂时不支持获取支持最小曝光度
 @return  最小曝光度
 */
- (float)getSupportedMinExposure;

/**
 获取支持最大曝光度
 @note 当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下获取支持最大曝光度，AlivcLivePushInteractiveMode模式下暂时不支持获取支持最大曝光度
 @return  最大曝光度
 */
- (float)getSupportedMaxExposure;


/**
 推流镜像开关
 
 @param mirror true:打开推流镜像 false:关闭推流镜像
 */
- (void)setPushMirror:(bool)mirror;


/**
 预览镜像开关
 
 @param mirror true:打开预览镜像 false:关闭预览镜像
 */
- (void)setPreviewMirror:(bool)mirror;


/**
 静音推流
 
 @param mute true:静音推流 false:正常推流
 */
- (void)setMute:(bool)mute;


/**
 设置推流模式

 @param qualityMode 推流模式 : 选择 ResolutionFirst 模式时，SDK内部会优先保障推流视频的清晰度; 选择 FluencyFirst 模式时，SDK内部会优先保障推流视频的流畅度，此接口只支持这两种模式。设置后码率设置失效。
 @return 0:success  非0:failure
 */
- (int)setQualityMode:(AlivcLivePushQualityMode)qualityMode;


/**
 设置目标码率

 @param targetBitrate 目标码率 [100  5000](Kbps)
 @return 0:success  非0:failure
 */
- (int)setTargetVideoBitrate:(int)targetBitrate;


/**
 设置最小码率

 @param minBitrate 最小码率 [100  5000](Kbps)
 @return 0:success  非0:failure
 */
- (int)setMinVideoBitrate:(int)minBitrate;

/**
 设置预览显示模式

 @param displayMode 预览显示模式
 */
- (void)setpreviewDisplayMode:(AlivcPusherPreviewDisplayMode)displayMode;


/**
 设置推流分辨率，只在预览模式下生效，推流中不能设置
 
 @param resolution 推流分辨率
 */
- (void)setResolution:(AlivcLivePushResolution)resolution;



/* ***********************背景音乐*********************** */

/**
 播放背景音乐

 @param path 背景音乐路径
 @return 0:success  非0:failure
 */
- (int)startBGMWithMusicPathAsync:(NSString *)path;


/**
 停止播放背景音乐

 @return 0:success  非0:failure
 */
- (int)stopBGMAsync;


/**
 暂停播放背景音乐

 @return 0:success  非0:failure
 */
- (int)pauseBGM;


/**
 恢复播放背景音乐

 @return 0:success  非0:failure
 */
- (int)resumeBGM;


/**
 设置背景音乐是否循环播放

 @param isLoop 是否循环  true:循环 false:不循环
 @return 0:success  非0:failure
 */
- (int)setBGMLoop:(bool)isLoop;


/**
 设置背景音乐耳返开关

 @param isOpen 是否打开耳返  true:开启耳返 false:关闭耳返
 @return 0:success  非0:failure
 */
- (int)setBGMEarsBack:(bool)isOpen;


/**
 设置降噪开关
 
 @param isOpen 是否打开降噪 true:开启 false:关闭 默认:true
 @return 0:success  非0:failure
 */
- (int)setAudioDenoise:(bool)isOpen;


/**
 设置背景音乐混音 音乐音量

 @param volume 音乐音量大小 范围:[0 ~ 100] 默认:50
 @return 0:success  非0:failure
 */
- (int)setBGMVolume:(int)volume;


/**
 设置背景音乐混音 人声音量

 @param volume 人声音量大小 范围:[0 ~ 100] 默认:50
 @return 0:success  非0:failure
 */
- (int)setCaptureVolume:(int)volume;

/* **********************开启屏幕分享******************************** */

/**
 开始屏幕分享（该接口支持 iOS 11.0 及以上的 iPhone 和 iPad）。

 @note 该接口开始 iOS 系统的屏幕分享，可以实现录屏推流功能
      该接口配合AlivcLibReplayKitExt.framework使用，在Extension进程中添加AlivcLibReplayKitExt.framework库完成屏幕采集和发送
      在Host APP中接收音视频数据，完成推流。
 
 @param appGroup App group ID 主 App 与 Extension 共享的 Application Group Identifier，当前接口仅支持主 App 与 Extension 属于同一个App     Group的情况，如果不存在App Group， 不可调用该接口。
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下开始屏幕分享（录屏推流），AlivcLivePushInteractiveMode模式下暂时不支持开始屏幕分享（录屏推流）
 */
- (int)startScreenCapture:(NSString *)appGroup;

/* ***********************外部数据*********************** */

/**
 发送自定义video SampleBuffer

 @param sampleBuffer video sample buffer
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义video SampleBuffer，AlivcLivePushInteractiveMode模式下暂时不支持发送自定义video SampleBuffer
 */
- (void)sendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 发送自定义的audio SampleBuffer
 只限于replaykit录屏直播使用
 
 @param sampleBuffer audio sample buffer
 @param sampleBufferType audio sample buffer type
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义的audio SampleBuffer，AlivcLivePushInteractiveMode模式下暂时不支持发送自定义的audio SampleBuffer
 */
- (void)sendAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

/**
 发送自定义视频数据
 
 @param data 视频数据
 @param width 视频宽度
 @param height 视频高度
 @param size 数据大小
 @param pts 时间戳（单位微秒）
 @param rotation 旋转
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义视频数据，AlivcLivePushInteractiveMode模式下暂时不支持发送自定义视频数据
 */
- (void)sendVideoData:(char *)data width:(int)width height:(int)height size:(int)size pts:(uint64_t)pts rotation:(int)rotation;

/**
 发送自定义音频数据
 
 @param data 音频数据
 @param size 数据大小
 @param sampleRate 采样率
 @param channel 声道数
 @param pts 时间戳（单位微秒）
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下发送自定义音频数据，AlivcLivePushInteractiveMode模式下暂时不支持发送自定义音频数据
 */
- (void)sendPCMData:(char *)data size:(int)size sampleRate:(int)sampleRate channel:(int)channel pts:(uint64_t)pts;

/**
 添加视频混流设置
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加视频混流设置，AlivcLivePushInteractiveMode模式下暂时不支持添加视频混流设置
 */
- (int)addMixVideo:(int)format width:(int)width height:(int)height rotation:(int)rotation displayX:(float)displayX displayY:(float)displayY displayW:(float)displayW displayH:(float)displayH adjustHeight:(bool)adjustHeight;

/**
 改变视频混流位置
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下改变视频混流位置，AlivcLivePushInteractiveMode模式下暂时不支持改变视频混流位置
 */
- (void)changeMixVideoPosition:(int)handler displayX:(float)displayX displayY:(float)displayY displayW:(float)displayW displayH:(float)displayH;

/**
 改变视频混流镜像
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下改变视频混流镜像，AlivcLivePushInteractiveMode模式下暂时不支持改变视频混流镜像
 */
- (void)setMixVideoMirror:(int)handler isMirror:(BOOL)isMirror;

/**
 输入视频混流数据
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下输入视频混流数据，AlivcLivePushInteractiveMode模式下暂时不支持输入视频混流数据
 */
- (void)inputMixVideoData:(int)handler data:(long)dataptr width:(int)width height:(int)height stride:(int)stride size:(int)size pts:(long)pts rotation:(int)rotation;

/**
 移除视频混流
 */
- (void)removeMixVideo:(int) handler;

/**
 添加音频混流设置
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加音频混流，AlivcLivePushInteractiveMode模式下暂时不支持添加音频混流
 */
- (int)addMixAudio:(int)channels format:(int)format audioSample:(int)audioSample;

/**
 输入音频混流数据
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下输入音频混流数据，AlivcLivePushInteractiveMode模式下暂时不支持输入音频混流数据
 */
- (bool)inputMixAudioData:(int)handler data:(long)dataptr size:(int)size pts:(long)pts;

/**
 移除音频混流
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下移除音频混流，AlivcLivePushInteractiveMode模式下暂时不支持移除音频混流
 */
- (void)removeMixAudio:(int)handler;

/* ****************************************************** */

/**
 设置Message
 
 @param msg 用户推流消息
 @param count 重复次数
 @param time 延时时间，单位毫秒
 @param isKeyFrame 是否只发关键帧
 @return 0:success  非0:failure
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下设置Message，AlivcLivePushInteractiveMode模式下暂时不支持设置Message
 */
- (int)sendMessage:(NSString *)msg repeatCount:(int)count delayTime:(int)time KeyFrameOnly:(bool)isKeyFrame;


/**
 获取是否正在推流

 @return YES:正在推流 NO:未推流
 */
- (BOOL)isPushing;


/**
 获取当前推流URL

 @return 推流URL
 */
- (NSString *)getPushURL;

/**
 获取当前推流状态
 
 @return 推流状态
 */
- (AlivcLivePushStatus)getLiveStatus;

/**
 获取推流数据统计

 @return 推流数据
 */
- (AlivcLivePushStatsInfo *)getLivePushStatusInfo;


/**
 设置Log级别

 @param level Log级别 default:AlivcLivePushLogLevelError
 @return 0:success  非0:failure
 */
- (int)setLogLevel:(AlivcLivePushLogLevel)level __deprecated_msg("Use AlivcLiveBase->setLogLevel instead.");

/**
 设置Log路径

 @param logPath Log路径
 @param maxPartFileSizeInKB 每个分片最大大小。最终日志总体积是 5*最大分片大小
 @return 0:success  非0:failure
 */
- (int)setLogPath:(NSString *)logPath maxPartFileSizeInKB:(int)maxPartFileSizeInKB __deprecated_msg("Use AlivcLiveBase->setLogPath:maxPartFileSizeInKB instead.");

/**
 获取SDK版本号

 @return 版本号
 */
+ (NSString *)getSDKVersion __deprecated_msg("Use AlivcLiveBase->getSDKVersion instead.");

/**
 添加水印 最多支持3个水印

 @param path 水印路径
 @param coordX 水印左上顶点x的相对坐标 [0,1]
 @param coordY 水印左上顶点y的相对坐标 [0,1]
 @param width 水印的相对宽度 (水印会根据水印图片实际大小和水印宽度等比缩放) (0,1]
 @return 0:success  非0:failure
 注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加水印，AlivcLivePushInteractiveMode模式下暂时不支持添加水印
 */
- (int)addWatermarkWithPath:(NSString *)path
             watermarkCoordX:(CGFloat)coordX
             watermarkCoordY:(CGFloat)coordY
              watermarkWidth:(CGFloat)width;

/**
 设置水印显示和隐藏
 
 @param visable true:显示水印，false:隐藏水印
 */
- (void)setWatermarkVisible:(bool) visable;

/**
  添加动态贴纸,最多支持添加5个贴纸
  waterMarkDirPath：贴纸图片sequence目录
  x,y：显示屏幕位置（0~1.0f)
  w,h：显示屏幕长宽（0~1.0f)
  注：当前SDK暂时只支持在livePushMode = AlivcLivePushBasicMode 模式下添加动态贴纸，AlivcLivePushInteractiveMode模式下暂时不支持添加动态贴纸
  @return 返回动态贴纸的id号，删除贴纸传此id
 **/
- (int)addDynamicWaterMarkImageDataWithPath:(NSString *)waterMarkDirPath x:(float)x y:(float)y w:(float)w h: (float)h;

/**
 删除动态贴纸
 vid:贴纸id，add时返回的
 
 **/
- (void)removeDynamicWaterMark:(int)vid;

/**
 截图
 count:张数
 interval:每张间隔(ms)
 **/
- (void)snapshot:(int)count interval:(int)interval;


/**
 设置截图回调
 **/
- (void)setSnapshotDelegate:(id<AlivcLivePusherSnapshotDelegate>)delegate;

/* **********************互动模式下特定API******************************** */
// 以下API是只在livePushMode为AlivcLivePushInteractiveMode，即只在直播SDK工作在互动模式下才可以使用
// 非互动模式调用以下API将无任何效果，特定API包括：
// setLiveMixTranscodingConfig

/**
 设置云端的混流（转码）参数
 一个直播间中可能有不止一位主播，而且每个主播都有自己的画面和声音，但对于 CDN 观众来说，他们只需要一路直播流
 所以您需要将多路音视频流混成一路标准的直播流，这就需要混流转码
 在连麦场景下，需要将主播和连麦观众音视频流混成一路标准的直播流，供CDN观众观看
 在PK场景下，需要将进行PK的多个主播的音视频流混成一路标准的直播流，供CDN观众观看
 @param config 参考AlivcLiveDef.h中关于AlivcLiveTranscodingConfig的介绍，如果传入nil，则取消云端混流转码
 @note 若主播还在房间中但不再需要混流，请务必传入 nil 进行取消，因为当发起混流后，云端混流模块就会开始工作，
 不及时取消混流可能会引起不必要的计费损失
 */
- (int)setLiveMixTranscodingConfig:(AlivcLiveTranscodingConfig *)config;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      美颜相关api，在v4.2.0版本已删除，推流SDK不再提供内置美颜功能，请使用阿里云Queen提供的美颜服务
//      详见：https://help.aliyun.com/document_detail/211047.html?spm=a2c4g.11174283.6.736.79c5454ek41M8B
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@end

@protocol AlivcLivePusherErrorDelegate <NSObject>

@required

/**
 系统错误回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onSystemError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 SDK错误回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onSDKError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;

@end



@protocol AlivcLivePusherNetworkDelegate <NSObject>

@required

/**
 网络差回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onNetworkPoor:(AlivcLivePusher *)pusher;


/**
 推流链接失败

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onConnectFail:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 网络恢复

 @param pusher 推流AlivcLivePusher
 */
- (void)onConnectRecovery:(AlivcLivePusher *)pusher;


/**
 重连开始回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onReconnectStart:(AlivcLivePusher *)pusher;


/**
 重连成功回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onReconnectSuccess:(AlivcLivePusher *)pusher;

/**
 连接被断开
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onConnectionLost:(AlivcLivePusher *)pusher;


/**
 重连失败回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onReconnectError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 发送数据超时
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onSendDataTimeout:(AlivcLivePusher *)pusher;


/**
 推流URL的鉴权时长即将过期(将在过期前1min内发送此回调)

 @param pusher 推流AlivcLivePusher
 @return 新的推流URL
 */
- (NSString *)onPushURLAuthenticationOverdue:(AlivcLivePusher *)pusher;


/**
 发送SEI Message 通知
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onSendSeiMessage:(AlivcLivePusher *)pusher;

@optional

/**
 网络原因导致音视频丢包
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPacketsLost:(AlivcLivePusher *)pusher;


@end




@protocol AlivcLivePusherInfoDelegate <NSObject>

@optional


- (void)onPreviewStarted:(AlivcLivePusher *)pusher;



/**
 停止预览回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onPreviewStoped:(AlivcLivePusher *)pusher;


/**
 渲染第一帧回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onFirstFramePreviewed:(AlivcLivePusher *)pusher;


/**
 推流开始回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushStarted:(AlivcLivePusher *)pusher;


/**
 推流暂停回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushPaused:(AlivcLivePusher *)pusher;


/**
 推流恢复回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushResumed:(AlivcLivePusher *)pusher;


/**
 重新推流回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onPushRestart:(AlivcLivePusher *)pusher;


/**
 推流停止回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushStoped:(AlivcLivePusher *)pusher;

/**
 * 直播推流器统计数据回调（每2秒回调一次）
 *
 * @param pusher 推流AlivcLivePusher
 * @param statistics 推流器统计数据
 */
- (void)onPushStatistics:(AlivcLivePusher *)pusher statsInfo:(AlivcLivePushStatsInfo*)statistics;

/**
 * 设置云端的混流（转码）参数回调，对应于setLiveMixTranscodingConfig接口
 * @param isSuccess YES表示成功，NO表示失败
 * @param msg 具体错误原因
 */
- (void)onSetLiveMixTranscodingConfig:(AlivcLivePusher *)pusher status:(BOOL)isSuccess message:(NSString *)msg;
@end


@protocol AlivcLivePusherBGMDelegate <NSObject>

@required

/**
 背景音乐开始播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onStarted:(AlivcLivePusher *)pusher;


/**
 背景音乐停止播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onStoped:(AlivcLivePusher *)pusher;


/**
 背景音乐暂停播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onPaused:(AlivcLivePusher *)pusher;


/**
 背景音乐恢复播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onResumed:(AlivcLivePusher *)pusher;


/**
 背景音乐当前播放进度

 @param pusher 推流AlivcLivePusher
 @param progress 播放时长
 @param duration 总时长
 */
- (void)onProgress:(AlivcLivePusher *)pusher progress:(long)progress duration:(long)duration;


/**
 背景音乐播放完毕

 @param pusher 推流AlivcLivePusher
 */
- (void)onCompleted:(AlivcLivePusher *)pusher;


/**
 背景音乐开启失败

 @param pusher 推流AlivcLivePusher
 */
- (void)onOpenFailed:(AlivcLivePusher *)pusher;


/**
 背景音乐下载播放超时

 @param pusher 推流AlivcLivePusher
 */
- (void)onDownloadTimeout:(AlivcLivePusher *)pusher;


@end
@protocol AlivcLivePusherCustomFilterDelegate <NSObject>
@required
/**
 通知外置滤镜创建回调
 */
- (void)onCreate:(AlivcLivePusher *)pusher context:(void*)context;
/**
 通知外置滤镜处理回调，当前版本SDK在非互动模式下需要使用onProcess处理美颜
 */
- (int)onProcess:(AlivcLivePusher *)pusher texture:(int)texture textureWidth:(int)width textureHeight:(int)height extra:(long)extra;
/**
 通知外置滤镜处理回调，当前版本SDK在互动模式下需要使用onProcessVideoSampleBuffer处理美颜
 - YES: 需要写回SDK
 - NO: 不需要写回SDK
 */
- (BOOL)onProcessVideoSampleBuffer:(AlivcLivePusher *)pusher sampleBuffer:(AlivcLiveVideoDataSample *)sampleBuffer;

/**
 通知外置滤镜销毁回调
 */
- (void)onDestory:(AlivcLivePusher *)pusher;

@end

@protocol AlivcLivePusherCustomDetectorDelegate <NSObject>

@required
/**
 通知外置识别器创建回调
 */
- (void)onCreateDetector:(AlivcLivePusher *)pusher;

/**
 通知外置识别器处理回调
 */
- (long)onDetectorProcess:(AlivcLivePusher *)pusher data:(long)data w:(int)w h:(int)h rotation:(int)rotation format:(int)format extra:(long)extra;

/**
 通知外置识别器销毁回调
 */
- (void)onDestoryDetector:(AlivcLivePusher *)pusher;

@end

@protocol AlivcLivePusherSnapshotDelegate <NSObject>

@required

/**
 截图回调
 
 @param pusher 推流AlivcLivePusher
 @param image 截图
 @param error error
 */
- (void)onSnapshot:(AlivcLivePusher *)pusher image:(UIImage *)image;
@end

@protocol AlivcLivePusherAudioSampleDelegate <NSObject>
/**
 设备采集的原始音频数据，支持修改
 */

- (void)onAudioSampleCallback:(AlivcLivePusher *)pusher audioSample:(AlivcLivePusherAudioDataSample*)audioSample;

@end
