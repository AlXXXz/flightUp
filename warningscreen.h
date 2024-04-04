#ifndef WARNINGSCREEN_H
#define WARNINGSCREEN_H

#include <QWidget>

namespace Ui {
class warningScreen;
}

class warningScreen : public QWidget
{
    Q_OBJECT

public:
    explicit warningScreen(QWidget *parent = nullptr);
    ~warningScreen();

private:
    Ui::warningScreen *ui;
};

#endif // WARNINGSCREEN_H
