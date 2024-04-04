#include "warningscreen.h"
#include "ui_warningscreen.h"

warningScreen::warningScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warningScreen)
{
    ui->setupUi(this);
}

warningScreen::~warningScreen()
{
    delete ui;
}
