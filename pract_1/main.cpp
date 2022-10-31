
#include <QApplication>
#include <checknumber.h>
#include <calculatexy.h>
#include <checktriangle.h>
#include <checksquare.h>
#include <checkpoint.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CheckPoint cxy;

    cxy.resize(800, 600);
    cxy.show();

    return a.exec();
}
