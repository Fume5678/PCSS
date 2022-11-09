#include "task_handler.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QTextStream>
#include <httpparser/request.h>
#include <httpparser/response.h>
#include <request_exec.h>

using httpparser::Request;
using httpparser::Response;
using namespace std;

static const string SERVER_ADDR = "127.0.0.1:1234";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.show();
    w.resize(700, 1000);

    QVBoxLayout* vbox = new QVBoxLayout(&w);

    // Task 1
    Task_Handler task1(1, "task 1", &w);
    task1.setCallback(std::function([&t=task1](){
        bool res = false;
        float val = t.inputs.at(0)->toPlainText().toFloat(&res);
        if(!res){
            t.result->setText("Input float!");
            return;
        }

        nlohmann::json placeholder = {
            {"val", val},
        };

        RequestsExecutor ex(SERVER_ADDR);
        Request req;
        req.uri = "/task_1";
        req.method = "POST";
        req.str_to_content(placeholder.dump());

        try{
              auto resp = ex.exec(req);
              if (resp.statusCode == 200){
                  t.result->setText(QString::fromStdString(resp.content_as_str()));
              } else {
                  throw resp.statusCode ;
              }

        } catch (std::exception& e) {
            t.result->setText("Bad request: " + QString::fromStdString(e.what()));
        } catch (int& code){
            t.result->setText("Request error: " + QString(code));
        }

    }));
    vbox->addWidget(&task1);


    // Task 2
    Task_Handler task2(1, "task 2", &w);
    task2.setCallback(std::function([&t=task2](){
        bool res = false;
        float a = t.inputs.at(0)->toPlainText().toFloat(&res);
        if(!res){
            t.result->setText("Bad input!");
            return;
        }

        nlohmann::json placeholder = {
            {"a", a},
        };

        RequestsExecutor ex(SERVER_ADDR);
        Request req;
        req.uri = "/task_2";
        req.method = "POST";
        req.str_to_content(placeholder.dump());

        try{
              auto resp = ex.exec(req);
              if (resp.statusCode == 200){
                  t.result->setText(QString::fromStdString(resp.content_as_str()));
              } else {
                  throw resp.statusCode ;
              }

        } catch (std::exception& e) {
            t.result->setText("Bad request: " + QString::fromStdString(e.what()));
        } catch (int& code){
            t.result->setText("Request error: " + QString(code));
        }
    }));
    vbox->addWidget(&task2);


    // Task 3
    Task_Handler task3(0, "task 3", &w);
    task3.setCallback(std::function([&t=task3](){
        RequestsExecutor ex(SERVER_ADDR);
        Request req;
        req.uri = "/task_3";
        req.method = "GET";

        try{
              auto resp = ex.exec(req);
              if (resp.statusCode == 200){
                  t.result->setText(QString::fromStdString(resp.content_as_str()));
              } else {
                  throw resp.statusCode ;
              }

        } catch (std::exception& e) {
            t.result->setText("Bad request: " + QString::fromStdString(e.what()));
        } catch (int& code){
            t.result->setText("Request error: " + QString(code));
        }
    }));
    vbox->addWidget(&task3);


    // Task 4
    Task_Handler task4(0, "task 4", &w);
    task4.setCallback(std::function([&t=task4](){
        RequestsExecutor ex(SERVER_ADDR);
        Request req;
        req.uri = "/task_4";
        req.method = "GET";

        try{
              auto resp = ex.exec(req);
              if (resp.statusCode == 200){
                  t.result->setText(QString::fromStdString(resp.content_as_str()));
              } else {
                  throw resp.statusCode ;
              }

        } catch (std::exception& e) {
            t.result->setText("Bad request: " + QString::fromStdString(e.what()));
        } catch (int& code){
            t.result->setText("Request error: " + QString(code));
        }
    }));
    vbox->addWidget(&task4);


    // Task 5
    Task_Handler task5(1, "task 5", &w);
    task5.setCallback(std::function([&t=task5](){
        RequestsExecutor ex(SERVER_ADDR);
        Request req;
        req.uri = "/task_5";
        req.method = "GET";

        try{
              auto resp = ex.exec(req);
              if (resp.statusCode == 200){
                  t.result->setText(QString::fromStdString(resp.content_as_str()));
              } else {
                  throw resp.statusCode ;
              }

        } catch (std::exception& e) {
            t.result->setText("Bad request: " + QString::fromStdString(e.what()));
        } catch (int& code){
            t.result->setText("Request error: " + QString(code));
        }
    }));
    vbox->addWidget(&task5);


    vbox->setAlignment(Qt::AlignTop | Qt::AlignCenter);


    w.setLayout(vbox);
    return a.exec();
}
