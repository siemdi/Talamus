#ifndef CCAMERA_H
#define CCAMERA_H
#include <flycapture/FlyCapture2.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "errorhandler.h"
class CCamera
        : public CErrorHandler
{
public:
    CCamera();
    IplImage GetImageFromCam();
    void setBrightness(double value);
    void setShutter(int value);
    void setGain(double value);
    void setExposure(double value);
    void setSharpness(double value);
    void setGamma(double value);
    void setWhiteBalance(int red, int blue);
    void setHue(int value);
    void setSaturation(int value);

private:
    IplImage* ConvertImageToOpenCV(FlyCapture2::Image* pImage);

private:
    FlyCapture2::Error      error;
    FlyCapture2::PGRGuid    guid;
    FlyCapture2::BusManager busMgr;
    FlyCapture2::Camera     cam;
    FlyCapture2::CameraInfo pCamInfo;
    FlyCapture2::Image      rawImage;
    IplImage                *image;
    IplImage                *cvImage;
    FlyCapture2::Image      colorImage;
    CvSize                  mySize;
    int imageCnt;

    double  mlBrightness;
    double  mlShutter;
    double  mlGain;
    double  mlExposure;
    int     mlSharpness;
    double  mlGamma;
    int     mlRed;
    int     mlBlue;
    int     mlHue;
    int     mlSaturation;
};

#endif // CCAMERA_H
