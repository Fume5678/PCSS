#include "calculatexy.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <cmath>
#include <QString>

CalculateXY::CalculateXY(QWidget *parent)
    : QWidget{parent}
{
    textX.setParent(this);
    textX.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textX.setMaximumSize(QSize{300, 40});

    textY.setParent(this);
    textY.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textY.setMaximumSize(QSize{300, 40});

    res.setParent(this);
    res.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    res.setMaximumSize(QSize{300, 30});

    QPushButton *checkBtn = new QPushButton("calculate", this);
    checkBtn->resize(80, 30);
    checkBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignTop);

    vbox->addWidget(&textX, 0);
    vbox->addWidget(&textY, 1);
    vbox->addWidget(checkBtn, 2);
    vbox->addWidget(&res, 3);

    connect(checkBtn, &QPushButton::clicked, this, &CalculateXY::Calc);
}

void CalculateXY::Calc()
{
    bool convert_res = true;
    float x = textX.toPlainText().toFloat(&convert_res);
    float y = textX.toPlainText().toFloat(&convert_res);

    if(!convert_res){
        res.setText("Failed to convert");
        return;
    }

    float z = asin(x+y);

    res.setText(QString::number(z));

}
