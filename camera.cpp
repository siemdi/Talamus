#include "camera.h"

CCamera::CCamera()
//    : mlBrightness(1)
//    , mlExposure(1)
//    , mlSharpness(1)
//    , mlHue(1)
//    , mlSaturation(1)
//    , mlGamma(1)
//    , mlShutter(1)
//    , mlGain(1)
//    , mlFrameRate(1)
//    , mlRed(1)
//    , mlBlue(1)
{
    DEBUG("CCamera::CCamera()");
    imageCnt=0;

    error = busMgr.GetCameraFromIndex(0, &guid);
    if (error != FlyCapture2::PGRERROR_OK)
    {
        CRITICAL(error.GetDescription());
    }

    error = cam.Connect(&guid);
    if (error != FlyCapture2::PGRERROR_OK)
    {
        CRITICAL(error.GetDescription());
    }

    error = cam.GetCameraInfo(&pCamInfo);
    if (error != FlyCapture2::PGRERROR_OK)
    {
        CRITICAL(error.GetDescription());
    }

    error = cam.StartCapture();
    if (error != FlyCapture2::PGRERROR_OK)
    {
        CRITICAL(error.GetDescription());
    }

    image = cvCreateImage(CvSize(1024,1280), IPL_DEPTH_8U, 3 );

    FlyCapture2::TriggerMode mTrigger;
    mTrigger.polarity = 1;
    mTrigger.onOff = true;
    cam.SetTriggerMode(&mTrigger);

}

IplImage CCamera::GetImageFromCam()
{
//    DEBUG("CCamera::GetImageFromCam()");

//    cam.ReadRegister( 0x11f8, &value);
//    std::cout<<std::hex<<"IO direction:"<<value<<std::endl;

//    cam.ReadRegister( 0x1110, &value);
//    std::cout<<std::hex<<"IO 0:"<<value<<std::endl;

//    cam.ReadRegister( 0x1120, &value);
//    std::cout<<"IO 1:"<<value<<std::endl;

//    cam.ReadRegister( 0x1130, &value);
//    std::cout<<"IO 2:"<<value<<std::endl;

//    cam.ReadRegister( 0x1140, &value);
//    std::cout<<"IO 3:"<<value<<std::endl;

//    cam.ReadRegister( 0x1100, &value);

//    for(int i=0;i<10;i++)
//    {
//        cam.WriteRegister( 0x1100, 1<<3);
//        cam.WriteRegister( 0x1100, 1<<2);
//        cam.WriteRegister( 0x1100, 1<<1);
//        //cam.ReadRegister(0x1100, &value);
//        cvWaitKey(10);
//        cam.WriteRegister( 0x1100, value&~(1<<1));
//        cam.WriteRegister( 0x1100, value&~(1<<2));
//        cam.WriteRegister( 0x1100, value&~(1<<3));
//        //cam.ReadRegister(0x1100, &value);
//        cvWaitKey(10);
//    }

//    std::cin>>a;
//    std::cout<<"pin reg new status="<<value<<std::endl;
//    cam.WriteRegister( 0x1100, 1<<3);
//    cam.ReadRegister(0x1100, &value);
//    std::cin>>a;
//    std::cout<<"pin reg new status="<<value<<std::endl;
//    cam.WriteRegister( 0x1100, 0x0);



//    cam.ReadRegister( 0x1100, &value);
//    std::cout<<"pin IO="<<value<<std::endl;

//    cam.WriteRegister( 0x1100, 0x40000000);
//    cam.ReadRegister(0x1100, &value);
//    std::cout<<"pin IO="<<value<<std::endl;

//    cam.WriteRegister( 0x1100, 0x00000000);
//    cam.ReadRegister( 0x1100, &value);
//    std::cout<<"pin IO="<<value<<std::endl;



//    FlyCapture2::StrobeControl mStrobe;
//    mStrobe.source = 1;

//    mStrobe.onOff = true;

//    mStrobe.delay = 1.0f;

//    cam.SetStrobe(&mStrobe);

    error = cam.RetrieveBuffer(&rawImage);
    WARNING(error.GetDescription());
    image = ConvertImageToOpenCV(&rawImage);
    return *image;
}

void CCamera::setBrightness(double value)
{
    //std::cout<<"setBrightness value: "<<value<<std::endl;
    //std::cout<<"setBrightness mBrightness: "<<mlBrightness<<std::endl;
    if(value != mlBrightness)
    {
        mlBrightness = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::BRIGHTNESS;
        property.onOff = true;
        property.absControl = true;
        property.autoManualMode = false;
        property.absValue = value;
        //property.valueA = value*2; //red
        //property.valueB = 777; //blue
        error = cam.SetProperty(&property);
        //std::cout<<"===SetProperty: "<<error.GetDescription()<<std::endl;
//        error = cam.StopCapture();
//        std::cout<<"===stop: "<<error.GetDescription()<<std::endl;
//        error = cam.StartCapture();
//        std::cout<<"===start: "<<error.GetDescription()<<std::endl;
    }
//    FlyCapture2::Property pProp;
//    pProp.type = FlyCapture2::PropertyType::BRIGHTNESS;

//    pProp.onOff=true;
//    pProp.valueA = value;
//    std::cout<<pProp.valueA<<std::endl;
//    cam.SetProperty(&pProp);
}

