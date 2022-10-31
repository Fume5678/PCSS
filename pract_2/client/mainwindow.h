#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

static const QString SERVER_URL = "127.0.0.1:1234";

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void task_22();
    void task_25();
    void task_28();
    void task_1();
    void task_4();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
