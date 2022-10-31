#include "checknumber.h"
#include <QGridLayout>
#include <QPushButton>

CheckNumber::CheckNumber(QWidget *parent) : QWidget{parent}
{
    textA.setParent(this);
    textA.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textA.setMaximumSize(QSize{300, 40});

    textB.setParent(this);
    textB.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textB.setMaximumSize(QSize{300, 40});

    textC.setParent(this);
    textC.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textC.setMaximumSize(QSize{300, 40});

    textD.setParent(this);
    textD.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textD.setMaximumSize(QSize{300, 40});

    err.setParent(this);
    err.setStyleSheet("QLabel{ color: red }");
    err.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    err.setAlignment(Qt::AlignTrailing);
    err.setMinimumSize(QSize{200, 40});

    result.setParent(this);
    result.setText("result");
    result.setStyleSheet("QLabel{ }");
    result.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    result.setAlignment(Qt::AlignTrailing);
    result.setMinimumSize(QSize{200, 40});


    QPushButton *checkBtn = new QPushButton("check", this);
    checkBtn->resize(50, 30);
    checkBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(&result,  2, 1);
    grid->addWidget(&err,     3, 1);
    grid->addWidget(&textA,   0, 0);
    grid->addWidget(&textB,   1, 0);
    grid->addWidget(&textC,   2, 0);
    grid->addWidget(&textD,   3, 0);
    grid->addWidget(checkBtn, 4, 0);
    grid->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    setLayout(grid);

    connect(checkBtn, &QPushButton::clicked, this, &CheckNumber::CheckInput);
}

void CheckNumber::CheckInput()
{
    bool res;
    float A = textA.toPlainText().toFloat(&res);
    if(!res){
        err.setText("failed to parse text A to float");
        return;
    }

    float B = textB.toPlainText().toFloat(&res);
    if(!res){
        err.setText("failed to parse text B to float");
        return;
    }

    float C = textC.toPlainText().toFloat(&res);
    if(!res){
        err.setText("failed to parse text C to float");
        return;
    }

    float D = textD.toPlainText().toFloat(&res);
    if(!res){
        err.setText("failed to parse text D to float");
        return;
    }
    err.setText("");

    if(!(3 < A && A < 15)){
        result.setText("A not in range (3, 15)");
        return;
    }

    if(!(3 < B && B < 15)){
        result.setText("B not in range (3, 15)");
        return;
    }

    if(!(3 < C && C < 15)){
        result.setText("C not in range (3, 15)");
        return;
    }

    if(!(3 < D && D < 15)){
        result.setText("D not in range (3, 15)");
        return;
    }

    result.setText("All in range (3, 15)");
    return;
}
