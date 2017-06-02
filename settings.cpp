 #include "settings.h"

////////////////////////////////////
/// \brief CSettings::CSettings
/// \param parent
///
CSettings::CSettings(QObject *parent) : QObject(parent)
{
    qDebug()<<"CSettings::CSettings()";
}

////////////////////////////////////
/// \brief CSettings::mBrightness
///
double CSettings::mBrightness(4.785);
void CSettings::SetBrightness(int value)
{
    mBrightness = value / 1000.;
    qDebug()<<"CSettings::mBrightness = " << mBrightness;
}

////////////////////////////////////
/// \brief CSettings::mShutter
///
double CSettings::mShutter(0.251);
void CSettings::SetShutter(int value)
{
    CSettings::mShutter = value / 1000.;
    qDebug()<<"CSettings::mShutter = " << mShutter;
}

////////////////////////////////////
/// \brief CSettings::mGain
///
double CSettings::mGain(13.148);
void CSettings::SetGain(int value)
{
    CSettings::mGain = value / 1000.;
    qDebug()<<"CSettings::mGain = " << mGain;
}

////////////////////////////////////
/// \brief CSettings::mExposure
///
double CSettings::mExposure(-7.585);
void CSettings::SetExposure(int value)
{
    mExposure = value / 1000.;
    qDebug()<<"CSettings::mExposure = " << mExposure;
}

////////////////////////////////////
/// \brief CSettings::mSharpness
///
int CSettings::mSharpness(1024);
void CSettings::SetSharpness(int value)
{
    CSettings::mSharpness = value;
    qDebug()<<"CSettings::mSharpness = " << mSharpness;
}

////////////////////////////////////
/// \brief CSettings::mHue
///
int CSettings::mHue(0);
void CSettings::SetHue(int value)
{
    CSettings::mHue = value;
    qDebug()<<"CSettings::mHue = " << mHue;
}

////////////////////////////////////
/// \brief CSettings::mSaturation
///
int CSettings::mSaturation(100);
void CSettings::SetSaturation(int value)
{
    CSettings::mSaturation = value;
    qDebug()<<"CSettings::mSaturation = " << mSaturation;
}

////////////////////////////////////
/// \brief CSettings::mGamma
///
double CSettings::mGamma(1);
void CSettings::SetGamma(int value)
{
    CSettings::mGamma = value / 1000.;
    qDebug()<<"CSettings::mGamma = " << mGamma;
}

////////////////////////////////////
/// \brief CSettings::mWBRed
///
int CSettings::mWBRed(0);
void CSettings::SetRed(int value)
{
    CSettings::mWBRed = value;
    qDebug()<<"CSettings::mRed = " << mWBRed;
}

////////////////////////////////////
/// \brief CSettings::mWBBlue
///
int CSettings::mWBBlue(0);
void CSettings::SetBlue(int value)
{
    CSettings::mWBBlue = value;
    qDebug()<<"CSettings::mBlue = " << mWBBlue;
}

////////////////////////////////////
/// \brief CSettings::mSimilar
///
bool CSettings::mSimilar(false);
void CSettings::SetSimilar(int value)
{
    mSimilar = value;
    qDebug()<<"CSettings::SetSimilar = " << mSimilar;
}

////////////////////////////////////
/// \brief CSettings::mContrast
///
bool CSettings::mContrast(false);
void CSettings::SetContrast(int value)
{
    mContrast=value;
    qDebug()<<"CSettings::SetContrast = " << mContrast;
}

////////////////////////////////////
/// \brief CSettings::mBinary
///
bool CSettings::mBinary(false);
void CSettings::SetBinary(int value)
{
    mBinary=value;
    qDebug()<<"CSettings::SetBinary = " << mBinary;
}

////////////////////////////////////
/// \brief CSettings::mContour
///
bool CSettings::mContour(false);
void CSettings::SetContour(int value)
{
    mContour=value;
    qDebug()<<"CSettings::SetContour = " << mContour;
}

////////////////////////////////////
/// \brief CSettings::mSaveImage
///
bool CSettings::mSaveImage(false);
void CSettings::SetSaveImage(int value)
{
    mSaveImage = value;
    qDebug()<<"CSettings::SetSaveImage = " << mSaveImage;
}

////////////////////////////////////
/// \brief CSettings::mDlina
///
double CSettings::mDelContour(1.42);
void CSettings::SetDelContour(double value)
{
    mDelContour = value;
    qDebug()<<"CSettings::SetDelContour = " << mDelContour;
}

////////////////////////////////////
/// \brief CSettings::mDlina
///
int CSettings::mDlina(100);
void CSettings::SetDlina(int value)
{
    mDlina = value;
    qDebug()<<"CSettings::SetDlina = " << mDlina;
}

////////////////////////////////////
/// \brief CSettings::mMinimumDistance2
///
double CSettings::mMinimumDistance2(-5);
void CSettings::SetMinimumDistance2(double value)
{
    mMinimumDistance2 = value;
    qDebug()<<"CSettings::SetMinimumDistance2 = " << mMinimumDistance2;
}

////////////////////////////////////
/// \brief CSettings::mMinimumDistance1
///
double CSettings::mMinimumDistance1(-5);
void CSettings::SetMinimumDistance1(double value)
{
    mMinimumDistance1 = value;
    qDebug()<<"CSettings::SetMinimumDistance1 = " << mMinimumDistance1;
}

////////////////////////////////////
/// \brief CSettings::mMaximumDistance
///
double CSettings::mMaximumDistance(6);
void CSettings::SetMaximumDistance(double value)
{
    mMaximumDistance = value;
    qDebug()<<"CSettings::SetMaximumDistance = " << mMaximumDistance;
}

////////////////////////////////////
/// \brief CSettings::mShablonSquere
///
double CSettings::mShablonSquere(90000);
void CSettings::SetShablonSquere(double value)
{
    mShablonSquere = value;
    qDebug()<<"CSettings::SetShablonSquere = " << mShablonSquere;
}

////////////////////////////////////
/// \brief CSettings::mShablonDl
///
double CSettings::mShablonDl(700);
void CSettings::SetShablonDl(double value)
{
    mShablonDl = value;
    qDebug()<<"CSettings::SetShablonDl = " << mShablonDl;
}

////////////////////////////////////
/// \brief CSettings::mEach
///
int CSettings::mEach(0);
void CSettings::SetEach(int value)
{
    mEach = value;
    qDebug()<<"CSettings::SetEach = " << mEach;
}
