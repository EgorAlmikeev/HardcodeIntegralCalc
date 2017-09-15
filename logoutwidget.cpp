#include "logoutwidget.h"

LogoutWidget::LogoutWidget()
{
    p_layout = new QVBoxLayout;

    setLayout(p_layout);

    p_logout_text = new QTextEdit;
    p_close_button = new QPushButton("Close");

    p_logout_text->setFontPointSize(12);

    p_logout_text->setReadOnly(true);

    p_layout->addWidget(p_logout_text);
    p_layout->addWidget(p_close_button);

    connect(p_close_button, SIGNAL(clicked(bool)), SIGNAL(CloseButtonClicked()));
}

void LogoutWidget::LogIteration(double iteration_number, double current_x, double maximum_x, double current_sum)
{
    p_logout_text->append(QString("------------------    ") + QString("iteration ") + QString::number(iteration_number) + QString("    ------------------"));
    p_logout_text->append("Step " + QString::number(current_x) + " / " + QString::number(maximum_x));
    p_logout_text->append("sum = " + QString::number(current_sum));
}

void LogoutWidget::InitializeCalculatingMethod(QString method_name, double _a, double _b, int _n, double _h, double _x)
{
    p_logout_text->append(QString("Start calculating \"" + method_name + "\" method..."
                                  "\n-------------------------------------"
                                  "\nArguments :"
                                  "\na = " + QString::number(_a) +
                                  "\nb = " + QString::number(_b) +
                                  "\nn = " + QString::number(_n) +
                                  "\nh = (b - a) / n = " + QString::number(_h) +
                                  "\nx = " + QString::number(_x) +
                                  "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                  )
                          );
}

void LogoutWidget::InitializeCalculatingMethod(QString method_name, double _a, double _b, int _n, double _h, double _x, double _e)
{
    p_logout_text->append(QString("Start calculating \"" + method_name + "\" method..."
                                  "\n-------------------------------------"
                                  "\nArguments :"
                                  "\na = " + QString::number(_a) +
                                  "\nb = " + QString::number(_b) +
                                  "\nn = " + QString::number(_n) +
                                  "\nh = (b - a) / n = " + QString::number(_h) +
                                  "\nx = " + QString::number(_x) +
                                  "\ne = " + QString::number(_e) +
                                  "\nf(x) = sqrt(0.5 * x * x + 3) / (2 * x + sqrt(2 * x * x + 1.6))"
                                  )
                          );
}

void LogoutWidget::EndOfCalculating(double _integral_value)
{
    p_logout_text->append("-------------------------------------"
                                    "\nCalculating is successfully finished"
                                    "\nIntegral = " + QString::number(_integral_value, 'g', 30)
                                    );
}
