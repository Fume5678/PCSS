#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include "requests.h"
#include <httpparser/request.h>
#include <httpparser/response.h>


using httpparser::Request;
using httpparser::Response;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->t22_pbtn, &QPushButton::clicked, this, &MainWindow::task_22);
    connect(ui->t25_pbtn, &QPushButton::clicked, this, &MainWindow::task_25);
    connect(ui->t28_pbtn, &QPushButton::clicked, this, &MainWindow::task_28);
    connect(ui->t1_pbtn, &QPushButton::clicked, this, &MainWindow::task_1);
    connect(ui->t4_pbtn, &QPushButton::clicked, this, &MainWindow::task_4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::task_22(){
    bool res;
    int val = ui->t22_input->toPlainText().toInt(&res);

    if(!res){
        ui->t22_res->setText("Введите число!!!");
        return;
    }

    RequestsExec re(SERVER_URL.toStdString());

    Request req;
    req.uri = "/task_22";
    req.method = "POST";
    nlohmann::json body = {
        {"val", val}
    };

    httpparser::Request::HeaderItem cont_type{"Content-Type", "application/json"};
    req.headers.push_back(cont_type);
    req.str_to_content(body.dump());

    try{
          std::string resp = re.exec(req).content_as_str();

          if (resp == "1") {
              ui->t22_res->setText("Нечетное");
          } else {
              ui->t22_res->setText("Четное");
          }

    } catch (std::exception& e) {
        ui->t22_res->setText("Bad request");
    }
}

void MainWindow::task_25(){
    bool res;
    int val = ui->t25_input->toPlainText().toInt(&res);

    if(!res){
        ui->t25_res->setText("Введите число!!!");
        return;
    }

    RequestsExec re(SERVER_URL.toStdString());

    Request req;
    req.uri = "/task_25";
    req.method = "POST";
    nlohmann::json body = {
        {"val", val}
    };

    httpparser::Request::HeaderItem cont_type{"Content-Type", "application/json"};
    req.headers.push_back(cont_type);
    req.str_to_content(body.dump());

    try{
          std::string resp = re.exec(req).content_as_str();
          ui->t25_res->setText(QString::fromStdString(resp));
    } catch (std::exception& e) {
        ui->t25_res->setText("Bad request");
    }
}


void MainWindow::task_28(){
    bool res;
    float X = ui->t28_input_1->toPlainText().toFloat(&res);
    if(!res){
        ui->t28_res->setText("Введите число!!!");
        return;
    }

    float Y = ui->t28_input_2->toPlainText().toFloat(&res);
    if(!res){
        ui->t28_res->setText("Введите число!!!");
        return;
    }


    RequestsExec re(SERVER_URL.toStdString());

    Request req;
    req.uri = "/task_28";
    req.method = "POST";
    nlohmann::json body = {
        {"X", int(X * 1000)},
        {"Y", int(Y * 1000)},
    };

    httpparser::Request::HeaderItem cont_type{"Content-Type", "application/json"};
    req.headers.push_back(cont_type);
    req.str_to_content(body.dump());

    try{
          std::string resp = re.exec(req).content_as_str();
          ui->t28_res->setText(QString::fromStdString(resp));
    } catch (std::exception& e) {
        ui->t28_res->setText("Bad request");
    }
}


void MainWindow::task_1(){
    bool res;
    float val = ui->t1_input->toPlainText().toFloat(&res);
    if(!res){
        ui->t1_res->setText("Введите число!!!");
        return;
    }


    RequestsExec re(SERVER_URL.toStdString());

    Request req;
    req.uri = "/task_1";
    req.method = "POST";
    nlohmann::json body = {
        {"val", val},
    };

    httpparser::Request::HeaderItem cont_type{"Content-Type", "application/json"};
    req.headers.push_back(cont_type);
    req.str_to_content(body.dump());

    try{
          std::string resp = re.exec(req).content_as_str();
          ui->t1_res->setText(QString::fromStdString(resp) + " sm");
    } catch (std::exception& e) {
        ui->t1_res->setText("Bad request");
    }
}


void MainWindow::task_4(){
    bool is_binary;
    QString val = ui->t4_input->toPlainText();

    for(const auto& c : val){
        if(c != '0' && c != '1'){
            ui->t4_res->setText("Введите двоичное число!!!");
            return;
        }
    }


    RequestsExec re(SERVER_URL.toStdString());

    Request req;
    req.uri = "/task_4";
    req.method = "POST";
    nlohmann::json body = {
        {"val", val.toStdString()},
    };

    httpparser::Request::HeaderItem cont_type{"Content-Type", "application/json"};
    req.headers.push_back(cont_type);
    req.str_to_content(body.dump());

    try{
          std::string resp = re.exec(req).content_as_str();
          ui->t4_res->setText(QString::fromStdString(resp));
    } catch (std::exception& e) {
        ui->t4_res->setText("Bad request");
    }
}



