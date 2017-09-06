#include "mainwindow.h"
#include <QDebug>
#include <math.h>

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
}

MainWindow::~MainWindow()
{

}

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
    case 0 : LeftRectMethod(); break;
    case 1 : RightRectMethod(); break;
    case 2 : TrapMethod(); break;
    case 3 : ParaMethod(); break;
    case 4 : Method1(); break;
    case 5 : Method2(); break;
    }
}

void MainWindow::Restart()
{
    p_logout->p_logout_text->clear();
    p_stacked_widget->setCurrentWidget(p_main_menu);
}

void MainWindow::LeftRectMethod()
{
    h = (b - a) / n;
    sum = 0;
    x = a;

    p_logout->p_logout_text->append(QString("Start calculating \"left rect\" method..."
                                            "\n-------------------------------------"
                                            "\nArguments :"
                                            "\na = " + QString::number(a) +
                                            "\nb = " + QString::number(b) +
                                            "\nn = " + QString::number(n) +
                                            "\nh = (b - a) / n = " + QString::number(h) +
                                            "\nx = " + QString::number(x) +
                                            "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                            )
                                    );

    if(!isArgumentsCorrect())
        return;

    p_logout->p_logout_text->append("-------------------------------------\n\n");

    double temp = b - h;
    int counter = 0;

    while(x <= temp)
    {
        p_logout->p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(++counter) + QString("    ------------------"));
        p_logout->p_logout_text->append("Step " + QString::number(x) + " / " + QString::number(temp));
        p_logout->p_logout_text->append("sum = " + QString::number(sum));
        sum += sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6));
        x += h;
    }

    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " + QString::number(h * sum)
                                    );
}

void MainWindow::RightRectMethod()
{
    h = (b - a) / n;
    sum = 0;
    x = a + h;

    p_logout->p_logout_text->append(QString("Start calculating \"right rect\" method..."
                                            "\n-------------------------------------"
                                            "\nArguments :"
                                            "\na = " + QString::number(a) +
                                            "\nb = " + QString::number(b) +
                                            "\nn = " + QString::number(n) +
                                            "\nh = (b - a) / n = " + QString::number(h) +
                                            "\nx = " + QString::number(x) +
                                            "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                            )
                                    );

    if(!isArgumentsCorrect())
        return;

    p_logout->p_logout_text->append("-------------------------------------\n\n");

    double temp = b;
    int counter = 0;

    while(x <= temp)
    {
        p_logout->p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(++counter) + QString("    ------------------"));
        p_logout->p_logout_text->append("Step " + QString::number(x) + " / " + QString::number(temp));
        p_logout->p_logout_text->append("sum = " + QString::number(sum));
        sum += sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6));
        x += h;
    }

    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " + QString::number(h * sum)
                                    );
}

void MainWindow::TrapMethod()
{
    h = (b - a) / n;
    sum = ((sqrt(0.5 * a * a + 3)) / (2 * a + sqrt(2 * a * a + 1.6)) + (sqrt(0.5 * b * b + 3)) / (2 * b + sqrt(2 * b * b + 1.6))) / 2;
    x = a + h;

    p_logout->p_logout_text->append(QString("Start calculating \"trapeze rect\" method..."
                                            "\n-------------------------------------"
                                            "\nArguments :"
                                            "\na = " + QString::number(a) +
                                            "\nb = " + QString::number(b) +
                                            "\nn = " + QString::number(n) +
                                            "\nh = (b - a) / n = " + QString::number(h) +
                                            "\nx = " + QString::number(x) +
                                            "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                            )
                                    );

    if(!isArgumentsCorrect())
        return;

    p_logout->p_logout_text->append("-------------------------------------\n\n");

    double temp = b - h;
    int counter = 0;

    while(x <= temp)
    {
        p_logout->p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(++counter) + QString("    ------------------"));
        p_logout->p_logout_text->append("Step " + QString::number(x) + " / " + QString::number(temp));
        p_logout->p_logout_text->append("sum = " + QString::number(sum));
        sum += sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6));
        x += h;
    }

    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " + QString::number(h * sum)
                                    );
}

void MainWindow::ParaMethod()
{
    h = (b - a) / n;
    sum = 0;
    x = a + h;

    p_logout->p_logout_text->append(QString("Start calculating \"parabola rect\" method..."
                                            "\n-------------------------------------"
                                            "\nArguments :"
                                            "\na = " + QString::number(a) +
                                            "\nb = " + QString::number(b) +
                                            "\nn = " + QString::number(n) +
                                            "\nh = (b - a) / n = " + QString::number(h) +
                                            "\nx = " + QString::number(x) +
                                            "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                            )
                                    );

    if(!isArgumentsCorrect())
        return;

    p_logout->p_logout_text->append("-------------------------------------\n\n");

    double temp = b;
    int counter = 0;

    while(x <= temp)
    {
        p_logout->p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(++counter) + QString("    ------------------"));
        p_logout->p_logout_text->append("Step " + QString::number(x) + " / " + QString::number(temp));
        p_logout->p_logout_text->append("sum = " + QString::number(sum));
        sum = sum + 4 * (sqrt(0.5 * x * x + 3)) / (2 * x + sqrt(2 * x * x + 1.6));
        x = x + h;
        sum = sum + 2 * (sqrt(0.5 * x * x + 3)) / (2 * x + sqrt(2 * x * x + 1.6));
        x = x + h;
    }

    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " +
                                    QString::number( (h * (sum + (sqrt(0.5 * a * a + 3)) / (2 * a + sqrt(2 * a * a + 1.6)) - (sqrt(0.5 * b * b + 3))/(2 * b + sqrt(2 * b * b +1.6)))) / 3)
                                    );
}

void MainWindow::Method1()
{
    h = (b - a) / n;
    sum = 0;
    x = a;

    p_logout->p_logout_text->append(QString("Start calculating \"double calc\" rect method..."
                                            "\n-------------------------------------"
                                            "\nArguments :"
                                            "\na = " + QString::number(a) +
                                            "\nb = " + QString::number(b) +
                                            "\nn = " + QString::number(n) +
                                            "\nh = (b - a) / n = " + QString::number(h) +
                                            "\nx = " + QString::number(x) +
                                            "\ne = " + QString::number(e) +
                                            "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                            )
                                    );

    if(!isArgumentsCorrect())
        return;

    p_logout->p_logout_text->append("-------------------------------------\n\n");

    double temp = b - h;
    int counter = 0;

    double integral_previous = 0, integral_current = 0;

    while(true)
    {
        while(x <= temp)
        {
            p_logout->p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(++counter) + QString("    ------------------"));
            p_logout->p_logout_text->append("Step " + QString::number(x) + " / " + QString::number(temp));
            p_logout->p_logout_text->append("sum = " + QString::number(sum));

            sum += sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6));
            x += h;
        }

        integral_current = h * sum;

        if(integral_current - integral_previous <= e)
            break;

        integral_previous = integral_current;
        h /= 2;
        sum = 0;
        x = a;
    }

    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " + QString::number(integral_current)
                                    );
}

void MainWindow::Method2()
{}

bool MainWindow::isArgumentsCorrect()
{
    p_logout->p_logout_text->append("-------------------------------------"
                                    "\nChecking for arguments...");
    if(a >= b)
    {
        p_logout->p_logout_text->append("\nError : a >= b");
        return false;
    }

    p_logout->p_logout_text->append("\nAll arguments are normal...");

    return true;
}
