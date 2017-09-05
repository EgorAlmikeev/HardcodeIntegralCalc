#include "mainmenu.h"

MainMenu::MainMenu()
{
    p_main_vertical_layout = new QVBoxLayout;
    setLayout(p_main_vertical_layout);

    p_const_step_method_choice = new ConstStepMethodButtons;
    p_non_const_step_method_choice = new NonConstStepMethodButtons;
    p_step_choice = new StepButtons;

    p_non_const_step_method_choice->setEnabledFalse();

    p_main_vertical_layout->addWidget(p_step_choice);
    p_main_vertical_layout->addWidget(p_const_step_method_choice);
    p_main_vertical_layout->addWidget(p_non_const_step_method_choice);

    p_integral_label = new QLabel;
    p_integral_label->setPixmap(QPixmap(":/images/res/integral.png"));
    p_integral_label->setAlignment(Qt::AlignCenter);

    p_main_vertical_layout->addWidget(p_integral_label);

    p_a_edit = new QLineEdit;
    p_b_edit = new QLineEdit;
    p_n_edit = new QLineEdit;
    p_e_edit = new QLineEdit;

    p_a_label = new QLabel("a =");
    p_b_label = new QLabel("b =");
    p_n_label = new QLabel("n =");
    p_e_label = new QLabel("e =");

    SetEpsilonEditEnabledFalse();

    p_first_horizontal_layout = new QHBoxLayout;
    p_second_horizontal_layout = new QHBoxLayout;

    p_start_button = new QPushButton("Start");
    p_start_button->setEnabled(false);

    p_first_horizontal_layout->addWidget(p_a_label);
    p_first_horizontal_layout->addWidget(p_a_edit);

    p_first_horizontal_layout->addWidget(p_b_label);
    p_first_horizontal_layout->addWidget(p_b_edit);

    p_first_horizontal_layout->addWidget(p_n_label);
    p_first_horizontal_layout->addWidget(p_n_edit);

    p_second_horizontal_layout->addWidget(p_e_label);
    p_second_horizontal_layout->addWidget(p_e_edit);

    p_second_horizontal_layout->addWidget(p_start_button);

    p_main_vertical_layout->addWidget(p_integral_label);

    p_main_vertical_layout->addLayout(p_first_horizontal_layout);
    p_main_vertical_layout->addLayout(p_second_horizontal_layout);

    connect(p_start_button, SIGNAL(clicked(bool)), SLOT(SendArguments()));

    connect(p_a_edit, SIGNAL(textEdited(QString)), SLOT(CheckForArguments()));
    connect(p_b_edit, SIGNAL(textEdited(QString)), SLOT(CheckForArguments()));
    connect(p_n_edit, SIGNAL(textEdited(QString)), SLOT(CheckForArguments()));
    connect(p_e_edit, SIGNAL(textEdited(QString)), SLOT(CheckForArguments()));

    connect(p_step_choice, SIGNAL(ConstClicked()), p_const_step_method_choice, SLOT(setEnabledTrue()));
    connect(p_step_choice, SIGNAL(ConstClicked()), p_non_const_step_method_choice, SLOT(setEnabledFalse()));
    connect(p_step_choice, SIGNAL(ConstClicked()), SLOT(SetEpsilonEditEnabledFalse()));
    connect(p_step_choice, SIGNAL(ConstClicked()), SLOT(CheckForArguments()));

    connect(p_step_choice, SIGNAL(NonConstClicked()), p_const_step_method_choice, SLOT(setEnabledFalse()));
    connect(p_step_choice, SIGNAL(NonConstClicked()), p_non_const_step_method_choice, SLOT(setEnabledTrue()));
    connect(p_step_choice, SIGNAL(NonConstClicked()), SLOT(SetEpsilonEditEnabledTrue()));
    connect(p_step_choice, SIGNAL(NonConstClicked()), SLOT(CheckForArguments()));
}

void MainMenu::CheckForArguments()
{
    QRegExp reg_1("^[+-]?[\\d]+($|[\\.][\\d]+|([\\.][\\d]+[Ee]|[Ee])[+-]?\\d+)$");

    bool boolean = true;

    (boolean *= p_a_edit->text().contains(reg_1));

    (boolean *= p_b_edit->text().contains(reg_1));

    (boolean *= p_n_edit->text().contains(reg_1));

    if(p_e_edit->isEnabled())
        (boolean *= p_e_edit->text().contains(reg_1));

    if(boolean)
        p_start_button->setEnabled(true);
    else
        p_start_button->setEnabled(false);
}

void MainMenu::SendArguments()
{
    if(p_const_step_method_choice->enabled)
    {
        if(p_const_step_method_choice->p_left_rect_method->isChecked())
            type = left_rect_method;
        else if(p_const_step_method_choice->p_right_rect_method->isChecked())
            type = right_rect_method;
        else if(p_const_step_method_choice->p_trap_method->isChecked())
            type = trapeze_method;
        else if(p_const_step_method_choice->p_para_method->isChecked())
            type = parabola_method;
    }
    else if(p_non_const_step_method_choice->enabled)
    {
        if(p_non_const_step_method_choice->p_method_1->isChecked())
            type = method_1;
        else if(p_non_const_step_method_choice->p_method_2->isChecked())
            type = method_2;
    }
    else
        exit(1);

    emit SendingArguments(p_a_edit->text().toDouble(),
                          p_b_edit->text().toDouble(),
                          p_n_edit->text().toDouble(),
                          p_e_edit->text().toInt(),
                          type);
}

void MainMenu::SetEpsilonEditEnabledTrue()
{
    p_e_edit->setEnabled(true);
}

void MainMenu::SetEpsilonEditEnabledFalse()
{
    p_e_edit->setEnabled(false);
}
