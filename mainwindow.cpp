#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    p_main_widget = new QWidget;
    setCentralWidget(p_main_widget);

    p_main_vertical_layout = new QVBoxLayout;
    p_main_widget->setLayout(p_main_vertical_layout);

    p_logo_button = new QPushButton("logo");

//    p_main_vertical_layout->addWidget(p_logo_button);

    p_logout = new LogoutWidget;

    p_main_menu = new MainMenu;

    p_stacked_widget = new QStackedWidget;
    p_stacked_widget->addWidget(p_main_menu);
    p_stacked_widget->addWidget(p_logout);
    p_stacked_widget->setCurrentWidget(p_main_menu);

    p_main_vertical_layout->addWidget(p_stacked_widget);

    connect(p_main_menu, SIGNAL(SendingArguments(int,int,int,int,int)), SLOT(StartCalculating(int,int,int,int,int)));
    connect(p_logout, SIGNAL(CloseButtonClicked()), SLOT(Restart()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::StartCalculating(int _a, int _b, int _n, int _e, int _type)
{
    a = _a;
    b = _b;
    n = _n;
    e = _e;

    qDebug() << "start calculating with a = " << _a << " b = " << _b << " n = " << _n << " e = " << _e << " type = " << _type;

    p_stacked_widget->setCurrentWidget(p_logout);
}

void MainWindow::Restart()
{
    p_logout->p_logout_text->clear();
    p_stacked_widget->setCurrentWidget(p_main_menu);
}

void MainWindow::LeftRectMethod()
{}
void MainWindow::RightRectMethod()
{}
void MainWindow::TrapMethod()
{}
void MainWindow::ParaMethod()
{}
void MainWindow::Method1()
{}
void MainWindow::Method2()
{}
