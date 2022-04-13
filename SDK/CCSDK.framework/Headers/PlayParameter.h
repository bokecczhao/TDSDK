//
//  Parameter.h
//  CCLivePlayDemo
//
//  Created by cc on 2017/3/9.
//  Copyright © 2017年 ma yige. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PlayParameter : NSObject
/**
 *  @brief 用户ID
 */
@property(nonatomic, copy)NSString                      *userId;//用户ID
/**
 *  @brief 用户ID
 */
@property(nonatomic, copy)NSString                      *roomId;//用户ID
/**
 *  @brief 用户名称
 */
@property(nonatomic, copy)NSString                      *viewerName;//用户名称
/**
 *  @brief 房间密码
 */
@property(nonatomic, copy)NSString                      *token;//房间密码
/**
 *  @brief 回放ID
 */
@property(nonatomic, copy)NSString                      *recordId;//回放ID
/**
 *  @brief 用户自定义参数，需和后台协商，没有定制传@"" 长度不能超过40个字符
 */
@property(nonatomic, copy)NSString                      *viewerCustomua;//用户自定义参数，需和后台协商，没有定制传@""
/**
 * json格式字符串，可选，自定义用户信息，该信息会记录在用户访问记录中，用于统计分析使用（长度不能超过200个字符，若直播间启用接口验证则该参数无效）如果不需要的话就不要传值
 * 格式如下：
 * viewercustominfo: '{"exportInfos": [ {"key": "城市", "value": "北京"}, {"key": "姓名", "value": "哈哈"}]}'
 */
@property(nonatomic, copy)NSString                      *viewercustominfo;
/**
 *  @brief 下载文件解压到的目录路径(离线下载相关)
 */
@property(nonatomic, copy)NSString                      *destination;//下载文件解压到的目录路径(离线下载相关)
/**
 *  @brief 文档父类窗口
 */
@property(nonatomic,strong)UIView                       *docParent;//文档父类窗口
/**
 *  @brief 文档区域
 */
@property(nonatomic,assign)CGRect                       docFrame;//文档区域
/**
 *  @brief 屏幕适配方式
 * 0:HDSMediaScalingModeNone
 * 1:HDSMediaScalingModeAspectFit
 * 2:HDSMediaScalingModeAspectFill
 * 3:HDSMediaScalingModeFill
 */
@property(assign, nonatomic)NSInteger                   scalingMode;//屏幕适配方式，含义见上面
/**
 *  @brief ppt默认底色，不写默认为白色
 */
@property(nonatomic, copy)  NSString                     *defaultColor;//ppt默认底色，不写默认为白色(@"#FFFFFF")
/**
 *  @brief /后台是否继续播放，注意：如果开启后台播放需要打开 xcode->Capabilities->Background Modes->on->Audio,AirPlay,and Picture in Picture
 */
@property(nonatomic,assign)BOOL                         pauseInBackGround;//后台是否继续播放，注意：如果开启后台播放需要打开 xcode->Capabilities->Background Modes->on->Audio,AirPlay,and Picture in Picture
/**
 *  @brief PPT适配模式分为四种
 *    PPT适配模式分为四种，
 *    1.拉伸填充，PPT内容全部展示在显示区域，会被拉伸或压缩，不会存在黑边
 *    2.等比居中，PPT内容保持原始比例,适应窗口展示在显示区域,会存在黑边
 *    3.等比填充，PPT内容保持原始比例,以横向或纵向适应显示区域,另一方向将会超出显示区域,超出部分会被裁减,不会存在黑边
 *    4.根据直播间文档显示模式的返回值进行设置（推荐）
 */
@property(assign, nonatomic)NSInteger                   PPTScalingMode;//PPT适配方式，含义见上面
/**
 *  @brief PPT是否允许滚动(The New Method)
 */
@property(nonatomic, assign)BOOL                        pptInteractionEnabled;
/**
 *  @brief 设置当前的文档模式，
 * 1.切换至跟随模式（默认值）值为0，
 * 2.切换至自由模式；值为1，
 */
@property(assign, nonatomic)NSInteger                   DocModeType;//设置当前的文档模式
/**
 *  @brief 聊天分组id
 *         使用聊天分组功能时传入,不使用可以不传
 */