void CCamera::setShutter(int value)
{
    //std::cout<<"setShutter value: "<<value<<std::endl;
    //std::cout<<"setShutter mShutter: "<<mlShutter<<std::endl;
    if(value != mlShutter)
    {
        mlShutter = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::SHUTTER;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setGain(double value)
{
    //std::cout<<"setGain value: "<<value<<std::endl;
    //std::cout<<"setGain mGain: "<<mlGain<<std::endl;
    if(value != mlGain)
    {
        mlGain = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::GAIN;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setExposure(double value)
{
    //std::cout<<"setExposure value: "<<value<<std::endl;
    //std::cout<<"setExposure mExposure: "<<mlExposure<<std::endl;
    if(value != mlExposure)
    {
        mlExposure = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::AUTO_EXPOSURE;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setSharpness(double value)
{
    //std::cout<<"setSharpness value: "<<value<<std::endl;
    //std::cout<<"setSharpness mSharpness: "<<mlSharpness<<std::endl;
    if(value != mlSharpness)
    {
        mlSharpness = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::SHARPNESS;
        property.onOff = true;
        property.autoManualMode = false;
        //property.absControl = true;
        property.valueA = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setGamma(double value)
{
    //std::cout<<"setGamma value: "<<value<<std::endl;
    //std::cout<<"setGamma mGamma: "<<mlGamma<<std::endl;
    if(value != mlGamma)
    {
        mlGamma = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::GAMMA;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setWhiteBalance(int red, int blue)
{
//    std::cout<<"setWhiteBalance red: "<<red<<std::endl;
//    std::cout<<"setWhiteBalance blue: "<<blue<<std::endl;
//    std::cout<<"setWhiteBalance mRed: "<<mlRed<<std::endl;
//    std::cout<<"setWhiteBalance mBlue: "<<mlBlue<<std::endl;

    if((red != mlRed)||(blue != mlBlue))
    {
        mlRed = red;
        mlBlue = blue;

        FlyCapture2::Property property;
        property.type = FlyCapture2::WHITE_BALANCE;
        property.onOff = true;
        property.autoManualMode = false;
        property.valueA = red;
        property.valueB = blue;
        //property.absControl = true;
        //property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setHue(int value)
{
    //std::cout<<"setHue value: "<<value<<std::endl;
    //std::cout<<"setHue mHue: "<<mlHue<<std::endl;
    if(value != mlHue)
    {
        mlHue = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::HUE;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

void CCamera::setSaturation(int value)
{
    //std::cout<<"setSaturation value: "<<value<<std::endl;
    //std::cout<<"setSaturation mSaturation: "<<mlSaturation<<std::endl;
    if(value != mlSaturation)
    {
        mlSaturation = value;
        FlyCapture2::Property property;
        property.type = FlyCapture2::SATURATION;
        property.onOff = true;
        property.autoManualMode = false;
        property.absControl = true;
        property.absValue = value;
        error = cam.SetProperty(&property);
    }
}

//BRIGHTNESS, /**< Brightness. */
//AUTO_EXPOSURE, /**< Auto exposure. */
//SHARPNESS, /**< Sharpness */
//WHITE_BALANCE, /**< White balance. */
//HUE, /**< Hue. */
//SATURATION, /**< Saturation. */
//GAMMA, /**< Gamma. */
//IRIS, /**< Iris. */
//FOCUS, /**< Focus. */
//ZOOM, /**< Zoom. */
//PAN, /**< Pan. */
//TILT, /**< Tilt. */
//SHUTTER, /**< Shutter. */
//GAIN, /**< Gain. */
//TRIGGER_MODE, /**< Trigger mode. */
//TRIGGER_DELAY, /**< Trigger delay. */
//FRAME_RATE, /**< Frame rate. */
//TEMPERATURE, /**< Temperature. */
//UNSPECIFIED_PROPERTY_TYPE, /**< Unspecified property type. */
//PROPERTY_TYPE_FORCE_32BITS = FULL_32BIT_VALUE

IplImage* CCamera::ConvertImageToOpenCV(FlyCapture2::Image* pImage)
{
    //DEBUG("CCamera::ConvertImageToOpenCV()");
    mySize.height = pImage->GetRows();
    mySize.width = pImage->GetCols();
    colorImage.ReleaseBuffer();
    cvImage = cvCreateImageHeader(mySize, 8, 3 );
    cvImage->depth = IPL_DEPTH_8U;
    cvImage->nChannels = 3;
    pImage->Convert(FlyCapture2::PIXEL_FORMAT_BGR, &colorImage);
    cvImage->width = colorImage.GetCols();
    cvImage->height = colorImage.GetRows();
    cvImage->widthStep = colorImage.GetStride();
    cvImage->origin = 0;
    cvImage->imageDataOrigin = (char*)colorImage.GetData();
    cvImage->imageData = (char*)(colorImage.GetData());
    cvImage->widthStep = colorImage.GetStride();
    cvImage->nSize = sizeof (IplImage);
    cvImage->imageSize = cvImage->height * cvImage->widthStep;
    return cvImage;
}
