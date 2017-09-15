#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "finitestatemachine.h"
#include <QThread>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow
        : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CSettings oSettings;
    CFiniteStateMachine *fsm;

public slots:
    void MVCGPIO1(bool);
    void MVCGPIO2(bool);
    void MVCGPIO3(bool);

//public slots:
//    void    slot_ReceiveImage(IplImage);
};

#endif // MAINWINDOW_H