@property(copy, nonatomic)NSString                   *groupid;
/**
 *  @brief 是否禁用视频,默认为NO,禁用视频则只播放音频 (在线回放专用)
 *         只有账号开启支持音频模式设置才生效,可以在初始化SDK的时候配置,也可以在切换线路调用(changeLineWithPlayParameter)的时候配置
 */
@property(assign, nonatomic)BOOL                        disableVideo;
/**
 *  @brief 切换线路
 *         在切换线路调用(changeLineWithPlayParameter)的时候配置
*/
@property(assign, nonatomic)NSInteger                   lineNum;//线路
/**
 *  抽奖2.0 抽奖去重, 默认开启YES.(不开启时(NO),收到同一重复抽奖,代理方法会响应多次)
 */
@property(assign, nonatomic)BOOL                        LotteryRepetition;

@property(nonatomic, assign)int                         tpl;

/**
 *  视频播放状态
 *  HDSMediaPlaybackStateStopped          播放停止
 *  HDSMediaPlaybackStatePlaying          开始播放
 *  HDSMediaPlaybackStatePaused           暂停播放
 *  HDSMediaPlaybackStateInterrupted      播放间断
 *  HDSMediaPlaybackStateSeekingForward   播放快进
 *  HDSMediaPlaybackStateSeekingBackward  播放后退
 */
typedef NS_ENUM(NSUInteger, HDSMediaPlaybackState) {
    HDSMediaPlaybackStateStopped,
    HDSMediaPlaybackStatePlaying,
    HDSMediaPlaybackStatePaused,
    HDSMediaPlaybackStateInterrupted,
    HDSMediaPlaybackStateSeekingForward,
    HDSMediaPlaybackStateSeekingBackward,
};

/**
 *  视频加载状态
 *  HDSMediaLoadStateUnknown         未知状态
 *  HDSMediaLoadStatePlayable        视频未完成全部缓存，但已缓存的数据可以进行播放
 *  HDSMediaLoadStatePlaythroughOK   缓冲已经完成
 *  HDSMediaLoadStateStalled         缓冲已经开始
 */
typedef NS_ENUM(NSUInteger, HDSMediaLoadState) {
    HDSMediaLoadStateUnknown,
    HDSMediaLoadStatePlayable,
    HDSMediaLoadStatePlaythroughOK,
    HDSMediaLoadStateStalled,
};

/**
 *  视频播放完成原因
 *  HDSMediaFinishReasonPlaybackEnded    自然播放结束
 *  HDSMediaFinishReasonUserExited       用户人为结束
 *  HDSMediaFinishReasonPlaybackError    发生错误崩溃结束
 */
typedef NS_ENUM(NSUInteger, HDSMediaFinishReason) {
    HDSMediaFinishReasonPlaybackEnded,
    HDSMediaFinishReasonUserExited,
    HDSMediaFinishReasonPlaybackError,
};



@end


@interface RemindModel :NSObject

/**
 *  用户进出通知
 *  HDUSER_IN_REMIND      进入直播间
 *  HDUSER_OUT_REMIND     退出直播间
 */
typedef NS_ENUM(NSUInteger, HDUSER_REMIND) {
    HDUSER_IN_REMIND,//进入直播间
    HDUSER_OUT_REMIND,//退出直播间
};

/** 用户id */
@property (nonatomic, copy) NSString    *userId;
/** 昵称 */
@property (nonatomic, copy) NSString    *userName;
/** 角色 */
@property (nonatomic, copy) NSString    *userRole;
/** 头像 */
@property (nonatomic, copy) NSString    *userAvatar;
/** 分组id */
@property (nonatomic, copy) NSString    *groupId;
/** 接收端   1-讲师；2-助教；3-主持人；4-观看端 */
@property (nonatomic, strong) NSArray   *clientType;
/** 用户进出通知 */
@property (nonatomic, assign) HDUSER_REMIND remindType;
/** 发送内容前缀 */
@property (nonatomic, copy) NSString    *prefixContent;
/** 发送内容后缀 */
@property (nonatomic, copy) NSString    *suffixContent;



@end


@interface BanChatModel : NSObject

