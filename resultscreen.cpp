#include "resultscreen.h"
#include "ui_resultscreen.h"
#include "warningscreen.h"
#include <QDebug>

resultScreen::resultScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultScreen)
{
    ui->setupUi(this);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(0, 2);
    ui->widget->yAxis->setRange(-4, 4);
}

void resultScreen::Default_param(){
    xBegin = 0;
    xEnd = 2.25;
    h = 0.01;
}

void resultScreen::makeGraph(){
    // Переделать на фильтр
    // А график получается / генерируется в другом месте
    float noise = 0;
    float buff[3] = { 0 };
    float middle;
    int count = 0;
    double y_value;

    xBegin = 0;
    xEnd = 2.25;
    h = 0.01;

    X = xBegin;
    x.clear();
    y.clear();

    ui->widget->addGraph();
    ui->widget->addGraph();

    // Цикл от начала координаты x до значения xEnd (введённого в поле или дефолтного)
    while (X <= xEnd) {
        if (count > 2)
            count = 0;

        noise += rand() % 6;
        y_value = 3 * sin(noise);
        buff[count] = y_value;
        x.push_back(X);
        y.push_back(y_value);
        middle = (std::max(buff[0], buff[1]) == std::max(buff[1], buff[2])) ? std::max(buff[1], buff[2]) : std::max(buff[1], std::min(buff[0], buff[2]));
        filter_y.push_back(middle);
        X += h;
        count++;
    }
}

void resultScreen::drawGraph(){
    ui->widget->graph(0)->addData(x, y);
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->replot();
}

void resultScreen::drawFilterGraph(){
    ui->widget->graph(1)->addData(x, filter_y);
    ui->widget->graph(1)->setPen(QPen(Qt::blue));
    ui->widget->replot();
}

void resultScreen::clearGraph()
{
    ui->widget->clearGraphs();
    ui->widget->replot();
    x.clear();
    y.clear();
    filter_y.clear();
}

resultScreen::~resultScreen(){
    delete ui;
}

//void resultScreen::on_clearGraphBtn_clicked(){
//    ui->widget->clearGraphs();
//    ui->widget->replot();
//    x.clear();
//    y.clear();
//    filter_y.clear();
//}

//void resultScreen::on_makeGraphBtn_clicked(){
//    ui->widget->removeGraph(0);
//    ui->widget->replot();
////    if ((xBegin == 0) && (xEnd == 0) && (h == 0))
////            Default_param();
////    else {
////        ui->widget->xAxis->setRange(xBegin, xEnd);
////        ui->widget->yAxis->setRange(-4, 4);
////    }
////    ui->widget->addGraph();
////    ui->widget->addGraph();

////    makeGraph();

////    //qDebug() << ui->noFilter->checkState() << ui->Filter->checkState();



////    //qDebug() << ((ui->noFilter->checkState() == Qt::Checked ? true: false) && (ui->Filter->checkState() == Qt::Checked ? true: false));

////    if((ui->noFilter->checkState() == Qt::Checked) && !(ui->Filter->checkState() == Qt::Checked))
////        drawGraph();
////    else if ((ui->Filter->checkState() == Qt::Checked) && !(ui->noFilter->checkState() == Qt::Checked))
////        drawFilterGraph();
////    else if ((ui->noFilter->checkState() == Qt::Checked) && (ui->Filter->checkState() == Qt::Checked)) {
////        drawGraph();
////        drawFilterGraph();
////    }
////    else {
////        warningScreen *war = new warningScreen();
////        war->show();
////    }
//}

void resultScreen::on_start_in_area_textEdited(const QString &arg1){
    xBegin = arg1.toDouble();
}

void resultScreen::on_stop_in_area_textEdited(const QString &arg1){
    xEnd = arg1.toDouble();
}

void resultScreen::on_h_in_area_textEdited(const QString &arg1){
    h = arg1.toDouble();
}

void resultScreen::check_param()
{
    qDebug() << xBegin << xEnd << h;
    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(-4, 4);
//    if ((xBegin == 0) && (xEnd == 0) && (h == 0))
//        Default_param();
//    else {
//        ui->widget->xAxis->setRange(xBegin, xEnd);
//        ui->widget->yAxis->setRange(-4, 4);
//    }
}
