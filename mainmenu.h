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

class ConstStepMethodButtons : public QGroupBox
{
    Q_OBJECT


public :

    QVBoxLayout *p_layout;

    QRadioButton *p_left_rect_method;
    QRadioButton *p_trap_method;
    QRadioButton *p_para_method;
    QRadioButton *p_right_rect_method;

    bool enabled;

    ConstStepMethodButtons()
    {
        enabled = true;
        setTitle("Const step methods");

        p_left_rect_method = new QRadioButton("left rect method");
        p_right_rect_method = new QRadioButton("right rect method");
        p_trap_method = new QRadioButton("trapeze method");
        p_para_method = new QRadioButton("parabola method");

        p_layout = new QVBoxLayout;

        p_layout->addWidget(p_left_rect_method);
        p_layout->addWidget(p_right_rect_method);
        p_layout->addWidget(p_trap_method);
        p_layout->addWidget(p_para_method);

        p_left_rect_method->setChecked(true);

        setLayout(p_layout);
    }

public slots:

    void setEnabledFalse()
    {
        setEnabled(false);
        enabled = false;
    }

    void setEnabledTrue()
    {
        setEnabled(true);
        enabled = true;
    }

};

class NonConstStepMethodButtons : public QGroupBox
{
    Q_OBJECT


public :

    QVBoxLayout *p_layout;

    QRadioButton *p_method_1;
    QRadioButton *p_method_2;

    bool enabled;

    NonConstStepMethodButtons()
    {
        enabled = true;
        setTitle("Non const step methods");

        p_method_1 = new QRadioButton("left rect method");
        p_method_2 = new QRadioButton("trapeze method");

        p_layout = new QVBoxLayout;

        p_layout->addWidget(p_method_1);
        p_layout->addWidget(p_method_2);

        p_method_1->setChecked(true);

        setLayout(p_layout);
    }

public slots:

    void setEnabledFalse()
    {
        setEnabled(false);
        enabled = false;
    }

    void setEnabledTrue()
    {
        setEnabled(true);
        enabled = true;
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

        connect(p_const_step, SIGNAL(clicked(bool)), SIGNAL(ConstClicked()));
        connect(p_non_const_step, SIGNAL(clicked(bool)), SIGNAL(NonConstClicked()));
    }

signals :

    void NonConstClicked();
    void ConstClicked();
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

    NonConstStepMethodButtons *p_non_const_step_method_choice;
    ConstStepMethodButtons *p_const_step_method_choice;
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

    enum method_type {left_rect_method, right_rect_method, trapeze_method, parabola_method, method_1, method_2};

    method_type type;

public slots :

    void CheckForArguments();
    void SendArguments();

signals :

    void SendingArguments(int a, int b, int n, int e, int type);
};

#endif // MAINMENU_H
