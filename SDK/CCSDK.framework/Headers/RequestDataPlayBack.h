//
//  RequestDataPlayBack.h
//  CCLivePlayDemo
//
//  Created by cc-mac on 15/11/10.
//  Copyright © 2015年 ma yige. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayParameter.h"
#import <WebKit/WebKit.h>
#import "CCLiveUtil.h"

#define SDKVersion @"4.1.0"
@protocol RequestDataPlayBackDelegate <NSObject>
@optional
/**
 *	@brief  获取文档内白板或者文档本身的宽高，来进行屏幕适配用的
 */
- (void)getDocAspectRatioOfWidth:(CGFloat)width height:(CGFloat)height;
/**
 *  @brief  获取ppt当前页数和总页数
 *
 *  回调当前翻页的页数信息
 *  白板docTotalPage一直为0, pageNum从1开始
 *  其他文档docTotalPage为正常页数,pageNum从0开始
 *  @param dictionary 翻页信息
 */
- (void)onPageChange:(NSDictionary *) dictionary;
/**
 *	@brief	收到本房间的历史提问&回答
 */
- (void)onParserQuestionArr:(NSArray *)questionArr onParserAnswerArr:(NSArray *)answerArr;
/**
 *	@brief	解析本房间的历史聊天数据
 */
- (void)onParserChat:(NSArray *)arr;
/**
 *  @brief  收到本房间历史广播
 *  content 广播内容
 *  time 发布时间(单位:秒)
 */
- (void)broadcastHistory_msg:(NSArray *)array;
/**
 *	@brief	请求回放地址失败
 */
-(void)requestFailed:(NSError *)error reason:(NSString *)reason;
/**
 *	@brief  登录成功
 */
- (void)loginSucceedPlayBack;
/**
 *	@brief  登录失败
 */
-(void)loginFailed:(NSError *)error reason:(NSString *)reason;
/**
 *	@brief  获取房间信息，主要是要获取直播间模版来类型，根据直播间模版类型来确定界面布局
 *	房间信息
 *
 *  3.16.0 新增
 *
 *  新增参数名称      类型              是否必须        示例
 *  recordInfo      NSDictionary    （非必须）       @{@"title":@"房间标题",@"description":@"简介信息"}
 *
 *	房间模版类型：[dic[@"templateType"] integerValue];
 *	模版类型为1: 聊天互动： 无 直播文档： 无 直播问答： 无
 *	模版类型为2: 聊天互动： 有 直播文档： 无 直播问答： 有
 *	模版类型为3: 聊天互动： 有 直播文档： 无 直播问答： 无
 *	模版类型为4: 聊天互动： 有 直播文档： 有 直播问答： 无
 *	模版类型为5: 聊天互动： 有 直播文档： 有 直播问答： 有
 *	模版类型为6: 聊天互动： 无 直播文档： 无 直播问答： 有
 */
-(void)roomInfo:(NSDictionary *)dic;
/**
 *  @brief 回放的开始时间和结束时间(The new method)
 */
-(void)liveInfo:(NSDictionary *)dic;
/**
 *  @brief  加载视频失败
 */
- (void)playback_loadVideoFail;
/**
 *  @brief  回放翻页数据列表
 */
- (void)pageChangeList:(NSMutableArray *)array;
/**
 *    @brief     双击ppt
 */
- (void)doubleCllickPPTView DEPRECATED_MSG_ATTRIBUTE("该方法已废弃");
/**
 *    @brief    服务器端给自己设置的信息
 *    viewerId 服务器端给自己设置的UserId
 *    groupId 分组id
 *    name 用户名
 */
-(void)setMyViewerInfo:(NSDictionary *) infoDic;
/**
 *    @brief    文档加载状态
 *    index
 *      0 文档组件初始化完成
 *      1 动画文档加载完成
 *      2 非动画翻页加载成功
 *      3 文档组件加载失败
 *      4 非动画翻页加载失败
 *      5 文档动画加载失败
 *      6 画板加载失败
 *      7 极速动画翻页加载成功
 *      8 极速动画翻页加载失败
 */
- (void)docLoadCompleteWithIndex:(NSInteger)index;
/**
 *    @brief    视频状态
 *    rseult    playing/paused/loading
 */
