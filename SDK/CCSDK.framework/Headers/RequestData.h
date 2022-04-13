//
//  RequestData.h
//  CCavPlayDemo
//
//  Created by ma yige on 15/6/29.
//  Copyright (c) 2015年 ma yige. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayParameter.h"
#import <WebKit/WebKit.h>
#define SDKVersion @"4.1.0"

@protocol RequestDataDelegate <NSObject>
@optional
//@optional
/**
 *    @brief    请求播放地址成功
 */
-(void)requestSucceed;
/**
 *    @brief    请求播放地址失败
 */
- (void)requestFailed:(NSError *)error reason:(NSString *)reason;

/// 3.18.0 new 错误回调
/// @param model 错误信息
- (void)onError:(HDSOnErrorModel *)model;

/**
 *    @brief  收到提问，用户观看时和主讲的互动问答信息
 */
- (void)onQuestionDic:(NSDictionary *)questionDic;
/**
 *    @brief  收到回答，用户观看时和主讲的互动问答信息
 */
- (void)onAnswerDic:(NSDictionary *)answerDic;
/**
 *    @brief  收到提问&回答，在用户登录之前，主讲和其他用户的历史互动问答信息 (会多次回调)
 */
- (void)onQuestionArr:(NSArray *)questionArr onAnswerArr:(NSArray *)answerArr;
/**
 *    @brief  历史聊天数据 (会多次回调)
 */
- (void)onChatLog:(NSArray *)chatLogArr;
/**
 *    @brief  主讲开始推流
 */
- (void)onLiveStatusChangeStart;
/**
 *    @brief  停止直播，endNormal表示是否异常停止推流，这个参数对观看端影响不大
 */
- (void)onLiveStatusChangeEnd:(BOOL)endNormal;
/**
 *  @brief  收到公聊消息
 *  @param  message {groupId         //聊天组ID
                     msg             //消息内容
                     time            //发布时间
                     useravatar      //用户头像
                     userid          //用户ID
                     username        //用户名称
                     userrole        //用户角色  (publisher:主讲,student:学生或观众,host:主持人,unknow:其他没有角色,teacher:助教) }
 */
- (void)onPublicChatMessage:(NSDictionary *)message;
/**
 *    @brief    收到私聊信息
 *    @param    dic {fromuserid         //发送者用户ID
 *                   fromusername       //发送者用户名
 *                   fromuserrole       //发送者角色
 *                   msg                //消息内容
 *                   time               //发送时间
 *                   touserid           //接受者用户ID
 *                   tousername         //接受者用户名}
 */
- (void)OnPrivateChat:(NSDictionary *)dic;
/**
 *    @brief    修改昵称
 */
- (void)onChangeNickname:(NSString *)nickNime;
/*
 *  @brief  收到自己的禁言消息，如果你被禁言了，你发出的消息只有你自己能看到，其他人看不到
 */
- (void)onSilenceUserChatMessage:(NSDictionary *)message;
/**
 *    @brief    收到在线人数
 */
- (void)onUserCount:(NSString *)count;
/**
 *    @brief    当主讲全体禁言时，你再发消息，会出发此代理方法，information是禁言提示信息
 */
- (void)information:(NSString *)information;
/**
 *    @brief    服务器端给自己设置的UserId
 */
-(void)setMyViewerId:(NSString *)viewerId;
/**
 *    @brief  收到踢出消息，停止推流并退出播放（被主播踢出）(change)
 kick_out_type
 10 在允许重复登录前提下，后进入者会登录会踢出先前登录者
 20 讲师、助教、主持人通过页面踢出按钮踢出用户
 */
