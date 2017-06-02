#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>

class CSettings
        : public QObject
{
    Q_OBJECT
public:
    explicit CSettings(QObject *parent = 0);

signals:

public slots:
    void SetBrightness(int value);
    void SetShutter(int value);
    void SetGain(int value);
    void SetExposure(int value);
    void SetSharpness(int value);
    void SetGamma(int value);
    void SetRed(int value);
    void SetBlue(int value);
    void SetHue(int value);
    void SetSaturation(int value);
    void SetSimilar(int value);
    void SetContrast(int value);
    void SetBinary(int value);
    void SetContour(int value);
    void SetSaveImage(int value);
    void SetEach(int value);
    void SetShablonDl(double value);
    void SetShablonSquere(double value);
    void SetMaximumDistance(double value);
    void SetMinimumDistance1(double value);
    void SetMinimumDistance2(double value);
    void SetDlina(int value);
    void SetDelContour(double value);

public:
    static double mBrightness;
    static double mShutter;
    static double mGain;
    static double mExposure;
    static int mSharpness;
    static double mGamma;
    static int mWBRed;
    static int mWBBlue;
    static int mHue;
    static int mSaturation;
    static bool mSimilar;
    static bool mContrast;
    static bool mBinary;
    static bool mContour;
    static bool mSaveImage;
    static int mEach;
    static double mShablonDl;
    static double mShablonSquere;
    static double mMaximumDistance;
    static double mMinimumDistance1;
    static double mMinimumDistance2;
    static int mDlina;
    static double mDelContour;
};

#endif // SETTINGS_H
