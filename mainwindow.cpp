#include "mainwindow.h"
#include "ui_mainwindow.h"

static const char blankString[] = QT_TRANSLATE_NOOP("MainWindow", "N/A");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultWidget = new resultScreen();
    //settingsWidget = new settingsScreen();
    welcomeWidget = new welcomeScreen();
    referenceWidget = new referenceScreen();

//    ui->stackedWidget->addWidget(settingsWidget);
    ui->stackedWidget->addWidget(resultWidget);
    ui->stackedWidget->addWidget(welcomeWidget);
    ui->stackedWidget->addWidget(referenceWidget);

    ui->stackedWidget->setCurrentWidget(welcomeWidget);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        list << info.portName();
      ui->comboBox->addItem(list.first());
    }


    //ui->pushButton_6->setStyleSheet("QPushButton:border-style{ none;}");

    //ui->toolButton->setStyleSheet("QToolButton:hover{ background-color: red;}");
    //ui->pushButton->setStyleSheet("QPushButton:hover{ background-color: red;}");
}

MainWindow::~MainWindow() {
    delete ui;
}

//void MainWindow::on_pushButton_2_clicked(){
//    ui->stackedWidget->setCurrentWidget(settingsWidget);
//}

void MainWindow::on_pushButton_clicked(){
    ui->stackedWidget->setCurrentWidget(welcomeWidget);
}

void MainWindow::on_pushButton_3_clicked(){
    ui->stackedWidget->setCurrentWidget(resultWidget);
}

void MainWindow::on_pushButton_4_clicked(){
    ui->stackedWidget->setCurrentWidget(referenceWidget);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(resultWidget);
    resultWidget->check_param();
    resultWidget->clearGraph();
    resultWidget->makeGraph();
    resultWidget->drawGraph();
    resultWidget->drawFilterGraph();
}