/** 用户id */
@property (nonatomic, copy) NSString    *userId;
/** 昵称 */
@property (nonatomic, copy) NSString    *userName;
/** 角色 */
@property (nonatomic, copy) NSString    *userRole;
/** 头像 */
@property (nonatomic, copy) NSString    *userAvatar;
/** 分组id */
@property (nonatomic, copy) NSString    *groupId;


@end


@interface NewLotteryMessageModel : NSObject

/**
 *  抽奖2.0 抽奖消息类别
 *  NEW_LOTTERY_NULL       无抽奖
 *  NEW_LOTTERY_BEGIN      开始抽奖
 *  NEW_LOTTERY_CANCEL     取消抽奖
 *  NEW_LOTTERY_COMPLETE   抽奖结束
 *  NEW_LOTTERY_EXIT       抽奖异常
 *  
 */
typedef NS_ENUM(NSUInteger, NEW_LOTTERY) {
    NEW_LOTTERY_NULL,//无抽奖
    NEW_LOTTERY_BEGIN,//开始抽奖
    NEW_LOTTERY_CANCEL,//取消抽奖
    NEW_LOTTERY_COMPLETE,//抽奖结束
    NEW_LOTTERY_EXIT,//抽奖异常
};
/** 抽奖类型 */
@property (nonatomic, assign) NEW_LOTTERY type;
/** 当前是否有抽奖 */
@property (nonatomic, assign) BOOL haveLottery;
/**
 * 抽奖信息 infos
 * infos 包含的字段:  注:字段对应的值可能为空
 * lotteryStatus    (NSInteger      必须)     抽奖状态: 0抽奖创建成功， 1抽奖取消成功， 2抽奖已完成， 3抽奖异常结束
 * lotteryId        (NSString       必须)     抽奖ID
 * collectTemplate  (NSArray        必须)     用户信息模板 例:@[@{@"index":index序号,@"title":提示,@"tips":@"提示"}]
 * isWinner         (BOOL           必须)     是否中奖
 * ownUserInfo      (NSDictionary   必须)     中奖者信息 例:@{@"userAvatar":头像,@"userName":用户名,@"userId":用户id,@"prizeCode":中奖码}
 * prize            (NSDictionary   必须)     奖品信息 例:@{@"name":奖品名字}
 * userInfos        (NSArray        必须)     中奖名单 例:@[@{@"userAvatar":头像,@"userName":用户名,@"userId":用户id,@"prizeCode":中奖码}]
 */
@property (nonnull, strong) NSDictionary *infos;

@end

@interface LineModel : NSObject //（已废弃）

/** 清晰度 0-原画；200-流畅；300-标清； */
@property (nonatomic, copy)   NSArray      * _Nonnull quality;
/** 视频线路数 */
@property (nonatomic, assign) NSInteger               videoLine;
/** 音频线路数 */
@property (nonatomic, assign) NSInteger               audioLine;

@end

@interface PlayBackLineModel : NSObject //（已废弃）

/** 清晰度 @[@{@"quality":@"0",@"desp":@"清晰度"},@{@"quality":@"1",@"desp":@"清晰度"}] */
@property (nonatomic, copy)   NSArray      * _Nonnull qualityArray;
/** 视频线路数 */
@property (nonatomic, assign) NSInteger               videoLine;
/** 音频线路数 */
@property (nonatomic, assign) NSInteger               audioLine;

@end

/**
 *  音视频模式
 *  PLAY_MODE_TYEP_VIDEO       视频
 *  PLAY_MODE_TYEP_AUDIO       音频
 */
typedef NS_ENUM(NSUInteger, PLAY_MODE_TYEP) {
    PLAY_MODE_TYEP_VIDEO,//视频
    PLAY_MODE_TYEP_AUDIO,//音频
};
/**
 *    是否有音频线路
 *    HAVE_AUDIO_LINE_TURE      有音频线路
 *    HAVE_AUDIO_LINE_FALSE     无音频线路
 */
typedef NS_ENUM(NSUInteger, HAVE_AUDIO_LINE) {
    HAVE_AUDIO_LINE_TURE,//有音频线路
    HAVE_AUDIO_LINE_FALSE,//无音频线路
};

