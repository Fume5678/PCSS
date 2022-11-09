#include "task_handler.h"
#include <QGridLayout>
#include <QPushButton>

using namespace std;

Task_Handler::Task_Handler(int input_amount, QString title_text, QWidget* parent)
    : QWidget{parent}
{

    QLabel* label = new QLabel(this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label->setMaximumSize(QSize{350, 30});
    label->setStyleSheet("QLabel{font-size: 18px; font-weight: bold;}");
    label->setText(title_text);

    result = new QLabel(this);
    result->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    result->setMaximumSize(QSize{350, 500});
    result->setText("Here will be result!");
    result->setWordWrap(true);

    for (int i = 0; i < input_amount; i++){
        QTextEdit* new_input = new QTextEdit(this);
        new_input->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        new_input->setMaximumSize(QSize{350, 40});
        inputs.push_back(new_input);
    }

    btn = new QPushButton(this);
    btn->setText("get res");
    btn->resize(50, 30);
    btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    int row = 0;
    QGridLayout* grid = new QGridLayout(this);
    grid->addWidget(label, row++, 0);
    for(auto vinp : inputs){
        grid->addWidget(vinp, row++, 0);
    }

    grid->addWidget(btn, row++, 0);
    grid->addWidget(result, row++, 0);
    grid->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    setLayout(grid);

    connect(btn, &QPushButton::clicked, []{});
}
