#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->spinBox,    SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetBrightness(int)));
    connect(ui->spinBox_2,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetExposure(int)));
    connect(ui->spinBox_3,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetSharpness(int)));
    connect(ui->spinBox_4,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetHue(int)));
    connect(ui->spinBox_5,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetSaturation(int)));
    connect(ui->spinBox_6,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetGamma(int)));
    connect(ui->spinBox_7,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetShutter(int)));
    connect(ui->spinBox_8,  SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetGain(int)));
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetRed(int)));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)),
            &oSettings,     SLOT(SetBlue(int)));

    connect(ui->checkBox,               SIGNAL(stateChanged(int)), &oSettings, SLOT(SetContour(int)));
    connect(ui->checkBox_2,             SIGNAL(stateChanged(int)), &oSettings, SLOT(SetSimilar(int)));
    connect(ui->checkBox_3,             SIGNAL(stateChanged(int)), &oSettings, SLOT(SetContrast(int)));
    connect(ui->checkBox_4,             SIGNAL(stateChanged(int)), &oSettings, SLOT(SetBinary(int)));
    connect(ui->checkBox_10,            SIGNAL(stateChanged(int)), &oSettings, SLOT(SetSaveImage(int)));

    connect(ui->doubleSpinBox,          SIGNAL(valueChanged(double)), &oSettings, SLOT(SetShablonDl(double)));
    connect(ui->doubleSpinBox_2,        SIGNAL(valueChanged(double)), &oSettings, SLOT(SetShablonSquere(double)));
    connect(ui->doubleSpinBox_3,        SIGNAL(valueChanged(double)), &oSettings, SLOT(SetMaximumDistance(double)));
    connect(ui->doubleSpinBox_4,        SIGNAL(valueChanged(double)), &oSettings, SLOT(SetMinimumDistance1(double)));
    connect(ui->doubleSpinBox_5,        SIGNAL(valueChanged(double)), &oSettings, SLOT(SetMinimumDistance2(double)));
    connect(ui->doubleSpinBox_7,        SIGNAL(valueChanged(double)), &oSettings, SLOT(SetDelContour(double)));
    connect(ui->spinBox_12,             SIGNAL(valueChanged(int)), &oSettings,    SLOT(SetDlina(int)));
    connect(ui->spinBox_9,              SIGNAL(valueChanged(int)), &oSettings,    SLOT(SetEach(int)));

    QThread *thread= new QThread;
    CFiniteStateMachine *fsm = new CFiniteStateMachine;
    fsm->moveToThread(thread);
    connect(thread, SIGNAL(started()), fsm, SLOT(Start()));
    //connect(fsm,SIGNAL(signal_SendImage(IplImage),)
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
