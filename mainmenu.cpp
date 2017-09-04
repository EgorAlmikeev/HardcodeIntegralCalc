#include "mainmenu.h"

MainMenu::MainMenu()
{
    p_main_vertical_layout = new QVBoxLayout;
    setLayout(p_main_vertical_layout);

    p_method_choice = new MethodButtons;
    p_step_choice = new StepButtons;

    p_main_vertical_layout->addWidget(p_method_choice);
    p_main_vertical_layout->addWidget(p_step_choice);

    p_integral_label = new QLabel;

    p_main_vertical_layout->addWidget(p_integral_label);

    p_a_edit = new QLineEdit;
    p_b_edit = new QLineEdit;
    p_n_edit = new QLineEdit;
    p_e_edit = new QLineEdit;

    p_a_label = new QLabel("a =");
    p_b_label = new QLabel("b =");
    p_n_label = new QLabel("n =");
    p_e_label = new QLabel("e =");

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
}

void MainMenu::CheckForArguments()
{
    QRegExp reg_1("^[0-9]+$");

    bool boolean = true;

    if(boolean *= p_a_edit->text().contains(reg_1))
        p_a_edit->setStyleSheet("color : black;");
    else
        p_a_edit->setStyleSheet("color : red;");

    if(boolean *= p_b_edit->text().contains(reg_1))
        p_b_edit->setStyleSheet("color : black;");
    else
        p_b_edit->setStyleSheet("color : red;");

    if(boolean *= p_n_edit->text().contains(reg_1))
        p_n_edit->setStyleSheet("color : black;");
    else
        p_n_edit->setStyleSheet("color : red;");

    if(boolean *= p_e_edit->text().contains(reg_1))
        p_e_edit->setStyleSheet("color : black;");
    else
        p_e_edit->setStyleSheet("color : red;");

    if(boolean)
        p_start_button->setEnabled(true);
    else
        p_start_button->setEnabled(false);
}

void MainMenu::SendArguments()
{

    if(p_method_choice->p_rect_method->isChecked() && p_step_choice->p_const_step->isChecked())
        type = const_rect;
    else if(p_method_choice->p_trap_method->isChecked() && p_step_choice->p_const_step->isChecked())
        type = const_trap;
    else if(p_method_choice->p_simp_method->isChecked() && p_step_choice->p_const_step->isChecked())
        type = const_simp;
    else if(p_method_choice->p_rect_method->isChecked() && p_step_choice->p_non_const_step->isChecked())
        type = nconst_rect;
    else if(p_method_choice->p_trap_method->isChecked() && p_step_choice->p_non_const_step->isChecked())
        type = nconst_trap;
    else if(p_method_choice->p_simp_method->isChecked() && p_step_choice->p_non_const_step->isChecked())
        type = nconst_simp;
    else
        exit(1);


    emit SendingArguments(p_a_edit->text().toInt(),
                          p_b_edit->text().toInt(),
                          p_n_edit->text().toInt(),
                          p_e_edit->text().toInt(),
                          type);

}
