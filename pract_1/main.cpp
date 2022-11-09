
#include <QApplication>
#include <checknumber.h>
#include <calculatexy.h>
#include <checktriangle.h>
#include <checksquare.h>
#include <checkpoint.h>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.resize(800, 1200);

    QGridLayout grid(&widget);

    CheckNumber cn;
    CheckPoint cp;
    CheckSquare cs;
    CheckTriangle ct;
    CalculateXY cxy;
    grid.addWidget(&cn);
    grid.addWidget(&ct);
    grid.addWidget(&cxy);
    grid.addWidget(&cs);
    grid.addWidget(&cp);

    widget.show();


    return a.exec();
}
