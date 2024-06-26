#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "welcomescreen.h"
#include "settingsscreen.h"
#include "resultscreen.h"
#include "referencescreen.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    resultScreen *resultWidget;
    settingsScreen *settingsWidget;
    welcomeScreen *welcomeWidget;
    referenceScreen *referenceWidget;
    QSerialPort *serial;

};
#endif // MAINWINDOW_H