@interface HDQualityModel : NSObject
/** 清晰度 */
@property (nonatomic, copy)   NSString                * _Nonnull quality;
/** 描述 */
@property (nonatomic, copy)   NSString                * _Nonnull desc;

@end
/**
 *    操作调用状态
 *    HDOperationCallStatusSuccess                操作成功
 *    HDOperationCallStatusFailedNotLogin         操作失败未登录
 *    HDOperationCallStatusFailedInLoading        操作失败加载中
 *    HDOperationCallStatusFailedAllReadyLoaded   操作失败已加载
 */
typedef NS_ENUM(NSInteger, HDOperationCallStatus) {
    HDOperationCallStatusSuccess,//操作成功
    HDOperationCallStatusFailedNotLogin,//操作失败未登录
    HDOperationCallStatusFailedInLoading,//操作失败加载中
    HDOperationCallStatusFailedAllReadyLoaded,//操作失败已加载
};

@interface HDReplayDotModel : NSObject
/** 打点时间：单位:S */
@property (nonatomic, assign)  NSInteger           time;
/** 打点描述 */
@property (nonatomic, copy)    NSString            * _Nullable desc;

@end

/// 申请连麦类型
typedef NS_ENUM(NSInteger, HDSMediaCallType) {
    HDSMediaCallTypeAudio,          /// 音频连麦
    HDSMediaCallTypeAudioVideo,     /// 视频连麦
};

/// 连麦错误类型
typedef NS_ENUM(NSInteger, HDSMediaCallError) {
    HDSMediaCallErrorInCalling,                 /// 连麦失败
    HDSMediaCallErrorConnectTimeOut,            /// 连麦申请超时
    HDSMediaCallErrorRoomTypeDidChange,         /// 连麦房间类型改变（需要退出重进）
    HDSMediaCallErroronMumberLimit,             /// 连麦人数已达上限
    HDSMediaCallErrorAbilityDown,               /// 连麦功能不可用（需要退出重进）
    HDSMediaCallErrorPullStreamFailed,          /// 拉流失败
};
/// 初始化SDK成功回调
typedef void(^initSuccedClosure)(BOOL succed);
/// 流视图回调
typedef void(^HDSPlayerViewClosure)(UIView * _Nonnull playerView);
/// 初始化SDK失败回调
typedef void(^initFailedClosure)(NSError * _Nullable error, NSString  * _Nonnull reason);
/// 挂断回调
typedef void(^hangupClosure)(BOOL succed);

/// 连麦房间类型
typedef NS_ENUM(NSInteger, HDSRoomCallType) {
    HDSRoomCallTypeAudio,                       /// 音频连麦房间 （多人连麦情况下只能申请音频连麦）
    HDSRoomCallTypeAudioVideo,                  /// 视频连麦房间 （单人连麦可申请音频或视频连麦）
};

/// 连麦功能不可用原因
typedef NS_ENUM(NSUInteger, HDSMediaCallAbilityDisableReason) {
    HDSMediaCallAbilityDisableReasonNone,              /// 无
    HDSMediaCallAbilityDisableReasonRoomNotOpen,       /// 房间未开启
    HDSMediaCallAbilityDisableReasonTeacherClose,      /// 讲师关闭
    HDSMediaCallAbilityDisableReasonLiveEnd,           /// 直播结束
    HDSMediaCallAbilityDisableReasonLiveBan,           /// 直播封禁
    HDSMediaCallAbilityDisableReasonNotNetwork,        /// 无网络
};

@interface HDSRoomCallInfo : NSObject
/// 是否是多人连麦房间
@property (nonatomic, assign) BOOL                          isMultiMediaCallRoom;
/// 是否开启连麦功能
@property (nonatomic, assign) BOOL                          isMediaCallFuncEnable;
/// 房间连麦功能未开启原因
@property (nonatomic, assign) HDSMediaCallAbilityDisableReason disableReason;
/// 连麦类型
@property (nonatomic, assign) HDSRoomCallType               roomCallType;

@end

@interface HDSStreamUserInfoModel : NSObject

