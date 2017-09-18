#include "mainwindow.h"
#include <QDebug>
#include <math.h>
#include <QDesktopServices>

inline double Function(double x)
{
    return sin(sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6)));
}

double GetParabolaIntegralForMethod1(double _a, double _b, double _n)
{
    double _h = (_b - _a) / _n;
    double _sum = 0.0;
    double _x = _a + _h;

    double end_of_calculating = _b;

    while(_x <= end_of_calculating)
    {
        _sum += 4 * Function(_x);
        _x = _x + _h;
        _sum += 2 * Function(_x);
        _x = _x + _h;
    }

    return (_h * (_sum + (sqrt(0.5 * _a * _a + 3)) / (2 * _a + sqrt(2 * _a * _a + 1.6)) - (sqrt(0.5 * _b * _b + 3))/(2 * _b + sqrt(2 * _b * _b +1.6)))) / 3;
}

double GetIntForMethod2(double a, double b, double n, bool isShift)
{
    double x, s, h;

    s = 0;
    h = (b - a) / n;
    x = a;

    if(isShift)
        x += h * 0.5;

    while(x < b)
    {
        s += Function(x);
        x += h;
    }

    return s;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    p_main_widget = new QWidget;
    setCentralWidget(p_main_widget);

    p_main_vertical_layout = new QVBoxLayout;
    p_main_widget->setLayout(p_main_vertical_layout);

    p_logo_button = new QPushButton("crafted by pr_York");

    p_main_vertical_layout->addWidget(p_logo_button);

    p_logout = new LogoutWidget;

    p_main_menu = new MainMenu;

    p_stacked_widget = new QStackedWidget;
    p_stacked_widget->addWidget(p_main_menu);
    p_stacked_widget->addWidget(p_logout);
    p_stacked_widget->setCurrentWidget(p_main_menu);

    p_main_vertical_layout->addWidget(p_stacked_widget);

    connect(p_main_menu, SIGNAL(SendingArguments(double,double,double,double,int)), SLOT(StartCalculating(double,double,double,double,int)));
    connect(p_logout, SIGNAL(CloseButtonClicked()), SLOT(Restart()));
    connect(p_logo_button, SIGNAL(clicked(bool)), SLOT(OpenAuthorUrl()));
}

MainWindow::~MainWindow()
{}

void MainWindow::StartCalculating(double _a, double _b, double _n, double _e, int _type)
{
    a = _a;
    b = _b;
    n = _n;
    e = _e;

    qDebug() << "start calculating with a = " << _a << " b = " << _b << " n = " << _n << " e = " << _e << " type = " << _type;

    p_stacked_widget->setCurrentWidget(p_logout);

    switch(_type)
    {
    case 0 : LogoutLeftRectMethod(); break;
    case 1 : LogoutRightRectMethod(); break;
    case 2 : LogoutTrapMethod(); break;
    case 3 : LogoutParaMethod(); break;
    case 4 : LogoutMethod1(); break;
    case 5 : LogoutMethod2(); break;
    }
}

void MainWindow::Restart()
{
    p_logout->p_logout_text->clear();
    p_stacked_widget->setCurrentWidget(p_main_menu);
}

void MainWindow::LogoutLeftRectMethod()
{
    h = (b - a) / n;
    sum = 0.0;
    x = a;

    p_logout->InitializeCalculatingMethod("left rect", a, b, n, h, x);

    if(!isArgumentsCorrect())
        return;

    double end_of_calculating = b - h;
    int counter = 0;

    while(x <= end_of_calculating)
    {
        p_logout->LogIteration(++counter, x, end_of_calculating, sum);

        sum += Function(x);
        x += h;
    }

    p_logout->EndOfCalculating(h * sum);
}

