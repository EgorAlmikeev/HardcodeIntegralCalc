#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include "mainmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStackedWidget *p_stacked_widget;
    QVBoxLayout *p_main_layout;
    QPushButton *p_logo_button;
    QTextEdit *p_logout_text;
    MainMenu *p_main_menu;

    int a, b, n, h, e, last_I, next_I, sum;

    void ConstantStepTrapezeMethod();
    void ConstantStepSimpsonMethod();
    void ConstantStepRectangleMethod();

    void NonConstantStepTrapezeMethod();
    void NonConstantStepSimpsonMethod();
    void NonConstantStepRectangleMethod();
};

#endif // MAINWINDOW_H
