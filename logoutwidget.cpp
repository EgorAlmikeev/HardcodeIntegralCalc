#include "logoutwidget.h"

LogoutWidget::LogoutWidget()
{
    p_layout = new QVBoxLayout;

    setLayout(p_layout);

    p_logout_text = new QTextEdit;
    p_close_button = new QPushButton("Close");

    p_logout_text->setFontPointSize(16);

    p_logout_text->setReadOnly(true);

    p_layout->addWidget(p_logout_text);
    p_layout->addWidget(p_close_button);

    connect(p_close_button, SIGNAL(clicked(bool)), SIGNAL(CloseButtonClicked()));
}
