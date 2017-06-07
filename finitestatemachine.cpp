#include "finitestatemachine.h"
CFiniteStateMachine::CFiniteStateMachine(QObject *parent)
    : QObject(parent)
    , EState(Camera)
    , m_pause(0)
    , m_counter(0)
    , logi("/home/buildmachine/build-Widget-Desktop_Qt_5_8_0_GCC_64bit-Release/Logs.txt")
    , logs_stream (&logi)
{
    std::cout<<"CFiniteStateMachine::CFiniteStateMachine"<<std::endl;
    camera = new CCamera();
    logi.open(QIODevice::ReadWrite);
}

void CFiniteStateMachine::Start()
{
    std::cout<<"CFiniteStateMachine::Start"<<std::endl;
    m_timer.start();
    m_time = 1;
    m_time = m_timer.elapsed();

    //m_timer2.start();
    m_time2 = 1;
    m_time2 = m_timer2.elapsed();

    QString filename = "/home/buildmachine/build-Widget-Desktop_Qt_5_8_0_GCC_64bit-Release/Times.txt";
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);
    stream << "something" << endl;


    //char *result="";
    //cvNamedWindow("test_math",CV_WINDOW_AUTOSIZE);
    //bool first=true;
    while(true)
    {
        switch (EState)
        {
            case Logging:
            {
                break;
            }
            case Settings:
            {
                EState=Camera;
                break;
            }
            case Camera:
            {
                test_math = camera->GetImageFromCam();

                m_time3 = GetTickCount();
                rubberControl("logs", &test_math);
                m_elapsed3 = GetTickCount()-m_time3;
                std::cout<< "WORK TIME: "<< m_elapsed3 << std::endl;


                //stream << m_elapsed2 << endl;



//                if(!first)
//                {
                    //rubberControl(result, &test_math);
//                    std::cout<<"result: "<<result<<std::endl;
//                }
//                if(first)
//                {
//                    std::cout<<"FIRST"<<std::endl;
//                    first=false;
//                }





                //cvRelease(test_math);
//                if( !test_math )
//                {
//                    break;
//                }
//                else
//                {

                    //cvWaitKey(33);
                    EState=Idle;
//                }
                break;
            }
            case Idle:
            {
                m_elapsed = m_timer.elapsed() - m_time;
                if(m_elapsed>m_pause)
                {
                    std::cout<<"elapsed: "<<m_elapsed<<std::endl;
                    m_time = m_timer.elapsed();
                    camera->setBrightness(CSettings::mBrightness);
                    camera->setShutter(CSettings::mShutter);
                    camera->setGain(CSettings::mGain);
                    camera->setExposure(CSettings::mExposure);
                    camera->setSharpness(CSettings::mSharpness);
                    camera->setGamma(CSettings::mGamma);
                    camera->setWhiteBalance(CSettings::mWBRed, CSettings::mWBBlue);
                    camera->setHue(CSettings::mHue);
                    camera->setSaturation(CSettings::mSaturation);
                    EState=Camera;
                }
                break;
            }
            case Math:
            {
                break;
            }
        }
    }
}
double CFiniteStateMachine::GetTickCount()
{
  struct timespec now;
  if (clock_gettime(CLOCK_MONOTONIC, &now))
    return 0;
  return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
}
void CFiniteStateMachine::rubberControl(char* b, IplImage* imageF)
{
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();

    double shablonDL = CSettings::mShablonDl;
    double shablonSquere = CSettings::mShablonSquere;
    double maxDist1 = CSettings::mMaximumDistance;
    double MinDist1 = CSettings::mMinimumDistance1;
    double MinDist2 = CSettings::mMinimumDistance2;
    int dlina1 = CSettings::mDlina;
    double delkontour = CSettings::mDelContour;

    //double shablonDist = 1000;
    double shablonlArea=0;
    //double fourPI;
    // �������� �����������
    //char b[] = "0.bmp";

    // logging------------------------------------
    char fname[256];
    strcpy(fname, b);
    strcat(fname, ".txt");

    FILE *f;
    f = fopen(fname, "w");

    if (f == 0)
    {
        printf("�� ���� ������� ���� '%s'",fname);
        //return EXIT_FAILURE;
    }

    //char out[20];
    //----------------------------------------------

    //IplImage* image = cvLoadImage(b);
    IplImage* IBinary;
    IplImage* ImgKontrast;
    // �������� - ��������� �� �����������
    assert(imageF != 0);
    //cvNamedWindow("�������� �����������", CV_WINDOW_AUTOSIZE);
    //cvShowImage("�������� �����������", image);
    //cvWaitKey(0);
    IplImage* image;
    //IplImage* image1;
    //cvSetImageROI(imageF, cvRect(160, 50, (1150 - 160), (960 - 50)));
    //image1 = cvCreateImage(cvSize((1150 - 160), (960 - 50)), imageF->depth, imageF->nChannels);
    //cvCopy(imageF, image1);
    //cvResetImageROI(imageF);

    //cvNamedWindow("�������� ����������� image1", CV_WINDOW_AUTOSIZE);
    //cvShowImage("�������� ����������� image1", image1);
    //cvWaitKey(0);

    //
    // Resize
    //
    //image = cvCreateImage(cvSize(image1->width / 2, image1->height / 2), image1->depth, image1->nChannels);
    //cvResize(image1, image, 3);
    image = cvCreateImage(cvSize(imageF->width / 2, imageF->height / 2), imageF->depth, imageF->nChannels);
    cvResize(imageF, image, 2);

    if((CSettings::mSimilar == true)&&(m_counter==CSettings::mEach))
    {
        cvNamedWindow("similar image", CV_WINDOW_AUTOSIZE);
        cvShowImage("similar image", image);
    }

    //cvWaitKey(0);
    //
    //printf("%d  %d", image->width, image->height);
    //
    IBinary = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 1);
    ImgKontrast = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 1);






    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >start TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();
    FillIn(image->width, image->height, ImgKontrast, 0);
    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >FillIn 1 TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();
    kontrast1(image, ImgKontrast, 3);
    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >Kontrast TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();




    if((CSettings::mContrast == true)&&(m_counter==CSettings::mEach))
    {
        cvNamedWindow("Contrast image", CV_WINDOW_AUTOSIZE);
        cvShowImage("Contrast image", ImgKontrast);
    }
    //cvWaitKey(0);
    //------------------------------------------------
    IplImage* Fmedian;
    Fmedian = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 1);
    cvSmooth(ImgKontrast, Fmedian, CV_GAUSSIAN, 9, 9);