- (void)onKickOut:(NSDictionary *)dictionary;
/**
 *    @brief  获取房间信息，主要是要获取直播间模版来类型，根据直播间模版类型来确定界面布局
 *  显示在线人数   dic[@"showusercount"];
 *  倒计时              dic[@"openlivecountdown"];
 *  弹幕                  dic[@"barrage"];
 *  跑马灯              dic[@"openmarquee"];
 *    房间简介：       dic[@"desc"];
 *    房间名称：       dic[@"name"];
 *    房间模版类型：[dic[@"templateType"] integerValue];
 *    模版类型为1: 聊天互动： 无 直播文档： 无 直播问答： 无
 *    模版类型为2: 聊天互动： 有 直播文档： 无 直播问答： 有
 *    模版类型为3: 聊天互动： 有 直播文档： 无 直播问答： 无
 *    模版类型为4: 聊天互动： 有 直播文档： 有 直播问答： 无
 *    模版类型为5: 聊天互动： 有 直播文档： 有 直播问答： 有
 *    模版类型为6: 聊天互动： 无 直播文档： 无 直播问答： 有
 */
-(void)roomInfo:(NSDictionary *)dic;
/**
 *    @brief  收到播放直播状态 0.正在直播 1.未开始直播
 */
- (void)getPlayStatue:(NSInteger)status;
/**
 *    @brief  获取文档内白板或者文档本身的宽高，来进行屏幕适配用的
 */
- (void)getDocAspectRatioOfWidth:(CGFloat)width height:(CGFloat)height;
/**
 *  @brief  获取ppt当前页数和总页数 (会多次回调)
 *
 *  回调当前翻页的页数信息
 *  白板docTotalPage一直为0, pageNum从1开始
 *  其他文档docTotalPage为正常页数,pageNum从0开始
 *  @param dictionary 翻页信息
 */
- (void)onPageChange:(NSDictionary *) dictionary;
/**
 *    @brief  登录成功
 */
- (void)loginSucceedPlay;
/**
 *    @brief  登录失败
 */
-(void)loginFailed:(NSError *)error reason:(NSString *)reason;

/**
 *  @brief  自定义消息
 */
- (void)customMessage:(NSString *)message;
/**
 *  @brief  公告
 */
- (void)announcement:(NSString *)str;
/**
 *  @brief  监听到有公告消息
 */
- (void)on_announcement:(NSDictionary *)dict;
/**
 *  @brief  开始抽奖
 */
- (void)start_lottery;
/**
 *  @brief  抽奖结果
 *  remainNum   剩余奖品数
 */
- (void)lottery_resultWithCode:(NSString *)code myself:(BOOL)myself winnerName:(NSString *)winnerName remainNum:(NSInteger)remainNum;
/**
 *  @brief  退出抽奖
 */
- (void)stop_lottery;
/**
 *  @brief  开始签到
 */
- (void)start_rollcall:(NSInteger)duration;
/**
 *  @brief  开始答题
 */
- (void)start_vote:(NSInteger)count singleSelection:(BOOL)single;
/**
 *  @brief  结束答题
 */
- (void)stop_vote;
/**
 *  @brief  答题结果
 */
- (void)vote_result:(NSDictionary *)resultDic;
/**
 *  @brief  加载视频失败
 */
- (void)play_loadVideoFail;
/**
 *  @brief  接收到发送的广播
 */
- (void)broadcast_msg:(NSDictionary *)dic;
/**
 *  @brief  接收到最后一条广播(直播中途进入,会返回最后一条广播) (会多次回调)
 */
- (void)broadcastLast_msg:(NSArray *)array;
/**
 *  @brief  发布问题的ID
 */
- (void)publish_question:(NSString *)publishId;
/**
 *  @brief  发布问卷
 */
- (void)questionnaire_publish;
/**
 *  @brief  结束发布问卷
 */
- (void)questionnaire_publish_stop;
/**
 *  @brief  获取问卷详细内容
 *  forcibly 为1就是强制答卷，0为非强制答卷
 */
- (void)questionnaireDetailInformation:(NSDictionary *)detailDic;
/**
 *  @brief  获取问卷统计
 */
- (void)questionnaireStaticsInformation:(NSDictionary *)staticsDic;
/**
 *  @brief  提交问卷结果（成功，失败）
 */