-(void)videoStateChangeWithString:(NSString *) result;
/**
 *    @brief    视频状态改变
 *    @param    state
 *              HDSMediaPlaybackStateStopped          播放停止
 *              HDSMediaPlaybackStatePlaying          开始播放
 *              HDSMediaPlaybackStatePaused           暂停播放
 *              HDSMediaPlaybackStateInterrupted      播放间断
 *              HDSMediaPlaybackStateSeekingForward   播放快进
 *              HDSMediaPlaybackStateSeekingBackward  播放后退
 */
- (void)HDSMediaPlayBackStateDidChange:(HDSMediaPlaybackState)state;
/**
 *    @brief    视频加载状态
 *    @param    state   播放状态
 *              HDSMediaLoadStateUnknown         未知状态
 *              HDSMediaLoadStatePlayable        视频未完成全部缓存，但已缓存的数据可以进行播放
 *              HDSMediaLoadStatePlaythroughOK   缓冲已经完成
 *              HDSMediaLoadStateStalled         缓冲已经开始
 */
- (void)HDSMediaLoadStateDidChange:(HDSMediaLoadState)state;
/**
 *    @brief    视频播放完成原因
 *    @param    reason  原因
 *              HDSMediaFinishReasonPlaybackEnded    自然播放结束
 *              HDSMediaFinishReasonUserExited       用户人为结束
 *              HDSMediaFinishReasonPlaybackError    发生错误崩溃结束
 */
- (void)HDSMediaPlayerPlaybackDidFinish:(HDSMediaFinishReason)reason;

/**
 *    @brief    播放器准备完成 (会多次回调)
 */
- (void)HDMediaPlaybackIsPreparedToPlayDidChange;

/**
 *    @brief    播放器时间
 *    @param    currentTime   当前时间
 *    @param    totalTime     总时间
 */
- (void)HDPlayerCurrentTime:(NSTimeInterval)currentTime totalTime:(NSTimeInterval)totalTime;
/**
 *    @brief    视频加载速度
 *    @param    speed   视频加载速度字符串
 */
- (void)onBufferSpeed:(NSString *)speed;
/**
 *    @brief    跑马灯信息,需要开启跑马灯功能且iOS 9.0以上
*/
-(void)receivedMarqueeInfo:(NSDictionary *)dic;

/**
 *    The New Method (3.13.0)
 *    @brief    是否开启音频模式
 *    @param    hasAudio   HAVE_AUDIO_LINE_TURE 有音频 HAVE_AUDIO_LINE_FALSE 无音频
 *
 *    触发回调条件 1.初始化SDK登录成功后
 */
- (void)HDAudioMode:(HAVE_AUDIO_LINE)hasAudio;
/**
 *    The New Method (3.13.0)
 *    @brief    房间所包含的清晰度 (会多次回调)
 *    @param    dict    清晰度数据
 *    清晰度数据  key(包含的键值)              type(数据类型)             description(描述)
 *              qualityList(清晰度列表)      array                     @[HDQualityModel(清晰度详情),HDQualityModel(清晰度详情)]
 *              currentQuality(当前清晰度)   object                    HDQualityModel(清晰度详情)
 *
 *    触发回调条件 1.初始化SDK登录成功后
 *               2.主动调用切换清晰度方法
 *               3.主动调用切换视频模式回调
 */
- (void)HDReceivedVideoQuality:(NSDictionary *)dict;
/**
 *    The New Method (3.13.0)
 *    @brief    房间包含的音视频线路 (会多次回调)
 *    @param    dict   线路数据
 *    线路数据   key(包含的键值)             type(数据类型)             description(描述)
 *              lineList(线路列表)         array                     @[@"line1",@"line2"]
 *              indexNum(当前线路下标)      integer                   0
 *
 *    触发回调条件 1.初始化SDK登录成功后
 *               2.主动调用切换清晰度方法
 *               3.主动调用切换线路方法
 *               4.主动调用切换音视频模式回调
 */
- (void)HDReceivedVideoAudioLines:(NSDictionary *)dict;
/**
 *    @brief    回放打点数据
 *    @param    dotList   打点信息
 *              @[HDReplayDotModel,HDReplayDotModel]
 */
- (void)HDReplayDotList:(NSArray *)dotList;
/**
 *    @brief    错误信息回调
 *    @param    error       错误描述
 *    @param    errorCode   错误码 (可选)
 */
