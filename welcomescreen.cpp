#include "welcomescreen.h"
#include "ui_welcomescreen.h"

welcomeScreen::welcomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcomeScreen)
{
    ui->setupUi(this);
}

welcomeScreen::~welcomeScreen()
{
    delete ui;
}
