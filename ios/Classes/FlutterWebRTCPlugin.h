#import <Flutter/Flutter.h>
#import <Foundation/Foundation.h>

#import <WebRTC/RTCDataChannel.h>
#import <WebRTC/RTCPeerConnection.h>
#import <WebRTC/RTCDataChannel.h>
#import <WebRTC/RTCDataChannelConfiguration.h>
#import <WebRTC/RTCMediaStreamTrack.h>
#if !TARGET_OS_TV
#import <WebRTC/RTCCameraVideoCapturer.h>
#endif

@class FlutterRTCVideoRenderer;

@interface FlutterWebRTCPlugin : NSObject<FlutterPlugin, RTCPeerConnectionDelegate>

@property (nonatomic, strong) RTCPeerConnectionFactory *peerConnectionFactory;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCPeerConnection *> *peerConnections;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStream *> *localStreams;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStreamTrack *> *localTracks;
#if !TARGET_OS_TV
@property (nonatomic, strong) NSMutableDictionary<NSNumber *, FlutterRTCVideoRenderer *> *renders;
#endif
@property (nonatomic, retain) UIViewController *viewController;/*for broadcast or ReplayKit */
@property (nonatomic, strong) NSObject<FlutterBinaryMessenger>* messenger;
#if !TARGET_OS_TV
@property (nonatomic, strong) RTCCameraVideoCapturer *videoCapturer;
#endif
@property (nonatomic) BOOL _usingFrontCamera;
@property (nonatomic) int _targetWidth;
@property (nonatomic) int _targetHeight;
@property (nonatomic) int _targetFps;

- (RTCMediaStream*)streamForId:(NSString*)streamId;

@end
