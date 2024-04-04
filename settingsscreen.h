#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include <QWidget>

namespace Ui {
class settingsScreen;
}

class settingsScreen : public QWidget
{
    Q_OBJECT

public:
    explicit settingsScreen(QWidget *parent = nullptr);
    ~settingsScreen();

private:
    Ui::settingsScreen *ui;
};

#endif // SETTINGSSCREEN_H
