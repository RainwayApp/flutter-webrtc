#if !TARGET_OS_TV
#import <WebRTC/WebRTC.h>

@interface FlutterRPScreenRecorder : RTCVideoCapturer

-(void)startCapture;

-(void)stopCapture;

@end
#endif