void MainWindow::LogoutRightRectMethod()
{
    h = (b - a) / n;
    sum = 0.0;
    x = a + h;

    p_logout->InitializeCalculatingMethod("right rect", a, b, n, h, x);

    if(!isArgumentsCorrect())
        return;

    double end_of_calculating = b;
    int counter = 0;

    while(x <= end_of_calculating)
    {
        p_logout->LogIteration(++counter, x, end_of_calculating, sum);

        sum += Function(x);
        x += h;
    }

    p_logout->EndOfCalculating(h * sum);
}

void MainWindow::LogoutTrapMethod()
{
    h = (b - a) / n;
    sum = ((sqrt(0.5 * a * a + 3)) / (2 * a + sqrt(2 * a * a + 1.6)) + (sqrt(0.5 * b * b + 3)) / (2 * b + sqrt(2 * b * b + 1.6))) / 2;
    x = a + h;

    p_logout->InitializeCalculatingMethod("trapeze", a, b, n, h, x);

    if(!isArgumentsCorrect())
        return;

    double end_of_calculating = b - h;
    int counter = 0;

    while(x <= end_of_calculating)
    {
        p_logout->LogIteration(++counter, x, end_of_calculating, sum);

        sum += Function(x);
        x += h;
    }

    p_logout->EndOfCalculating(h * sum);
}

void MainWindow::LogoutParaMethod()
{
    h = (b - a) / n;
    sum = 0.0;
    x = a + h;

    p_logout->InitializeCalculatingMethod("parabola", a, b, n, h, x);

    if(!isArgumentsCorrect())
        return;

    double end_of_calculating = b;
    int counter = 0;

    while(x <= end_of_calculating)
    {
        p_logout->LogIteration(++counter, x, end_of_calculating, sum);

        sum += 4 * Function(x);
        x = x + h;
        sum += 2 * Function(x);
        x = x + h;
    }

    p_logout->EndOfCalculating((h * (sum + (sqrt(0.5 * a * a + 3)) / (2 * a + sqrt(2 * a * a + 1.6)) - (sqrt(0.5 * b * b + 3))/(2 * b + sqrt(2 * b * b +1.6)))) / 3);
}

void MainWindow::LogoutMethod1()
{
    p_logout->InitializeCalculatingMethod("double calculating", a, b, n, h, x, e);

    if(!isArgumentsCorrect())
        return;

    double integral_previous = 0.0, integral_current = 0.0;

    integral_current = GetParabolaIntegralForMethod1(a, b, n);

    while(true)
    {
        integral_previous = integral_current;
        n *= 2;
        integral_current = GetParabolaIntegralForMethod1(a, b, n);

        if(fabs(integral_previous - integral_current) <= e)
            break;
    }

    p_logout->EndOfCalculating(integral_current);
}

void MainWindow::LogoutMethod2()
{
    p_logout->InitializeCalculatingMethod("mixed calc", a, b, n, h, x, e);

    if(!isArgumentsCorrect())
        return;

    sum = 0;
    double integral_previous = 0.0, integral_current = 0.0, ns = 0.0;

    sum = GetIntForMethod2(a, b, n, false);
    sum += GetIntForMethod2(a, b, n, true);

    integral_previous = sum;

    do
    {
        integral_current = integral_previous;

        ns += n * 2;
        n *= 2;

        sum += GetIntForMethod2(a, b, n, true);

        integral_previous = sum * ((b - a) / ns);
    }
    while(fabs(integral_previous - integral_current) > e);

    p_logout->EndOfCalculating(integral_current);
}

bool MainWindow::isArgumentsCorrect()
{
    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nChecking for arguments...");
    if(a >= b)
    {
        p_logout->p_logout_text->append("\nError : a >= b");
        return false;
    }

    p_logout->p_logout_text->append("\nAll arguments are normal..."
                                    "\n-------------------------------------\n\n");

    return true;
}

void MainWindow::OpenAuthorUrl()
{
    QDesktopServices::openUrl(QUrl("https://github.com/PrincessYork"));
}