//	cvNamedWindow(" Median", CV_WINDOW_AUTOSIZE);
//	cvShowImage(" Median", Fmedian);
//	cvWaitKey(0);

    //BinCaps(ImgKontrast, IBinary, 3);
    cvThreshold(Fmedian, IBinary, 50, 255, 8);
    cvReleaseImage(&Fmedian);

    if((CSettings::mBinary == true)&&(m_counter==CSettings::mEach))
    {
        cvNamedWindow("Binari", CV_WINDOW_AUTOSIZE);
        cvShowImage("Binari", IBinary);
    }
   // cvWaitKey(0);
    //
    IplImage *IBinaryCopy;
    IplImage *IBinaryCopy2;
    IBinaryCopy = cvCloneImage(IBinary);
    IBinaryCopy2 = cvCloneImage(IBinary);
//	cvNamedWindow("BinariCopy", CV_WINDOW_AUTOSIZE);
//	cvShowImage("BinariCopy", IBinaryCopy);
//	cvWaitKey(0);
//
//-----------------------------------------------
// �������� ���������� ��� �������� ��������
    CvMemStorage* kontayner = cvCreateMemStorage(0);
    // ��������� �� ������ ��������� ������
    CvSeq* contour_1;
//	 IplImage* dst = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
     cvFindContours(IBinary, kontayner, &contour_1, sizeof(CvContour), CV_RETR_EXTERNAL /*CV_RETR_LIST*/, CV_CHAIN_APPROX_SIMPLE/*CV_CHAIN_APPROX_TC89_L1  CV_LINK_RUNS*/);
    //���������� ��������
    //char a[10];
    int i = 1;
    double MaxDlina = 0;
    for (; contour_1 != 0; contour_1 = contour_1->h_next)
    {
        // ����� ������������ ������  �������
        //printf("i= %d\n", i);
        double dlina = cvContourPerimeter(contour_1);
        //int i = 0;
        if (MaxDlina <= dlina){
            MaxDlina = dlina;
            //_itoa(i,a,2);
            //printf("%d  %f\n", i, dlina); // /2/M_PI
            //cvDrawContours(dst, contour_1, CV_RGB(255, 255, 255), CV_RGB(255, 255, 255), 0, 1, 8);
            //cvNamedWindow(a, CV_WINDOW_AUTOSIZE);
            //cvShowImage(a, dst);
            //cvWaitKey(0);
        }
        //i++;
    }
    printf("Max  %f\n", MaxDlina);
    logs_stream<<"Max: "<< MaxDlina <<endl;
    fprintf(f, "Maxdlina= %f\n", MaxDlina);
    IplImage* dstMaxKont = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);




    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >Two block TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();
    FillIn(image->width, image->height, dstMaxKont, 0);
    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >FillIn 2 TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time2 = GetTickCount();

    // ���� ������������ ������ ������� ������ ��������� ����� �� ������ ��� �������
    // ����� ������� � ������������ �������
    if (MaxDlina > shablonDL){
        cvFindContours(IBinaryCopy, kontayner, &contour_1, sizeof(CvContour), CV_RETR_TREE /*CV_RETR_LIST*/, CV_CHAIN_APPROX_SIMPLE /*CV_LINK_RUNS*/);
        for (; contour_1 != 0; contour_1 = contour_1->h_next)
        {
            // ����� ������������ ������  �������
            //printf("i= %d\n", i);
            double dlina = cvContourPerimeter(contour_1);
            //int i = 0;
            if (MaxDlina == dlina){
                //_itoa(i, a, 2);
                //printf("length=  %f\n", dlina); // /2/M_PI
                shablonlArea = cvContourArea(contour_1);
                cvDrawContours(dstMaxKont, contour_1, cvScalarAll(255), cvScalarAll(255), 0, 1, 8);
         }
            //i++;
        }
        if((CSettings::mContour == true)&&(m_counter==CSettings::mEach))
        {
            cvNamedWindow("External", CV_WINDOW_AUTOSIZE);
            cvShowImage("External", dstMaxKont);
        }

        if(m_counter==CSettings::mEach)
        {
            m_counter==0;
        }
        else
        {
            m_counter++;
        }
        //cvWaitKey(0);
        //fprintf(f, "MaxDl= %f\n", MaxDlina);
        //printf("%f\n", MaxDlina); // /2/M_PI
        //
        int ww = dstMaxKont->width;
        int hh = dstMaxKont->height;
        int minY = 100000;
        int minX = 100000;
        int maxY = -100000;
        int maxX = -100000;
        int r;
        uchar* ptr;

        //
        for (int y = 0; y < hh; ++y)
        {
            ptr = (uchar*)(dstMaxKont->imageData + y * dstMaxKont->widthStep); // ��������� �� ������ ������ 'y'
            for (int x = 0; x < ww; ++x)
            {
                r = ptr[x];
                //g = ptr[3 * x + 1];
                //bb = ptr[3 * x + 2];

                if (r == 255){
                    if (x<minX) minX = x;
                    if (x>maxX) maxX = x;
                    if (y<minY) minY = y;
                    if (y>maxY) maxY = y;

                }

            }
        }
        // ���������� ��������������� ������ ROI
        double xCentr, yCentr;
        minY = minY - 2;
        maxY = maxY + 2;
        minX = minX - 2;
        maxX = maxX + 2;
        xCentr = (maxX - minX) / 2;
        yCentr = (maxY - minY) / 2;
        //����� ����������� ROI
        cvSetImageROI(IBinaryCopy2, cvRect(minX, minY, maxX - minX, maxY - minY));
        //
        //cvNamedWindow("�������� �������1_ROI", CV_WINDOW_AUTOSIZE);
        //cvShowImage("�������� �������1_ROI", dstMaxKont);
        //cvWaitKey(0);
        IplImage* ROIBinary;
        ROIBinary = cvCreateImage(cvSize((maxX - minX), (maxY - minY)), dstMaxKont->depth, dstMaxKont->nChannels);
        cvCopy(IBinaryCopy2, ROIBinary);
        cvResetImageROI(IBinaryCopy2);
        IplImage* ROIMaxKont;
        ROIMaxKont = cvCreateImage(cvSize((maxX - minX), (maxY - minY)), dstMaxKont->depth, dstMaxKont->nChannels);
        cvSetImageROI(dstMaxKont, cvRect(minX, minY, maxX - minX, maxY - minY));
        cvCopy(dstMaxKont, ROIMaxKont);
        cvResetImageROI(dstMaxKont);

        //cvNamedWindow("roibinary", CV_WINDOW_AUTOSIZE);
        //cvShowImage("roibinary", ROIBinary);
        //cvWaitKey(0);

        //cvNamedWindow("ROIMaxKont", CV_WINDOW_AUTOSIZE);
        //cvShowImage("ROIMaxKont", ROIMaxKont);
        //cvWaitKey(0);

        printf("ROIMaxKontWidth = %d  ROIMaxKonHeight = %d\n", ROIMaxKont->width, ROIMaxKont->height);
        logs_stream<<"ROIMaxKontWidth = "<< ROIMaxKont->width <<   " ROIMaxKonHeight = "<<  ROIMaxKont->height <<endl;
        double cY = 0, cX = 0, /*cY1 = 0,*/ cX1 = 0;
        double nt = 0;
        double maxDist = -100000;
        double MinDist = 10000;
        hh = ROIMaxKont->height;
        ww = ROIMaxKont->width;

        int radius = (xCentr > yCentr) ? (int)yCentr : (int)xCentr;
        radius = radius - 2;

        // �������� ������
        CvPoint pt;
        pt.x = (int)xCentr;
        pt.y = (int)yCentr;

//        int thickness = 1;
//        int lineType = 8;

        //cvCircle(ROIMaxKont, pt, radius, cvScalar(150, 150, 150), thickness, lineType);
        //cvNamedWindow("roicircle", CV_WINDOW_AUTOSIZE);
        //cvShowImage("roicircle", ROIMaxKont);
        //cvWaitKey(0);
        //


        //radius = (int)(MaxDlina/2/M_PI+0.5);
        printf("R = %d\n", radius);
        logs_stream<<"R= "<<radius<<endl;
        printf("xCentr = %f  yCentr = %f\n", xCentr, yCentr);
        logs_stream<<"xCentr = " << xCentr <<" yCentr= "<< yCentr <<endl;
//		cvWaitKey(0);
        for (int y = 0; y < hh; ++y)
        {
            ptr = (uchar*)(ROIMaxKont->imageData + y * ROIMaxKont->widthStep); // ��������� �� ������ ������ 'y'
            for (int x = 0; x < ww; ++x)
            {
                r = ptr[x];
                //g = ptr[3 * x + 1];
                //bb = ptr[3 * x + 2];
                //if ((x != 0) || (x != ww - 1) || (y != 0) || (y != hh - 1))
                if ((r == 255) /*&& (g == 255) && (bb == 255)*/){
                    cX = cX + x;
                    cY = cY + y;
                    nt = nt + 1;
                    // !!!� ���������� ����� ������� ������������� � ������������� ���������� �� �������!!!
                    // ���� �� ������� �����, �� ����� ������������ ���� +, ���� -
                    cX1 = (x - xCentr)*(x - xCentr) + (y - yCentr)*(y - yCentr);
                    cX1 = abs(radius - sqrt(cX1));
                    //cY1 = cY1 + cX1;
                    maxDist = (cX1 > maxDist) ? cX1 : maxDist;
                    MinDist = (cX1 < MinDist) ? cX1 : MinDist;
                }

            }
        }
        fprintf(f, "minD= %f   maxD= %f\n", MinDist, maxDist);
        cX = cX / nt;
        cY = cY / nt;
//        double gY = hh / 2;
//        double gX = ww / 2;
        //printf("minX= %d   maxX= %d\n", minX, maxX);
        //printf("minY= %d   maxY= %d\n", minY, maxY);
        //printf("cY= %f   cX= %f\n", cY, cX);
        //printf("gY= %f   gX= %f\n", gY, gX);
        //printf("gY-cY= %f   gX-cX= %f\n", gY - cY, gX - cX);

        //fprintf(f, "minX= %d   maxX= %d\n", minX, maxX);
        //fprintf(f, "minY= %d   maxY= %d\n", minY, maxY);
        //fprintf(f, "cY= %f   cX= %f\n", cY, cX);
        //fprintf(f, "gY= %f   gX= %f\n", gY, gX);
        //fprintf(f, "gY-cY= %f   gX-cX= %f\n", gY - cY, gX - cX);
        //fprintf(f, "cY1= %f   maxDist= %f\n", cY1, maxDist);

        // ���� ������� ��� ������ �������� ����� ��� �������
        double SRoi = (maxY - minY)*(maxX - minX);
        fprintf(f, "SRoi= %f\n", SRoi);
        printf("S= %d\n", (maxY - minY)*(maxX - minX));
        logs_stream<<"S= " << (maxY - minY)*(maxX - minX) <<endl;
            if (((maxY - minY)*(maxX - minX)) > shablonSquere){

            if ((maxDist<=maxDist1)&&(MinDist>=MinDist1)) {
                // ����������� ���������� ������ ������
                // ROI ��������� ��������� ��������
                //cvNamedWindow("ROIBinary", CV_WINDOW_AUTOSIZE);
                //cvShowImage("ROIBinary", ROIBinary);
                //cvWaitKey(0);

                cvFindContours(ROIBinary, kontayner, &contour_1, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE/*CV_LINK_RUNS*/);


        //IplImage* dst1[10];
        double kontour[10];
        double kontour_s[10];
        double kontour_char_razmer[10];
        i = 0;
        double dlina, plowad;
        for (; contour_1 != 0; contour_1 = contour_1->h_next)
        {
            // ����� ������������ ������  �������
            //printf("i= %d\n", i);
            dlina = cvContourPerimeter(contour_1);
            plowad = cvContourArea(contour_1);
            //int i = 0;
            if (dlina>dlina1){
        //		dst1[i] = cvCreateImage(cvGetSize(dst112), IPL_DEPTH_8U, 1);
        //		_itoa(i,a,2);
                //printf("%d  %f\n", i, dlina); // /2/M_PI
                //		cvDrawContours(dst1[i], contour_1, cvScalarAll(255), cvScalarAll(255), 0, 1, 8);
                //cvDrawContours(dst, contour_1, CV_RGB(255, 255, 255), CV_RGB(255, 255, 255), 0, 1, 8);
        //		cvNamedWindow(a, CV_WINDOW_AUTOSIZE);
        //		cvShowImage(a, dst1[i]);
        //		cvWaitKey(0);
        //		printf("%d  %f\n", i, dlina);
                kontour[i]=dlina;
                kontour_s[i]=plowad;
                kontour_char_razmer[i]=2*sqrt((dlina/2.)*(dlina/2.)-2*plowad);
                i++;
        //        fprintf(f, "Nkount=%d dlina= %f\n", i,dlina);
                fprintf(f, "Nkount= %d dlina= %f plowad= %f kontour_char_razmer/ kontour= %f\n", i,dlina,plowad, (kontour_char_razmer[i-1] / kontour[i-1]));
                printf("Nkount= %d dlina= %f plowad= %f kontour_char_razmer/ kontour= %f\n", i,dlina,plowad, (kontour_char_razmer[i-1] / kontour[i-1]));
                logs_stream<<"Nkount= "<< i<< " dlina= "<< dlina<<" plowad= "<<plowad <<" kontour_char_razmer/ kontour= "<<(kontour_char_razmer[i-1] / kontour[i-1])<<endl;
            }

        }

        fprintf(f, "kontour[0] / kontour[1]= %f\n", (kontour[0] / kontour[1]));
        double delkontour1;
//        double temp_kontour;
        if (i>=3)
        {
//            for(int ii=1;ii<=i;ii++)
//            {
//                for(int jj=1;jj<i-ii;jj++)
//                {
//                    if(kontour[jj-1]<kontour[jj])
//                    {
//                      temp_kontour=kontour[jj-1];
//                      kontour[jj-1]=kontour[jj];
//                      kontour[jj]=kontour[jj-1];

//                    }
//                }
//            }
            for(int ii=1;ii<=i-2;ii++)
            {
                delkontour1=kontour_char_razmer[ii-1] / kontour[ii-1];
                if ((delkontour1<0.9757)||(delkontour1>0.9994))
                {
                    printf("\n-2 - Fragments of gasket \n");
                    logs_stream<<"\n-2 - Fragments of gasket \n"<<endl;
                }
                else
                {
                    printf("\n1 - OK \n");
                    logs_stream<<"\n1 - OK \n"<<endl;
                }
            }
        }
        else
            if ((i == 2) && (kontour[0] / kontour[1] > delkontour))
            {
                printf("\n-2 - Fragments of gasket \n");
                logs_stream<<"\n-2 - Fragments of gasket \n"<<endl;
            }
            else
            {
                printf("\n1 - OK \n");
                logs_stream<<"\n1 - OK \n"<<endl;
            }
            //fprintf(f, "%f\n", maxDist);
        }

            if ((maxDist>maxDist1)||(MinDist<=MinDist2))
            {
                printf("\n-1 - cap with kink or other geometry fault\n");
                logs_stream<<"\n-1 - cap with kink or other geometry fault\n"<<endl;
            //	fprintf(f, "%f\n", maxDist);
            }

        }
        else
            {
                printf("\n0 - no gasket or untypical geometry problem\n");
                logs_stream<<"\n0 - no gasket or untypical geometry problem\n"<<endl;
            }

        fclose(f);
        //�������� �����������
        //
        //cvReleaseImage(&image); - �������� � ��������� � ��������

//		cvReleaseImage(&cannyContuor);
//		cvReleaseImage(&dlinContuor);
//		cvReleaseImage(&dst11);
//		cvReleaseImage(&dstMaxKont);
//		cvReleaseImage(&dst1);


        cvReleaseMemStorage(&kontayner);

    }
    else{ printf("\n0 - no gasket or untypical geometry problem\n");

        logs_stream<<"\n0 - no gasket or untypical geometry problem\n"<<endl;
    }



    m_elapsed2 = GetTickCount()-m_time2;
    std::cout<< "==== >3 block TIME: "<< m_elapsed2 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    //cvDestroyAllWindows();
}

