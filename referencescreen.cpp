#include "referencescreen.h"
#include "ui_referencescreen.h"

referenceScreen::referenceScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::referenceScreen)
{
    ui->setupUi(this);
}

referenceScreen::~referenceScreen()
{
    delete ui;
}