- (void)commitQuestionnaireResult:(BOOL)success;
/**
 *  @brief  问卷功能
 */
- (void)questionnaireWithTitle:(NSString *)title url:(NSString *)url;

/**
 *    @brief     双击ppt
 */
- (void)doubleCllickPPTView DEPRECATED_MSG_ATTRIBUTE("该方法已废弃");

/**
 *  @brief  获取直播开始时间和直播时长
 *  liveDuration 直播持续时间，单位（s），直播未开始返回-1"
 *  liveStartTime 新增开始直播时间（格式：yyyy-MM-dd HH:mm:ss），如果直播未开始，则返回空字符串
 *
 *  注: liveStartTime: 1.后台配置直播开始时间, liveStartTime 是后台配置的开始时间, 如果开始直播时间和配置的开始时间不一致,实际开播时间 "需要用当前时间 - liveDruation " 计算实际开始时间;
 *                     2.后台未配置直播开始时间, liveStartTime 是实际开始直播时间;
 *      liveDuration: 直播实际开播时长;
 *
 */
- (void)startTimeAndDurationLiveBroadcast:(NSDictionary *)dataDic;

/**
 *    @brief     直播间被禁
 */
- (void)theRoomWasBanned;

/**
 *    @brief     直播间解禁
 */
- (void)theRoomWasCleared;

/**
 *    @brief     获取所有文档列表 需要调用getDocsList
 */
- (void)receivedDocsList:(NSDictionary *)listDic;
/**
 *    @brief     客户端关闭摄像头
 数据源类型    数据源值    数据源类型描述       数据源类型描述值
 source_type    0     source_type_desc    数据源类型：默认值，
 source_type    10    source_type_desc    数据源类型：摄像头打开
 source_type    11    source_type_desc    数据源类型：摄像头关闭
 source_type    20    source_type_desc    数据源类型：图片
 source_type    30    source_type_desc    数据源类型：插播视频
 source_type    40    source_type_desc    数据源类型：区域捕获
 source_type    50    source_type_desc    数据源类型：桌面共享
 source_type    60    source_type_desc    数据源类型：自定义场景
 
 ps:
 source_type 参数 0 值 应用场景：
 1. 文档模式下 0 默认值
 2. 非文档模式下 0 无意义
 3. 低版本客户端 0 无意义
 source_type 参数 60 值 应用场景：
 当以上场景无法满足要求时，主播可自定义场景，用户不需要关心自定义场景细节内容
 */
- (void)receivedSwitchSource:(NSDictionary *)dic;
/**
 *  @brief  视频或者文档大窗
 *  isMain 1为视频为主,0为文档为主"
 */
- (void)onSwitchVideoDoc:(BOOL)isMain;
/**
 *    @brief    服务器端给自己设置的信息
 *    viewerId 服务器端给自己设置的UserId
 *    groupId 分组id
 *    name 用户名
 */
-(void)setMyViewerInfo:(NSDictionary *) infoDic;
/**
 *    @brief    收到聊天禁言
 *    mode 禁言类型 1：个人禁言  2：全员禁言
 */
-(void)onBanChat:(NSDictionary *) modeDic;
/**
 *    @brief    收到聊天禁言并删除聊天记录
 *    viewerId 禁言用户id,是自己的话别删除聊天历史,其他人需要删除该用户的聊天
 */
-(void)onBanDeleteChat:(NSDictionary *) viewerDic;
/**
 *    @brief    收到解除禁言事件
 *    mode 禁言类型 1：个人禁言  2：全员禁言
 */
-(void)onUnBanChat:(NSDictionary *) modeDic;
/**
 *    @brief    聊天管理
 *    status    聊天消息的状态 0 显示 1 不显示
 *    chatIds   聊天消息的id列列表
 */