//--------------------------------------------------------------------------------------------

// ������� ����������� (IPL_DEPTH_8U) �����//(IPL_DEPTH_32S, IPL_DEPTH_32F) �����
void CFiniteStateMachine::FillIn(const int& w, const int& h, IplImage* Ris, const int& col)
{
    int x, y;
    uchar* ptr;

    for (y = 0; y < h; ++y)
    {
        ptr = (uchar*)(Ris->imageData + y * Ris->widthStep); // ��������� �� ������ ������ 'y'
        for (x = 0; x < w; ++x)
        {
            // � IplImage ����� ������� BGR
            ptr[x] = col;
            //ptr[3 * x] = col;
            //ptr[3 * x + 1] = col;
            //ptr[3 * x + 2] = col;
        }
    }
}
//---------------------------------------------------------------------------

// ���������������� ����������� �� ��������� �����������������������, ��������� �����-��������� ��� ���������� � �������
// ����� ����������� ������
void CFiniteStateMachine::kontrast1(IplImage *colCaps, IplImage *KontrastCaps, const int& MaskSize)
{
    double ngl, sgeomGl;
    int h, w, x, y, Kontrast;
    h = colCaps->height;
    w = colCaps->width;
    //
    double dlog;
    double** imgIntegral = new double*[h+1];
        for (x = 0; x < h+1; ++x)
        {
            imgIntegral[x] = new double[w+1];
        }

    //
    uchar *ptr, *ptr1, *ptr2, *ptrG;
    IplImage *Green;
    Green= cvCreateImage(cvSize(colCaps->width, colCaps->height), IPL_DEPTH_8U, 1);
    //���������� ����������� ���������������������
    //ngl = h*w;
    sgeomGl = 0;
    ngl = 0;
    double Nm = MaskSize*MaskSize;

    ////////////////////////////////////////////////////////////
    ///
    ////////////////////////////////////////////////////////////
    m_time4 = GetTickCount();
    //
    for (x=0;x<w+1;++x)
        imgIntegral[0][x] = 0;

    for (y=0;y<h+1;++y)
        imgIntegral[y][0] = 0;

    for (y = 0; y < h; ++y)
    {
        ptr = (uchar*)(colCaps->imageData + y * colCaps->widthStep); // ��������� �� ������ ������ 'y'
        ptr1 = (uchar*)(Green->imageData + y * Green->widthStep);
        //ptrG = (uchar*)(KontrastCaps->imageData + (y + 1) * KontrastCaps->widthStep);
        for (x = 0; x < w; ++x)
        {
        //	ptrG[x] = (int)(((255 - ptr[3 * x]) + (255 - ptr[3 * x + 1]))/2);
        //	sgeomGl = sgeomGl + log((double)(256 - ptr[3 * x+1]));
            float k=log(100);
            ptr1[x] = ptr[3 * x + 1];
            dlog = log((double)(1+ptr[3 * x + 1]));
            sgeomGl = sgeomGl + dlog;
            imgIntegral[y+1][x+1] = dlog;
            if (ptr[3 * x + 1] != 0) ngl = ngl + 1;
        }
    }


    //int h = 3, w = 4;


//    double imgIntegral[4][5] = {{0,0,0,0,0}
//                               ,{0,1,1,1,1}
//                               ,{0,1,1,1,1}
//                               ,{0,1,1,1,1}};

//    for (x = 1; x < w+1; ++x)
//        for (y = 1; y < h+1; ++h)
//        {
//            imgIntegral[y][x] = 1.0;
//        }


    for (int x = 2; x <= w; ++x)
            imgIntegral[1][x] = imgIntegral[1][x] + imgIntegral[1][x-1];

    for (int y = 2; y <= h; ++y)
        imgIntegral[y][1] = imgIntegral[y][1] + imgIntegral[y-1][1];

    for (int y = 2; y <= h; ++y)
        for (int x = 2; x <= w; ++x)
            imgIntegral[y][x] = imgIntegral[y][x] + imgIntegral[y][x-1] + imgIntegral[y-1][x] - imgIntegral[y-1][x-1];


    m_elapsed4 = GetTickCount()-m_time4;
    std::cout<< "==== >Kontrast 1 cycle TIME: "<< m_elapsed4 << std::endl;
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////

   // double ppprom = sgeomGl / ngl;
    sgeomGl = exp(sgeomGl / ngl);
    sgeomGl = 256 - sgeomGl;
    //���������������� ��������� �������

    double sgeom;
    double Br;
    int kkk =4;
    //���������������� ��������� �������
////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
    m_time4 = GetTickCount();
//    double composition1=0;
//    double composition2=0;
//    double composition3=0;
//
    int xintegral, yintegral;
    for (int y = 1; y < h-1; ++y)
    {
            // ��������� ��� ������ � �����������
            ptr = (uchar*)(Green->imageData + y * Green->widthStep); // ��������� �� ������ ������ 'y'
            //ptr1= (uchar*)(Green->imageData + (y+1) * Green->widthStep);
           // ptr2= (uchar*)(Green->imageData + (y+2) * Green->widthStep);
            //������ ������������������ �����������
            //ptrG = (uchar*)(KontrastCaps->imageData + (y+1) * KontrastCaps->widthStep);
            ptrG = (uchar*)(KontrastCaps->imageData + y * KontrastCaps->widthStep);
        for (int x = 1; x < w-1; ++x)
        {
            //sgeom = 1;
            //B component
            //sgeom = log((double)(256 - ptr[3 * x])) + log((double)(256 - ptr[3 * (x + 1)])) + log((double)(256 - ptr[3 * (x+2)]));
            //sgeom = sgeom + log((double)(256 - ptr1[3 * x])) + log((double)(256 - ptr1[3 * (x + 1)])) + log((double)(256 - ptr1[3 * (x + 2)]));
            //sgeom = sgeom + log((double)(256 - ptr2[3 * x])) + log((double)(256 - ptr2[3 * (x + 1)])) + log((double)(256 - ptr2[3 * (x + 2)]));
            //
            //sgeom = (double)((256 - ptr[3 * x])*(256 - ptr[3 * (x + 1)])*(256 - ptr[3 * (x + 2)]));
            //sgeom = sgeom * ((256 - ptr1[3 * x])*(256 - ptr1[3 * (x + 1)])*(256 - ptr1[3 * (x + 2)]));
            //sgeom = sgeom * ((256 - ptr2[3 * x])*(256 - ptr2[3 * (x + 1)])*(256 - ptr2[3 * (x + 2)]));
            //sgeom = log(sgeom);
            //G component
            //sgeom = (double)(256 - ptr[3 * x+1]) *(double)(256 - ptr[3 * (x + 1)+1]) * (double)(256 - ptr[3 * (x + 2)+1]);
            //sgeom = sgeom * (double)(256 - ptr1[3 * x+1]) * (double)(256 - ptr1[3 * (x + 1)+1]) * (double)(256 - ptr1[3 * (x + 2)]+1);
            //sgeom = sgeom * (double)(256 - ptr2[3 * x]+1) * (double)(256 - ptr2[3 * (x + 1)+1]) * (double)(256 - ptr2[3 * (x + 2)+1]);
            //
            //int intens = ptr[3 * x + 1];
            //sgeom = (double)(256 - ptr[3 * x + 1]) *(double)(256 - ptr[3 * (x + 1) + 1]) * (double)(256 - ptr[3 * (x + 2) + 1]);
            //sgeom = sgeom * (double)(256 - ptr1[3 * x + 1]) * (double)(256 - ptr1[3 * (x + 1) + 1]) * (double)(256 - ptr1[3 * (x + 2)] + 1);
            //sgeom = sgeom * (double)(256 - +ptr2[3 * x] + 1) * (double)(256 - ptr2[3 * (x + 1) + 1]) * (double)(256 - ptr2[3 * (x + 2) + 1]);
            //
//            composition1 = (256. - ptr[x]) *(256. - ptr[x + 1]) * (256. - ptr[x + 2]);
//            composition2 = (256. - ptr1[x]) * (256. - ptr1[x + 1]) * (256. - ptr1[x + 2]);
//            composition3 = (256. - ptr2[x]) * (256. - ptr2[x + 1]) * (256. - ptr2[x + 2]);
//            if(x==0)
//            {
//                composition3 = (256. - ptr[x+2])*(256. - ptr1[x+2])*(256. - ptr2[x+2]);
//                composition2 = (256. - ptr[x+1])*(256. - ptr1[x+1])*(256. - ptr2[x+1]);
//                composition1 = (256. - ptr[x])*(256. - ptr1[x])*(256. - ptr2[x]);
//            }
//            else
//            {
//                composition1 = composition2;
//                composition2 = composition3;
//                composition3 = (256. - ptr[x+2])*(256. - ptr1[x+2])*(256. - ptr2[x+2]);
//            }
//            sgeom = composition1 * composition2 * composition3;

//            sgeom = (double)(256 - ptr[x]) *(double)(256 - ptr[x + 1]) * (double)(256 - ptr[x + 2]);
//            sgeom = sgeom * (double)(256 - ptr1[x]) * (double)(256 - ptr1[x + 1]) * (double)(256 - ptr1[x + 2]);
//            sgeom = sgeom * (double)(256 - +ptr2[x]) * (double)(256 - ptr2[x + 1]) * (double)(256 - ptr2[x + 2]);
            //
            xintegral = x + 1;
            yintegral = y + 1;
            sgeom = (imgIntegral[yintegral+1][xintegral+1] + imgIntegral[yintegral-2][xintegral-2] - imgIntegral[yintegral-2][xintegral+1] - imgIntegral[yintegral+1][xintegral-2])/9.;
//            sgeom = log(sgeom)/Nm;
            sgeom = exp(sgeom);
//            //
            Br = (256 - ptr[x]) / 256.0;
//            //sgeom = sgeomGl / sgeom;
            //Br = exp(log(Br)*sgeomGl / sgeom);

            Br = exp(log(Br)* kkk*sgeom/sgeomGl);
            //Br = exp(log(Br)*kkk*sgeomGl / sgeom);
            Br = 256 *Br - 1;
            Kontrast = 255-(int)(Br + 0.5);
            if (Kontrast >255)  Kontrast = 255;
            if (Kontrast < 0)  Kontrast = 0;
            ptrG[x] = Kontrast;
//            //ptrG[x] = ptr[3 * x];
        }
    }
    //
    for (int x = 0; x < h+1; ++x)
           delete[]imgIntegral[x];
       delete[]imgIntegral;
    //
    m_elapsed4 = GetTickCount()-m_time4;
    std::cout<< "==== >Kontrast 2 cycle TIME: "<< m_elapsed4 << std::endl;

////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////
}
