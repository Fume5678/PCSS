/*
 * Task 4
 *
*/
#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class CheckPoint: public QWidget
{
    Q_OBJECT
public:
    CheckPoint(QWidget *parent = 0);


private:
    QTextEdit textA1;
    QTextEdit textA2;
    QTextEdit textA3;
    QLabel result;

private slots:
    void CheckInput();
};

#endif // CHECKPOINT_H
