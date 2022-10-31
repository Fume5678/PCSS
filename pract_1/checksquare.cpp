#include "checksquare.h"
#include <QGridLayout>
#include <QPushButton>
#include <cmath>

CheckSquare::CheckSquare(QWidget *parent)
{
    textA.setParent(this);
    textA.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textA.setMaximumSize(QSize{300, 40});
    textA.setPlaceholderText("A");

    textB.setParent(this);
    textB.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textB.setMaximumSize(QSize{300, 40});
    textB.setPlaceholderText("B");

    textC.setParent(this);
    textC.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textC.setMaximumSize(QSize{300, 40});
    textC.setPlaceholderText("C");

    textD.setParent(this);
    textD.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textD.setMaximumSize(QSize{300, 40});
    textD.setPlaceholderText("D");

    result.setParent(this);
    result.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    result.setMaximumSize(QSize{300, 30});

    QPushButton *checkBtn = new QPushButton("check", this);
    checkBtn->resize(50, 30);
    checkBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(&textA,   0, 0);
    grid->addWidget(&textB,   1, 0);
    grid->addWidget(&textC,   3, 0);
    grid->addWidget(&textD,   4, 0);
    grid->addWidget(checkBtn, 5, 0);
    grid->addWidget(&result,  6, 0);
    grid->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    setLayout(grid);

    connect(checkBtn, &QPushButton::clicked, this, &CheckSquare::CheckInput);
}

void CheckSquare::CheckInput(){
    bool convert_res = true;
    float A = textA.toPlainText().toFloat(&convert_res);
    float B = textB.toPlainText().toFloat(&convert_res);
    float C = textC.toPlainText().toFloat(&convert_res);
    float D = textD.toPlainText().toFloat(&convert_res);

    if(!convert_res){
        result.setText("Failed to convert to float");
        return;
    }

    if(A < C || B < D){
        result.setText("Big rect CAN'T contain small sqaure");
    } else {
        result.setText("Big rect CAN contain small sqaure");
    }
}
