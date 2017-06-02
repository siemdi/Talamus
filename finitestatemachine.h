#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include <QObject>
#include "camera.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QElapsedTimer>
#include <stdio.h>
#include <iostream>
#include "settings.h"
#include <math.h>
#include <QFile>
class CFiniteStateMachine
        : public QObject
{
    Q_OBJECT
public:
    explicit CFiniteStateMachine(QObject *parent = 0);

private:
    CCamera         *camera;
    void            rubberControl(char* b, IplImage* imageF);
    void            FillIn(const int& w, const int& h, IplImage* Ris, const int& col);
    void            kontrast1(IplImage *colCaps, IplImage *KontrastCaps, const int& MaskSize);
    void            BinCaps(IplImage *colCaps, IplImage *BinCaps, const int& MaskSize);
    IplImage        test_math;
    double          GetTickCount();
    enum            states {Camera, Math, Logging, Idle, Settings} EState;

    QElapsedTimer   m_timer;
    unsigned int    m_pause;
    unsigned int    m_time;
    unsigned int    m_elapsed;

    QElapsedTimer   m_timer2;
    unsigned int    m_pause2;
    unsigned int    m_time2;
    unsigned int    m_elapsed2;

    unsigned int    m_time3;
    unsigned int    m_elapsed3;

    unsigned int    m_time4;
    unsigned int    m_elapsed4;

    char            str[11];
    int             m_counter;

    QFile logi;//("/home/buildmachine/build-Widget-Desktop_Qt_5_8_0_GCC_64bit-Release/Logs.txt");
    //logi.open(QIODevice::ReadWrite);
    QTextStream logs_stream;//(&file);
    //stream << "logs_stream" << endl;

//signals:
//    void    signal_SendImage(IplImage);

public slots:
    void    Start();
};

#endif // FINITESTATEMACHINE_H
