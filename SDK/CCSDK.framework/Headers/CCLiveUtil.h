#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ERROR_SERVICE_TYPE) {
    ERROR_ROOM_STATE = 1001,//@"直播间状态不可用，可能没有开始推流"
    ERROR_USELESS_INFO = 1002,//@"没有获取到有用的视频信息"
    ERROR_PASSWORD = 1003,//@"密码错误"
};

typedef NS_ENUM(NSInteger, ERROR_SYSTEM_TYPE) {
    ERROR_RETURNDATA = 1004,//@"返回内容格式错误"
    ERROR_PARAMETER = 1005,//@"直播间信息填写错误"
    ERROR_NETWORK = 1006,//@"网络异常"
    ERROR_LOGINDATA = 1007,//@"登录"
    ERROR_PLAYERURL = 1008,//@"视频播放地址"
    ERROR_QUESTIONLIST = 1009,//@"问卷列表"
    ERROR_STATISTICAL = 1010,//@"问卷统计"
    ERROR_DOCLIST = 1011,//@"文档列表"
    ERROR_HISTORY = 1012,//@"历史信息"
    PRACTICE_LIST = 1013,//@"随堂测试"
    PRACTICECOMMIT = 1014,//@"提交随堂测试"
    PRACTICESTATIS = 1015,//@"获取随堂测统计"
    PRACTICERANK = 1016,//@"获取随堂测排名"
    ERROR_SOCKET = 1017,//@"socket加载失败"
    ERROR_PUNCH = 1018,//@"获取打卡信息失败"
    ERROR_PUNCHCOMMIT = 1019,//@"获取打卡提交结果失败"
    ERROR_DRMURL = 1020,//@"获取加密地址失败"
    ERROR_QUERYLOTTERY = 1021,//@"抽奖2.0 查询抽奖信息失败"
    ERROR_QUERYPERSIONALLOTTERY = 1022,//@"抽奖2.0 查询个人中奖失败"
    ERROR_COMMITWINNERINFO = 1023 ,//@"抽奖2.0 提交中奖信息"
    ERROR_REQUESTMETADATA = 1024,//获取元数据异常
    ERROR_DOCINITERROR = 1025,//文档初始化失败
    ERROR_GETSUMMARYINFO = 1026, //获取摘要接口失败
    ERROR_REQUEST_RED_PACKET = 1027,//@"查询正在进行的红包雨失败"
    ERROR_GRAD_RED_PACKET = 1028,//@"抢红包失败"
    ERROR_REQUEST_RED_PACKET_RANKLIST = 1029,//@"获取红包雨排行榜失败"
};

typedef NS_ENUM(NSInteger, ERROR_REQUEST_TYPE) {
   ERROR_REQUEST_DRAWDATA = 1021,//请求画笔数据错误
};



@interface CCLiveUtil : NSObject

/**
 *  生成HTTP请求头"User-Agent"
 *
 *  @return 类似于：appName appVersion (deviceName; systemName systemVersion; locale)”
 */
+ (NSString *)generateUserAgent;

+ (NSString *)urlEncode:(NSString *)urlString;

+(NSString*)UUID;

+ (NSString *)MD5File:(NSString *)path andUpper:(BOOL)uppercase;
+ (NSString *)MD5String:(NSString *)str andUpper:(BOOL)uppercase;
+ (NSString *)thqsWith:(NSDictionary *)dict andLocaltime:(NSString *)localtime key:(NSString *)key;

+ (BOOL)createDirectoryWithFilePath:(NSString *)filePath error:(NSError **)error;
+ (BOOL)createDirectoryWithDirectoryPath:(NSString *)directoryPath error:(NSError **)error;

+ (NSInteger)getFileSizeWithPath:(NSString *)filePath Error:(NSError **)error;

+ (NSString *)stringUrlEncode:(NSString *)string;
+ (NSString *)stringUrlDecode:(NSString *)string;

+ (NSString *)hds_getErrorTipString:(NSInteger)code;

# pragma mark - NSURL
/**
 *  @brief  从 urlString 解析url参数到 NSDictionary
 *  如 https://123.com/a/b/c.txt?v1=k1&v2=k3&v3=k3 解析的结果为：
 *   {
 *       "v1":"k1，
 *       "v2":"k3",
 *       "v3":"k3"，
 *    }
 *
 *  注意：该函数对字典里的value做了url解码。
 *
 *  @param urlString 字符串 url
 *
 *  @return url参数 字典
 */
+ (NSDictionary *)urlQueryDictionaryWithURLString:(NSString *)urlString;
+ (NSDictionary *)urlQueryDictionaryWithUrl:(NSURL *)url;

+ (UInt64)htonll:(UInt64)n;
+ (UInt64)ntohll:(UInt64)n;

+ (NSData *)encrypt:(NSData *)data key:(NSString *)key;
+ (NSData *)decrypt:(NSData *)data key:(NSString *)key;

+ (u_char *)memcpyFrom:(const u_char *)src to:(u_char *)dst length:(size_t)len;

+ (NSArray *)splitString:(NSString *)message;
+ (NSError *)createAnErrorWithDesc:(NSInteger) num;

@end
