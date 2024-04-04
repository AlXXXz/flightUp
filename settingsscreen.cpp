#include "settingsscreen.h"
#include "ui_settingsscreen.h"

settingsScreen::settingsScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsScreen)
{
    ui->setupUi(this);
}

settingsScreen::~settingsScreen()
{
    delete ui;
}
