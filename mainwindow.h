#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "finitestatemachine.h"
#include <QThread>

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

//public slots:
//    void    slot_ReceiveImage(IplImage);
};

#endif // MAINWINDOW_H
