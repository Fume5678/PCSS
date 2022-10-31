/*
 * Task 1
 *
*/
#ifndef CHECKSQUARE_H
#define CHECKSQUARE_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class CheckSquare: public QWidget
{
    Q_OBJECT
public:
    CheckSquare(QWidget *parent = 0);

private:
    QTextEdit textA;
    QTextEdit textB;
    QTextEdit textC;
    QTextEdit textD;
    QLabel result;

private slots:
    void CheckInput();
};

#endif // CHECKSQUARE_H
