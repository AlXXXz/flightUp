#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setMinimumSize(800, 600);
    w.setWindowTitle("FlightUp");

    w.show();
    return a.exec();
}
