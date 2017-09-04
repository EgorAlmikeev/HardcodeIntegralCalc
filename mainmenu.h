#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>

class MainMenu
{
public:
    MainMenu();

    QWidget *p_main_widget;
    QVBoxLayout *p_main_vertical_layout;

    QGroupBox *p_method_choice;
    QGroupBox *p_step_choice;

    QRadioButton *p_rect_method;
    QRadioButton *p_trap_method;
    QRadioButton *p_simp_method;

    QRadioButton *p_const_step;
    QRadioButton *p_non_const_step;

    QPushButton *p_start_button;

    void CheckForArguments();

signals :

    void SendingArguments(int, int, int, int);
};

#endif // MAINMENU_H