- (void)HDRequestDataErrorWithDescription:(ERROR_REQUEST_TYPE)error errorCode:(NSString *)errorCode;
/**
 *    @brief    媒体准备完成
 */
- (void)mediaPrepared;
/**
 *    @brief    所有数据准备完成
 *
 *    数据准备完成后，才能主动获取全量数据
 *    获取全量聊天数据：- (void)fetchAllChat:(void (^)(NSArray * results))completion;
 *    获取全量问答数据：- (void)fetchAllQA:(void (^)(NSDictionary * results))completion;
 *    获取全量广播数据：- (void)fetchAllBroadcast:(void (^)(NSArray * results))completion;
 *    获取全量随堂测数据：- (void)fetchAllPractic:(void (^)(NSArray * results))completion;
 *    获取全量翻页数据：- (void)fetchAllPageChange:(void (^)(NSArray *results))completion;
 */
- (void)dataPrepared;

/// 试看时长
/// @param trialDuration 时长 trialDuration >= 1 代表有 试看时长 < 1 表示没有试看时长
- (void)onTrialDuration:(NSTimeInterval)trialDuration;

@end

@interface RequestDataPlayBack : NSObject

@property (weak,nonatomic) id<RequestDataPlayBackDelegate>  delegate;
/**
 *	@brief	登录房间
 *	@param 	parameter   配置参数信息
 *  必填参数 userId
 *  必填参数 roomId
 *  必填参数 viewerName
 *  必填参数 token
 *  非必填参数 security
 */
- (id)initLoginWithParameter:(PlayParameter *)parameter;

/// 初始化SDK
/// @param parameter 参数
/// @param succed 初始化成功回调
/// @param player 播放视图回调
/// @param failed 初始化失败回调
- (id)initSDKWithParameter:(PlayParameter *)parameter
                    succed:(initSuccedClosure)succed
                    player:(HDSPlayerViewClosure)player
                    failed:(initFailedClosure)failed;

/**
 *	@brief	销毁文档和视频，清除视频和文档的时候需要调用,推出播放页面的时候也需要调用
 */
- (void)requestCancel;

/**
 *	@brief  获取文档区域内白板或者文档本身的宽高比，返回值即为宽高比，做屏幕适配用
 */
- (CGFloat)getDocAspectRatio;

/**
 *	@brief  改变文档区域大小,主要用在文档生成后改变文档窗口的frame
 */
- (void)changeDocFrame:(CGRect) docFrame;
/**
 *    @brief  改变文档父窗口
 */
- (void)changeDocParent:(UIView *) docParent;
/**
 *	@brief  播放器暂停
 */
- (void)pausePlayer;
/**
 *	@brief  播放器播放
 */
- (void)startPlayer;
/**
 *	@brief  播放器关闭
 */
- (void)shutdownPlayer;
/**
 *	@brief  播放器停止
 */
- (void)stopPlayer;
/**
 *	@brief  从头重新播放
 */
- (void)replayPlayer;
/**
 *  @brief  重新加载(从当前时间继续播放)
 */
- (void)retryReplay;
/**
 *	@brief  播放器是否播放
 */
- (BOOL)isPlaying;
/**
 *    @brief   播放器当前播放时间
 */
- (NSTimeInterval)currentPlaybackTime;
/**
 *    @brief   设置播放器当前播放时间（用于拖拽进度条时掉用的）
 */
- (void)setCurrentPlaybackTime:(NSTimeInterval)time;
/**
 *    @brief  回放视频总时长
 */
- (NSTimeInterval)playerDuration;
/**
 *	@brief  设置后台是否可播放
 */
- (void)setpauseInBackGround:(BOOL)pauseInBackGround;

/**
 *  @brief  改变文档背景颜色
 
 @param hexColor 字符串,传颜色的HEXColor 如:#000000
 */
- (void)changeDocWebColor:(NSString *)hexColor;
/**
 *    The New Method (3.13.0)
 *    @brief    切换播放类型
 *    @param    mode   PLAY_MODE_TYEP_VIDEO 视频模式(默认)
 *                     PLAY_MODE_TYEP_AUDIO 音频模式(当前回放包含音频线路)
 *    @param    completion 切换结果
 *              { success 0 切换成功 -1切换失败 -2 切换频繁
 *                reason 错误原因 }
 *
 *    切换播放器类型 切换为音频,回调 - (void)HDReceivedVideoAudioLines:(NSDictionary *)dict;
 *                切换为视频,回调 - (void)HDReceivedVideoQuality:(NSDictionary *)dict;
 *                             - (void)HDReceivedVideoAudioLines:(NSDictionary *)dict;
 *
 */
