#include "checkpoint.h"
#include <QGridLayout>
#include <QPushButton>
#include <cmath>


CheckPoint::CheckPoint(QWidget *parent)
{
    textA1.setParent(this);
    textA1.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textA1.setMaximumSize(QSize{300, 40});
    textA1.setPlaceholderText("A1");

    textA2.setParent(this);
    textA2.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textA2.setMaximumSize(QSize{300, 40});
    textA2.setPlaceholderText("A2");

    textA3.setParent(this);
    textA3.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textA3.setMaximumSize(QSize{300, 40});
    textA3.setPlaceholderText("A3");

    QPushButton *checkBtn = new QPushButton("check", this);
    checkBtn->resize(50, 30);
    checkBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(&textA1,  0, 0);
    grid->addWidget(&textA2,  1, 0);
    grid->addWidget(&textA3,  2, 0);
    grid->addWidget(checkBtn, 5, 0);
    grid->addWidget(&result,  6, 0);
    grid->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    setLayout(grid);

    connect(checkBtn, &QPushButton::clicked, this, &CheckPoint::CheckInput);
}

void CheckPoint::CheckInput(){
    bool convert_res = true;
    float a1 = textA1.toPlainText().toFloat(&convert_res);
    float a2 = textA2.toPlainText().toFloat(&convert_res);
    float a3 = textA3.toPlainText().toFloat(&convert_res);

    if(!convert_res){
        result.setText("Failed to convert to float");
        return;
    }

    if(a1 + a2 < 0){
        result.setText("Error: sqrt: a1 + a2 < 0");
        return;
    }
    float c = sqrt(a1 + a1);
    float b = a1 + 0.7 * a3;

    if(c < 5 && b < 10){
        result.setText("D point in square 5 10");
    } else {
        result.setText("D point NOT in square 5 10");
    }

}

