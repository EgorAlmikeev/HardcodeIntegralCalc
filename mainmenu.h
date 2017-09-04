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

class MethodButtons : public QGroupBox
{
    Q_OBJECT


public :

    QVBoxLayout *p_layout;

    QRadioButton *p_rect_method;
    QRadioButton *p_trap_method;
    QRadioButton *p_simp_method;

    MethodButtons()
    {
        setTitle("Method");

        p_rect_method = new QRadioButton("rect method");
        p_trap_method = new QRadioButton("trap method");
        p_simp_method = new QRadioButton("simp method");

        p_layout = new QVBoxLayout;

        p_layout->addWidget(p_rect_method);
        p_layout->addWidget(p_trap_method);
        p_layout->addWidget(p_simp_method);

        p_rect_method->setChecked(true);

        setLayout(p_layout);
    }
};

class StepButtons : public QGroupBox
{
    Q_OBJECT


public :

    QVBoxLayout *p_layout;

    QRadioButton *p_const_step;
    QRadioButton *p_non_const_step;

    StepButtons()
    {
        setTitle("Step");

        p_const_step = new QRadioButton("const");
        p_non_const_step = new QRadioButton("non const");

        p_layout = new QVBoxLayout;

        p_layout->addWidget(p_const_step);
        p_layout->addWidget(p_non_const_step);

        p_const_step->setChecked(true);

        setLayout(p_layout);
    }
};

class MainMenu : public QWidget
{
    Q_OBJECT


public:
    MainMenu();

    QVBoxLayout *p_main_vertical_layout;

    QLabel *p_integral_label;

    QHBoxLayout *p_first_horizontal_layout;
    QHBoxLayout *p_second_horizontal_layout;

    MethodButtons *p_method_choice;
    StepButtons *p_step_choice;

    QLineEdit *p_a_edit;
    QLineEdit *p_b_edit;
    QLineEdit *p_n_edit;
    QLineEdit *p_e_edit;

    QLabel *p_a_label;
    QLabel *p_b_label;
    QLabel *p_n_label;
    QLabel *p_e_label;

    QPushButton *p_start_button;

    enum method_type {const_rect, const_trap, const_simp, nconst_rect, nconst_trap, nconst_simp};

    method_type type;

public slots :

    void CheckForArguments();
    void SendArguments();

signals :

    void SendingArguments(int a, int b, int n, int e, int type);
};

#endif // MAINMENU_H
