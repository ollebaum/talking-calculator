//
//  AudioPlayer.h
//  NewCalculator
//
//  Created by Olof Hellquist on 2013-07-23.
//  Copyright (c) 2013 Olof Hellquist. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class RepeatedStrings;
@class StringRepeated;

@interface AudioPlayer : NSObject

- (void)addAudioFile:(NSString *)audioFile withKey:(NSString *)key;
- (NSString *)playAudioWithKeyAsync:(StringRepeated *)key;
- (NSString *)playAudioWithKey:(StringRepeated *)key;
- (NSArray *)playAudioQueueWithKeys:(RepeatedStrings *)keys inBackground:(BOOL)async;
- (NSString *)playAudio:(id)player;
- (void)abortQueue;

@end

@interface MissingAudioFileException : NSException @end
@interface IncorrectFileNameException : NSException @end
@interface MissingAudioKeyException : NSException @end

@interface AsyncAudioPlayer : NSOperation

@property (strong) AudioPlayer *audioPlayer;
@property (strong) RepeatedStrings *keys;
-(id)initWithAudioPlayer:(AudioPlayer *)player andKeys:(RepeatedStrings *)keys;

@end

@interface AsyncPlay : AsyncAudioPlayer

-(id)initWithAudioPlayer:(AudioPlayer *)player andRepeatedKey:(StringRepeated *)repeatedString;
@end