/// 用户ID
@property (nonatomic, copy)   NSString    * _Nullable userId;
/// 用户名
@property (nonatomic, copy)   NSString    * _Nonnull userName;
/// 用户角色
@property (nonatomic, assign) NSInteger   userRole;
/// 声音是否可用
@property (nonatomic, assign) BOOL        isAudioEnable;
/// 视频是否可用
@property (nonatomic, assign) BOOL        isVideoEnable;

@end

/// 网络质量 -1为空值
typedef struct {
    int rtt;                //本机到服务器的往返时延(ms)
    int pktLostRate;        //发送丢包(0~100)
    int quality;            //本机上行网络质量(0~3)，分别对应优、良、中、差
    int rxQuality;          //本机下行网络质量(0~3)，分别对应优、良、中、差
    double akbps;           //音频码率(kb/s)
    double afps;            //音频帧率(网络接收)
    double vkbps;           //视频码率(kbps)
    double vfps;            //视频帧率(网络接收)
} HDSStreamQuality;

typedef HDSStreamQuality HDSStreamQuality;

@interface HDSStreamModel : NSObject

/// 远端流视图
@property (nonatomic, strong) UIView                 * _Nonnull hds_remoteView;

@property (nonatomic, strong) HDSStreamUserInfoModel * _Nonnull userInfo;
 
@end

typedef void (^pullStreamSuccedClosure)(HDSStreamModel * _Nullable stModel);
typedef void (^pullStreamFailedClosure)(HDSMediaCallError error);

typedef NS_ENUM(NSInteger, OnErrorType) {
    OnErrorType_LoginFailed = 2001001001,           // 登陆失败
    OnErrorType_GetPlaySourceFailed = 2001001002,   // 获取播放源失败
    OnErrorType_GetSummaryFailed = 2001001003,      // 获取摘要失败
};

typedef void (^completeHandler)(BOOL result, NSString * _Nullable message);

typedef void (^interactionTokenClosure)(NSString * _Nullable token);

@interface HDSOnErrorModel : NSObject
/// 错误类型
@property (nonatomic, assign) OnErrorType type;
/// 错误信息
@property (nonatomic, copy)   NSString    * _Nullable message;
 
@end

@interface HDSRedPacketModel : NSObject
/// ID
@property (nonatomic, copy)   NSString    * _Nullable id;
/// 红包雨时长
@property (nonatomic, assign) NSInteger  duration;
/// 红包雨开始时间
@property (nonatomic, assign) NSTimeInterval  startTime;
/// 当前系统时间
@property (nonatomic, assign) NSTimeInterval  currentTime;
/// 红包雨滑动速率  0:慢 1:中 2:快
@property (nonatomic, assign) NSInteger  slidingRate;

@end

@interface HDSRedPacketRankModel : NSObject
/// 总共抢到的学分
@property (nonatomic, copy) NSString    * _Nullable totalAmount;
/// 剩余学分
@property (nonatomic, copy) NSString    * _Nullable remainAmount;
/// 抢到红包的学员数量
@property (nonatomic, assign) NSInteger userCount;
/// 排行榜数据
@property (nonatomic, strong) NSArray   * _Nullable rankList;

@end

@interface HDSRedRacketRankListModel : NSObject

/// 用户id
@property (nonatomic, copy) NSString   * _Nullable userId;
/// 用户昵称
@property (nonatomic, copy) NSString   * _Nullable userName;
/// 得分
@property (nonatomic, assign) NSInteger amount;
/// 是否是自己
@property (nonatomic, assign) BOOL      isMyself;

@end

@interface HDSInteractionLikeModel : NSObject

/// 点赞功能配置  0:关闭 1:直播间配置 2:全局配置
@property (nonatomic, assign) NSInteger  likeFunctionConfig;

@end


@interface HDSInteractionGiftModel : NSObject

/// 打赏礼物功能配置 0:关闭 1:直播间配置 2:全局配置
@property (nonatomic, assign) NSInteger  giftFunctionConfig;
/// 打赏礼物特效配置 0:关闭 1:左侧特效 2：全局特效
@property (nonatomic, assign) NSInteger  specialEffects;

@end


@interface HDSInteractionFunctionModel : NSObject

@property (nonatomic, strong) HDSInteractionLikeModel * _Nullable likeModel;

@property (nonatomic, strong) HDSInteractionGiftModel * _Nullable giftModel;

@end
