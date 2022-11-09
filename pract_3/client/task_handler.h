#ifndef TASK_1_H
#define TASK_1_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <memory>
#include <functional>
#include <vector>

class Task_Handler : public QWidget
{
    Q_OBJECT


public:
    std::vector<QTextEdit*> inputs;
    QLabel* result;

    Task_Handler(
            int input_amount = 1,
            QString title_text = "",
            QWidget* parent = nullptr);

    template<typename ActFunc>
    void setCallback(std::function<ActFunc> func)
    {
        connect(btn, &QPushButton::clicked, func);
    }


private:
    int count_input;
    QPushButton* btn;
};

#endif // TASK_1_H