-(void)chatLogManage:(NSDictionary *) manageDic;

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
 *    @brief       接收到随堂测
 *    rseultDic    随堂测内容
      resultDic    {
                   isExist                         //是否存在正在发布的随堂测 1 存在 0 不存在
                   practice{
                             id                    //随堂测ID
                             isAnswered            //是否已答题 true: 已答题, false: 未答题
                             options               //选项数组
                             ({
                                   id              //选项ID
                                   index           //选项索引
                             })
                             publishTime           //随堂测发布时间
                             status                //随堂测状态: 1 发布中 2 停止发布 3 已关闭
                             type                  //随堂测类型: 0 判断 1 单选 2 多选
                             submitRecord          //如果已答题，返回该学员答题记录，如果未答题，服务端不返回该字段
                             ({
                                 optionId          //选项ID
                                 optionIndex       //选项索引
                             })
                           }
                   serverTime                      //分发时间
 
                  }
 *
 */
-(void)receivePracticeWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    随堂测提交结果
 *    rseultDic    提交结果,调用commitPracticeWithPracticeId:(NSString *)practiceId options:(NSArray *)options后执行
 *
      resultDic {datas {practice                                 //随堂测
                            { answerResult                      //回答是否正确 1 正确 0 错误
                              id                                //随堂测ID
                              isRepeatAnswered                  //是否重复答题 true: 重复答题, false: 第一次答题
                              options ({  count                 //参与人数
                                            id                  //选项主键ID
                                            index               //选项序号
                                            isCorrect           //是否正确
                                            percent             //选项占比})
                              submitRecord 如果重复答题，则返回该学员第一次提交的记录，否则，返回该学员当前提交记录
                                           ({ optionId          //提交记录 提交选项ID
                                              optionIndex       //提交选项序号})
                              type                              //随堂测类型: 0 判断 1 单选 2 多选}}}
 */
-(void)practiceSubmitResultsWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    随堂测统计结果
 *    rseultDic    统计结果,调用getPracticeStatisWithPracticeId:(NSString *)practiceId后执行
      resultDic  {practice {                                //随堂测
                           answerPersonNum                 //回答该随堂测的人数
                           correctPersonNum                //回答正确的人数
                           correctRate                     //正确率
                           id                              //随堂测ID
                           options ({                      //选项数组
                                       count               //选择该选项的人数
                                       id                  //选项ID
                                       index               //选项序号
                                       isCorrect           //是否为正确选项 1 正确 0 错误
                                       percent             //选择该选项的百分比})
                           status                          //随堂测状态  1 发布中 2 停止发布
                           type                            //随堂测类型: 0 判断 1 单选 2 多选}}
 */
-(void)practiceStatisResultsWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    随堂测排名结果
 *    rseultDic    排名结果,调用getPracticeRankWithPracticeId:(NSString *)practiceId后执行
 */
-(void)practiceRankResultsWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    停止随堂测
 *    rseultDic    结果
 */
-(void)practiceStopWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    关闭随堂测
 *    rseultDic    结果
 */
-(void)practiceCloseWithDic:(NSDictionary *) resultDic;
/**
 *    @brief    视频状态
 *    rseult    playing/paused/loading/buffing
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
 *    @brief    播放器准备完成 (会多次回调)
 */
- (void)HDMediaPlaybackIsPreparedToPlayDidChange;
/**
 *    @brief    视频加载速度
 *    @param    speed   视频加载速度字符串
 */
- (void)onBufferSpeed:(NSString *)speed;
/**
 *    @brief    收到奖杯
 *    dic       结果
 *    "type":  1 奖杯 2 其他
 */
-(void)prize_sendWithDict:(NSDictionary *)dic;
/**
 *    @brief    收到开始打卡
 *    dic {
          "punchId": "punchId",
          "expireTime": "2019-10-26 10:00:00",
          "remainDuration": 124
          "tips"  // 没有提示语则不返回该字段
           }
 *    当没有设置时长，即无过期时间时
 *    {
     "punchId": "asasdasdasdasd",
     "remainDuration": -1 //其中-1表示剩余无限时间。
      }
 */
-(void)hdReceivedStartPunchWithDict:(NSDictionary *)dic;
/**
 *    @brief    收到结束打卡
 *    dic{
     "punchId": "punchId"
 }
 */
-(void)hdReceivedEndPunchWithDict:(NSDictionary *)dic;
/**
 *    @brief    收到打卡提交结果
 *    dic{
     "success": true,
     "data": {
         "isRepeat": false//是否重复提交打卡
     }
 }
 */
-(void)hdReceivedPunchResultWithDict:(NSDictionary *)dic;
/**
收到老师列表
 teachers =     (
             {
         id = "";//老师id
         ip = "";//IP地址
         name = "";老师昵称
         role = teacher;//角色
     }
 );
*/
-(void)onOnlineTeachers:(NSDictionary *)dic;
/**
 *    @brief    房间设置信息
 *    dic{
      "allow_chat" = true;//是否允许聊天
      "allow_question" = true;//是否允许问答
      "room_base_user_count" = 0;//房间基础在线人数
      "source_type" = 0;//对应receivedSwitchSource方法的source_type
}
 *ps:当房间类型没有聊天或者问答时,对应的字段默认为true
*/
-(void)roomSettingInfo:(NSDictionary *)dic;
/**
 *    @brief    跑马灯信息,需要开启跑马灯功能且iOS 9.0以上
*/
-(void)receivedMarqueeInfo:(NSDictionary *)dic;
/**
 *    @brief    回调已播放时长, 如果未开始，则time为-1
 *              触发此方法需要调用getLivePlayedTime
*/
- (void)onLivePlayedTime:(NSDictionary *)dic;
/**
 *    @brief    删除广播
 *    @param    dic   删除数据
 *              dic {
 *              action         //操作 1.删除
                     id             //广播id }
 */
- (void)broadcast_delete:(NSDictionary *)dic;

/**
 *    @brief    禁言用户提示
 *    @param    model   BanChatModel    详情
 */
- (void)HDBanChatBroadcastWithModel:(BanChatModel *)model;

/**
 *    @brief    用户进出直播间提示
 *    @param    model    RemindModel    详情
 */
- (void)HDUserRemindWithModel:(RemindModel *)model;
/**
 *    @brief    抽奖2.0 抽奖信息回调 (该功能需要单独开启)
 *    @param    model   NewLotteryMessageModel 详情
 */
- (void)HDOnLotteryWithModel:(NewLotteryMessageModel *)model;
/**
 *    The New Method (3.14.0)
 *    @brief    是否开启音频模式
 *    @param    hasAudio   HAVE_AUDIO_LINE_TURE 有音频 HAVE_AUDIO_LINE_FALSE 无音频
 *
 *    触发回调条件 1.初始化SDK登录成功后
 */
- (void)HDAudioMode:(HAVE_AUDIO_LINE)hasAudio;
/**
 *    The New Method (3.14.0)
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
 *    The New Method (3.14.0)
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
 *    @brief    开始红包雨
 *    @param    redPacketId   红包雨ID
 */
- (void)HDSRedPacketDidStart:(NSString *)redPacketId;

/**
 *    @brief    结束红包雨
 *    @param    redPacketId   红包雨ID
 */
- (void)HDSRedPacketDidEnd:(NSString *)redPacketId;

/// 互动功能配置
/// @param configModel 配置信息
- (void)onInteractionFunctionConfig:(HDSInteractionFunctionModel *)configModel;

//#ifdef LIANMAI_WEBRTC
/// 房间是否允许连麦
/// @param callInfo 房间信息
- (void)onMediaCallStatusDidChange:(HDSRoomCallInfo *)callInfo;

/// 远端流可用
/// @param streamModel 流信息
- (void)onRemoteStreamEnable:(HDSStreamModel *)streamModel;

/// 远端流不可用
/// @param streamModel 流信息
- (void)onRemoteStreamDisable:(HDSStreamModel *)streamModel;

/// 连麦模式切换  只有多人连麦才会触发
/// @param  mode 模式  7 无延迟 / 8 低延迟 / 9 普通
- (void)onMediaCallModeDidChange:(int)mode;

/// 邀请上麦
- (void)onInviteCall;

/// 取消邀请
- (void)onInviteCanceled;

/// 音频状态改变
/// @param status 是否可用
/// @param userId 用户id
/// @param byTeacher 是否是老师操作
- (void)onAudioStatusDidChange:(BOOL)status userId:(NSString *)userId byTeacher:(BOOL)byTeacher;

/// 视频状态改变
/// @param status 是否可用
/// @param userId 用户id
- (void)onVideoStatusDidChange:(BOOL)status userId:(NSString *)userId;

/// 被挂断
- (void)onCallWasHangup;

/// 异常挂断
/// @param error 错误原因
- (void)onConnectionException:(HDSMediaCallError)error;

/// 推流质量回调 （单人连麦）
/// @param quality 流质量
- (void)onPushStreamQuality:(HDSStreamQuality)quality;

/// 拉流质量回调 （单人连麦）
/// @param quality 流质量
- (void)onPullStreamQuality:(NSString *)streamID quality:(HDSStreamQuality)quality;

//#endif

@end

@interface RequestData : NSObject

@property (weak,nonatomic) id<RequestDataDelegate>      delegate;


/**
 *    @brief    登录房间
 *    @param     parameter              配置参数信息
 *  必填参数 userId;                //用户ID
 *  必填参数 roomId;                //房间ID
 *  必填参数 viewerName;            //用户名称
 *  必填参数 token;                 //房间密码
 *  (已弃用!) security              //是否使用https
 * （选填参数）viewercustomua;       //用户自定义参数，需和后台协商，没有定制传@""
 */
- (id)initLoginWithParameter:(PlayParameter *)parameter;

/// 初始化SDK
/// @param parameter 参数
/// @param succed 初始化成功回调
/// @param player 播放视图回调 （流视图异步回调，存在回调多次；无延迟直播无需关注。）
/// @param failed 初始化失败回调
- (id)initSDKWithParameter:(PlayParameter *)parameter
                    succed:(initSuccedClosure)succed
                    player:(HDSPlayerViewClosure)player
                    failed:(initFailedClosure)failed;

/**
 *    @brief    提问
 *    @param     message 提问内容
 */
- (void)question:(NSString *)message;
/**
 *    @brief    发送公聊信息
 *    @param     message  发送的消息内容
 */
- (void)chatMessage:(NSString *)message;
/**
 *    @brief    发送公聊信息
 *    @param     message  发送的消息内容
 *               completion 发送回调 成功或者失败
 */
- (void)sendChatMessage:(NSString *)message completion:(void (^)(BOOL success))completion;
/**
 *    @brief  发送私聊信息
 */
- (void)privateChatWithTouserid:(NSString *)touserid msg:(NSString *)msg;
/**
 *    @brief    销毁文档和视频，清除视频和文档的时候需要调用,退出播放页面的时候也需要调用
 */
- (void)requestCancel;
/**
 *    @brief  获取文档区域内白板或者文档本身的宽高比，返回值即为宽高比，做屏幕适配用
 */
- (CGFloat)getDocAspectRatio;
/**
 *    @brief  改变文档区域大小,主要用在文档生成后改变文档窗口的frame
 */
- (void)changeDocFrame:(CGRect) docFrame;
/**
 *    @brief  改变文档父窗口
 */
- (void)changeDocParent:(UIView *) docParent;
/**
 *    @brief  播放器暂停
 */
- (void)pausePlayer;
/**
 *    @brief  播放器播放
 */
- (void)startPlayer;
/**
 *    @brief  播放器关闭并移除
 */
- (void)shutdownPlayer;
/**
 *    @brief  播放器停止
 */
- (void)stopPlayer;
/**
 *  @brief 重新加载视频,参数force表示是否强制重新加载视频，
 * 一般重新加载视频的时间间隔应该超过3秒，如果强制重新加载视频，时间间隔可以在3S之内
 */
-(void)reloadVideo:(BOOL)force;
/**
 *  @brief 签到
 */
-(void)answer_rollcall;
/**
 *  @brief 答单选题
 */
-(void)reply_vote_single:(NSInteger)index;
/**
 *  @brief 答多选题
 */
-(void)reply_vote_multiple:(NSMutableArray *)indexArray;
/**
 *    @brief  播放器是否播放
 */
- (BOOL)isPlaying;
/**
 *    @brief  设置后台是否可播放
 */
- (void)setpauseInBackGround:(BOOL)pauseInBackGround;
/**
 *  @brief 提交问卷结果
 */
-(void)commitQuestionnaire:(NSDictionary *)dic;
/**
 *  @brief 主动请求问卷
 */
-(void)getPublishingQuestionnaire;
/**
 *    @brief     修改昵称
 *    @param     nickName  修改后的昵称
 */
- (void)changeNickName:(NSString *)nickName;

/**
 *    @brief     切换当前的文档模式
 *      1.切换至跟随模式（默认值）值为0，
 *      2.切换至自由模式；值为1，
 */
- (void)changeDocMode:(NSInteger)mode;
/**
 *    @brief     查找并获取当前文档的信息
 *      @param     docId  文档的docId
 *      @param     pageIndex  跳转的页数
 */
- (void)changePageToNumWithDocId:(NSString *)docId pageIndex:(NSInteger)pageIndex;

/**
 *    @brief     提交随堂测
 *      @param     practiceId  随堂测ID
 *      @param     options   选项ID 数组
 */
- (void)commitPracticeWithPracticeId:(NSString *)practiceId options:(NSArray *)options;
/**
 *    @brief     获取随堂测统计信息(可多次调用)
 *      @param     practiceId  随堂测ID
 */
-(void)getPracticeStatisWithPracticeId:(NSString *)practiceId;
/**
 *    @brief     获取随堂测排名(可多次调用)
 *      @param     practiceId  随堂测ID
 */
-(void)getPracticeRankWithPracticeId:(NSString *)practiceId;

/**
 *    @brief     获取随堂测
 *      @param     practiceId  随堂测ID(没有传@"")
 */
-(void)getPracticeInformation:(NSString *)practiceId;
/**
 * 获取ppt列表(只能在登陆成功后调用)
 */
- (void)getDocsList;

/**
 改变文档背景颜色

 @param hexColor 字符串,传颜色的HEXColor 如:#000000
 */
- (void)changeDocWebColor:(NSString *)hexColor;
/**
查询打卡信息
*/
- (void)hdInquirePunchInformation;
/**
提交打卡

@param punchId 打卡id
*/
- (void)hdCommitPunchWithPunchId:(NSString *)punchId;
/**
获取老师列表
*/
- (void)getOnlineTeachers;
/**
 获取已播放时长,调用后会响应onLivePlayedTime方法,调用间隔三秒
 */
- (void)getLivePlayedTime;
/**
 *  重新加载文档
 */
- (void)docReload;
/**
 *    @brief    主动调用方法       用于调整PPT缩放模式
 *    @param    pptScalingMode   PPT缩放模式
 *                               1 = 拉伸填充:PPT内容全部展示在显示区域,会被拉伸或压缩,不会存在黑边
 *                               2 = 等比居中:PPT内容保持原始比例,适应窗口展示在显示区域,会存在黑边
 *                               3 = 等比填充:PPT内容保持原始比例,以横向或纵向适应显示区域,另一方向将会超出显示区域,超出部分会被裁减,不会存在黑边
 */
- (void)changeDocPPTScalingMode:(NSInteger)pptScalingMode;
/**
 *    @brief    抽奖2.0 查询抽奖状态
 */
- (void)queryLotteryStatus;
/**
 *    @brief    抽奖2.0 提交中奖用户信息
 *    @param    collectInfos   用户信息
 *              collectInfos = @[@{@"index":@(0),@"value":@""}];
 *    @param    lotteryId      中奖订单ID (非必选)
 *    @param    completion     请求结果回调
 */
- (void)commitLottery:(NSArray *)collectInfos lotteryId:(NSString *)lotteryId completion:(void (^)(BOOL success))completion;
/**
 *    The New Method (3.14.0)
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
 *    The New Method (3.14.0)
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
 *    The New Method (3.14.0)
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
 *    @brief    查询正在进行中的红包雨
 *    @param    redPacketId     红包雨ID （没有传空@""）
 *    @param    closure         回调
 */
- (void)requestRedPacket:(NSString *)redPacketId
                 closure:(void(^)(HDSRedPacketModel *model))closure;

/**
 *    @brief    抢红包
 *    @param    redPacketId   红包雨ID
 *    @param    closure       回调
 */
- (void)gradRedPacket:(NSString *)redPacketId
              closure:(void(^)(BOOL result))closure;

/**
 *    @brief    查询红包雨排行榜
 *    @param    redPacketId     红包雨ID
 *    @param    closure         回调
 */
- (void)requestRedPacketRankList:(NSString *)redPacketId
                         closure:(void(^)(HDSRedPacketRankModel *model))closure;

/// 获取流加载状态
- (HDSMediaLoadState)getMediaLoadStatus;

/// 获取流播放状态
- (HDSMediaPlaybackState)getMediaPlayStatus;

/// 获取互动组件 token
/// @param closure 操作回调 (result 操作状态， message 信息)
/// @param tokenClosure token回调  " result == YES 时返回token, result == NO 时返回 @""(空字符串) "
- (void)getInteractionTokenWithClosure:(completeHandler)closure tokenClosure:(interactionTokenClosure)tokenClosure;

//#ifdef LIANMAI_WEBRTC

/// 主动申请上麦
/// @param type 类型
/// @param succedClosure 成功回调 (preview 为自己的预览视图，仅在多人连麦使用)
/// @param failedClosure 失败回调
- (void)callInPreviewWithType:(HDSMediaCallType)type
                       succed:(void(^)(UIView *preview))succedClosure
                       failed:(void(^)(HDSMediaCallError error))failedClosure;

/// 同意上麦
/// @param succedClosure 成功回调 (preview 为自己的预览视图，仅在多人连麦使用)
/// @param failedClosure 失败回调
- (void)agreeCallInPreview:(void(^)(UIView *preview))succedClosure
                    failed:(void(^)(HDSMediaCallError error))failedClosure;

/// 拒接
- (void)rejectCall;

/// 挂断
/// @param closure 回调
/// 主动挂断连麦,用户主动点击下麦按钮时需要关心finishClosure的返回值，
/// 退出直播间、下课等调用hangup时不需要关心callback
- (void)hangup:(hangupClosure)closure;

/// 切换本地摄像头，默认前置
/// @return  是否操作成功
- (BOOL)switchCamera;

/// 设置本地视频开启 (开始直播之后生效)
/// @param enable 是否开启 YES 开启/ NO 关闭
/// @return  是否操作成功
- (BOOL)setLocalVideoEnable:(BOOL)enable;

/// 设置本地音频开启(开始直播之后生效)
/// @param enable 是否开启 YES 开启/ NO 关闭
/// @return  是否操作成功
- (BOOL)setLocalAudioEnable:(BOOL)enable;

/// 拉远端流
/// @param userId 用户ID
/// @param succedClosure 成功
/// @param failedClosure 失败
- (void)pullRemoteStream:(NSString *)userId
                  succed:(pullStreamSuccedClosure)succedClosure
                  failed:(pullStreamFailedClosure)failedClosure;

/// 移除远端流
/// @param userId 远端流用户id
- (void)removeRemoteStream:(NSString *)userId;
//#endif
@end
