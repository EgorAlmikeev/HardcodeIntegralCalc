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

signals :

    void CloseButtonClicked();
};

#endif // LOGOUTWIDGET_H
