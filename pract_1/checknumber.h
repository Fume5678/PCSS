/*
 * Task 22
 *
*/

#ifndef CHECKNUMBER_H
#define CHECKNUMBER_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class CheckNumber : public QWidget
{
    Q_OBJECT
public:
    CheckNumber(QWidget *parent = 0);

private:
    QTextEdit textA;
    QTextEdit textB;
    QTextEdit textC;
    QTextEdit textD;
    QLabel err;
    QLabel result;

private slots:
    void CheckInput();


};

#endif // CHECKNUMBER_H
