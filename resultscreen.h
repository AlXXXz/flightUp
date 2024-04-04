#ifndef RESULTSCREEN_H
#define RESULTSCREEN_H

#include <QWidget>
#include <QVector>

namespace Ui {
class resultScreen;
}

class resultScreen : public QWidget
{
    Q_OBJECT

public:
    explicit resultScreen(QWidget *parent = nullptr);
    /**
     * @brief Default_param - Использовать значения по умолчанию
     * @details Переменным xBegin, xEnd, h присваивается значения 0, 2.25, 0.01 соответсвенно
     * нужно в случае если пользователь не ввёл значения
     */
    void Default_param();
    /**
     * @brief makeGraph - расчитать значения y и отфильтрованных значений y
     */
    void makeGraph();
    /**
     * @brief drawGraph - нарисовать не отфильтрованный график
     */
    void drawGraph();
    /**
     * @brief drawFilterGraph - нарисовать отфильтрованный график
     */
    void drawFilterGraph();

    /**
     * @brief clearGraph - Удалить графики с координатной плоскости и очестить вектора
     */
    void clearGraph();

    void check_param();

    ~resultScreen();

    Ui::resultScreen *ui;
    double xBegin = 0, xEnd = 0, h = 0, X;
    QVector<double> x, y, filter_y;

private slots:
//    /**
//     * @brief on_clearGraphBtn_clicked - слот кнопки "очистить"
//     * @details Очищает координатную плоскость
//     */
//    void on_clearGraphBtn_clicked();

//    /**
//     * @brief on_makeGraphBtn_clicked - Построить график и вывести его на экран
//     * @details Запускает функцию расчёта значений и фильтрации, и отрисовки графика в зависимости от выбранного checkbox
//     */
//    void on_makeGraphBtn_clicked();

    /**
     * @brief on_start_in_area_textEdited - поле ввода начала диапозона
     * @param arg1
     */
    void on_start_in_area_textEdited(const QString &arg1);

    /**
     * @brief on_stop_in_area_textEdited - поле ввода конца диапозона
     * @param arg1
     */
    void on_stop_in_area_textEdited(const QString &arg1);

    /**
     * @brief on_h_in_area_textEdited - поле ввода шага
     * @param arg1
     */
    void on_h_in_area_textEdited(const QString &arg1);
private:

};

#endif // RESULTSCREEN_H
