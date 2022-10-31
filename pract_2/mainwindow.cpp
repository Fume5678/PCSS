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

