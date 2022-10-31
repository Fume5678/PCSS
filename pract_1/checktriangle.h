/*
 * Task 25
 *
*/
#ifndef CHECKTRIANGLE_H
#define CHECKTRIANGLE_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class CheckTriangle: public QWidget
{
    Q_OBJECT
public:
    CheckTriangle(QWidget *parent = 0);


private:
    QTextEdit textA;
    QTextEdit textB;
    QTextEdit textC;
    QLabel result;

private slots:
    void CheckInput();
};

#endif // CHECKTRIANGLE_H
