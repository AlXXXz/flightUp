#ifndef REFERENCESCREEN_H
#define REFERENCESCREEN_H

#include <QWidget>

namespace Ui {
class referenceScreen;
}

class referenceScreen : public QWidget
{
    Q_OBJECT

public:
    explicit referenceScreen(QWidget *parent = nullptr);
    ~referenceScreen();

private:
    Ui::referenceScreen *ui;
};

#endif // REFERENCESCREEN_H
