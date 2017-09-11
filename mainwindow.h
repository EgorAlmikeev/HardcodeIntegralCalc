#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "mainmenu.h"
#include "logoutwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *p_main_widget;
    QStackedWidget *p_stacked_widget;
    QVBoxLayout *p_main_vertical_layout;
    QPushButton *p_logo_button;

    LogoutWidget *p_logout;
    MainMenu *p_main_menu;

    double a, b, n, h, e, sum, x;

    void LeftRectMethod();
    void RightRectMethod();
    void TrapMethod();
    void ParaMethod();
    void Method1();
    void Method2();

    bool isArgumentsCorrect();

public slots :

    void StartCalculating(double _a, double _b, double _n, double _e, int _type);
    void Restart();
    void OpenAuthorUrl();
};

#endif // MAINWINDOW_H
