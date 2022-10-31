#include "checktriangle.h"
#include <QGridLayout>
#include <QPushButton>
#include <cmath>


CheckTriangle::CheckTriangle(QWidget *parent)
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

    result.setParent(this);
    result.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    result.setMaximumSize(QSize{300, 30});

    QPushButton *checkBtn = new QPushButton("check", this);
    checkBtn->resize(50, 30);
    checkBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(&textA,   0, 0);
    grid->addWidget(&textB,   1, 0);
    grid->addWidget(&textC,   2, 0);
    grid->addWidget(checkBtn, 4, 0);
    grid->addWidget(&result,  5, 0);
    grid->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    setLayout(grid);

    connect(checkBtn, &QPushButton::clicked, this, &CheckTriangle::CheckInput);
}

void CheckTriangle::CheckInput(){
    bool convert_res = true;
    float A = textA.toPlainText().toFloat(&convert_res);
    float B = textB.toPlainText().toFloat(&convert_res);
    float C = textC.toPlainText().toFloat(&convert_res);

    if(!convert_res){
        result.setText("Failed to convert to float");
        return;
    }

    if(A + B < C ||
       B + C < A ||
       A + C < B ||
       A <= 0 || B <= 0 || C <= 0){
        result.setText("Triangle is not exiting");
        return;
    }

    float p = (A + B +C) / 2;
    float S = sqrt(p * (p-A) * (p-B) * (p-C));

    result.setText(QString::number(S));
}
