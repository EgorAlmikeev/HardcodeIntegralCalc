#ifndef LOGOUTWIDGET_H
#define LOGOUTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class LogoutWidget : public QWidget
{
    Q_OBJECT


public:
    LogoutWidget();

    QTextEdit *p_logout_text;
    QPushButton *p_close_button;
    QVBoxLayout *p_layout;

    void LogIteration(double iteration_number, double current_x, double maximum_x, double current_sum);
    void InitializeCalculatingMethod(QString method_name, double _a, double _b, int _n, double _h, double _x);
    void InitializeCalculatingMethod(QString method_name, double _a, double _b, int _n, double _h, double _x, double _e);
    void EndOfCalculating(double _integral_value);

signals:

    void CloseButtonClicked();
};

#endif // LOGOUTWIDGET_H
