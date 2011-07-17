//
//  RootViewController.h
//  smile
//
//  Created by Noguchi Osamu on 11/07/16.
//  Copyright 2011 envision. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <opencv2/imgproc/imgproc_c.h>
#import <opencv2/objdetect/objdetect.hpp>

@interface RootViewController : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate> {
    AVCaptureSession *captureSession;
    AVCaptureVideoDataOutput *videoOutput;
    
    CvHaarClassifierCascade *cascade;
    CvMemStorage *storage;
    
    NSArray *smileRectangles;
    
    UIImageView *smileView;
}

@property (nonatomic, retain) AVCaptureSession *captureSession;
@property (nonatomic, retain) AVCaptureVideoDataOutput *videoOutput;

@property (nonatomic, retain) NSArray *smileRectangles;

@property (nonatomic, retain) UIImageView *smileView;

- (AVCaptureDevice *)frontFacingCameraIfAvailable;

- (void)initOpenCV;
- (void)releaseOpenCV;

- (void)opencvSmileDetect:(UIImage *)originalImage;

- (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (IplImage *)rotateImage:(IplImage *)img angle:(double)angle;

@end
