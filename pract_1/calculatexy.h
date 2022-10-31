/*
 * Task 28
 *
*/

#ifndef CALCULATEXY_H
#define CALCULATEXY_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class CalculateXY : public QWidget
{
    Q_OBJECT
public:
    explicit CalculateXY(QWidget *parent = nullptr);

private:
    QTextEdit textX;
    QTextEdit textY;
    QLabel res;

private slots:
    void Calc();

signals:

};

#endif // CALCULATEXY_H