- (void)changePlayMode:(PLAY_MODE_TYEP)mode completion:(void (^)(NSDictionary * results))completion;
/**
 *    The New Method (3.13.0)
 *    @brief    切换清晰度
 *    @param    quality   清晰度
 *    @param    completion 切换结果
 *              { success 0 切换成功 -1切换失败 -2 切换频繁
 *                reason 错误原因 }
 *
 *    切换清晰度回调 - (void)HDReceivedVideoQuality:(NSDictionary *)dict;
 *                - (void)HDReceivedVideoAudioLines:(NSDictionary *)dict;
 */
- (void)changeQuality:(NSString *)quality completion:(void (^)(NSDictionary * results))completion;
/**
 *    The New Method (3.13.0)
 *    @brief    切换线路
 *    @param    index   选择线路下标
 *    @param    completion 切换结果
 *              { success 0 切换成功 -1切换失败 -2 切换频繁
 *                reason 错误原因 }
 *
 *    切换线路回调方法 - (void)HDReceivedVideoAudioLines:(NSDictionary *)dict;
 */
- (void)changeLine:(NSInteger)index completion:(void (^)(NSDictionary * results))completion;

/**
 *    @brief    主动调用方法       用于调整PPT缩放模式
 *    @param    pptScalingMode   PPT缩放模式
 *                               1 = 拉伸填充:PPT内容全部展示在显示区域,会被拉伸或压缩,不会存在黑边
 *                               2 = 等比居中:PPT内容保持原始比例,适应窗口展示在显示区域,会存在黑边
 *                               3 = 等比填充:PPT内容保持原始比例,以横向或纵向适应显示区域,另一方向将会超出显示区域,超出部分会被裁减,不会存在黑边
 */
- (void)changeDocPPTScalingMode:(NSInteger)pptScalingMode;
/**
 *    @brief    重新获取 聊天 问答数据
 *    @return   操作状态
 *
 *    操作成功后会回调 - (void)onParserQuestionArr:(NSArray *)questionArr onParserAnswerArr:(NSArray *)answerArr;
 *                  - (void)onParserChat:(NSArray *)arr;
 *
 *    注:该api进行防重复请求数据限制，防止出现流量过度浪费
 *       如果未进行登录 那么调用无效
 */
- (HDOperationCallStatus)reloadMetaData;
/**
 *    @brief    重新获取 画笔
 *    @return   操作状态
 *
 *    注:如果获取过画笔数据 再次获取无效
 *       如果未登录进行调用 无效
 */
- (HDOperationCallStatus)reloadDraw;
/**
 *  重新加载文档
 */
- (void)docReload;
/**
 *    3.16.0 new
 *    @brief    获取全量聊天数据
 *    @param    completion   数据回调
 */
- (void)fetchAllChat:(void (^)(NSArray * results))completion;
/**
 *    3.16.0 new
 *    @brief    获取全量问答数据
 *    @param    completion   数据回调
 */
- (void)fetchAllQA:(void (^)(NSArray * results))completion;
/**
 *    3.16.2 new
 *    @brief    获取全量广播数据
 *    @param    completion   数据回调
 */
- (void)fetchAllBroadcast:(void (^)(NSArray * results))completion;
/**
 *    3.16.0 new
 *    @brief    获取全量随堂测数据
 *    @param    completion   数据回调
 */
- (void)fetchAllPractic:(void (^)(NSArray * results))completion;
/**
 *    3.16.0 new
 *    @brief    获取全量翻页数据
 *    @param    completion   数据回调
 */
- (void)fetchAllPageChange:(void (^)(NSArray *results))completion;


/// 获取流加载状态
- (HDSMediaLoadState)getMediaLoadStatus;

/// 获取流播放状态
- (HDSMediaPlaybackState)getMediaPlayStatus;

/// 获取播放速率
- (CGFloat)getMediaRate;

/// 设置播放速率
- (void)setMediaRate:(CGFloat)rate;

- (void)cancleTask;

@end
