//
//  HDSPreserve.h
//  DDLogTD
//
//  Created by david on 2022/3/1.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface HDSPreserve : NSObject
+ (HDSPreserve *)shared;

- (void)HDSApplicationDidFinishLaunching;
//- (void)HDSApplicationWillResignActive;
//- (void)HDSApplicationDidEnterBackground;
- (void)HDSApplicationWillTerminate;
@end

NS_ASSUME_NONNULL_END
