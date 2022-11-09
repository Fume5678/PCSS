#include "request_exec.h"
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <nlohmann/json.hpp>
#include <QtDebug>
#include <QString>

using namespace std;
using namespace boost::asio::ip;

RequestsExecutor::RequestsExecutor(std::string server_addr) : server_addr{server_addr}{

}

httpparser::Response RequestsExecutor::exec(httpparser::Request req){
    httpparser::Response resp;
    tcp::socket socket{context};

    std::string host = server_addr.substr(0, server_addr.find(":"));
     std::string port = server_addr.substr(server_addr.find(":") + 1, server_addr.length());
     // connection
     socket.connect(tcp::endpoint(
         address::from_string(host),
         std::stoi(port)));

     boost::system::error_code error;
     std::string buf = req.serialize();
     //std::cerr << "[INFO] request: " << buf << std::endl;
     auto buffer_tmp = boost::asio::buffer(buf);
     boost::asio::write(socket, buffer_tmp, error);

     if (error) {
         QString qmsg = QString::fromStdString(error.message());
         qDebug() << "[ERROR] Send failed: " << qmsg << Qt::endl;
     }

     boost::asio::streambuf receive_buffer;
     boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
     if( error && error != boost::asio::error::eof ) {
         QString qmsg = QString::fromStdString(error.message());
         qDebug() << "[ERRO] Recieve failed: " << qmsg << Qt::endl;
     }
     else {
         const char* c_data = boost::asio::buffer_cast<const char*>(receive_buffer.data());

         string data{c_data};

         //std::cerr << "[INFO] responce: " << data << std::endl;

         httpparser::HttpResponseParser parser;
         int res = parser.parse(
             resp, data.c_str(), data.c_str() + data.length());

         if(res != httpparser::HttpResponseParser::ParsingCompleted) {
             qDebug() << "Fail parse responce" << Qt::endl;
         }
         else {
             qInfo()  << "Ok" << Qt::endl;
         }
     }

     return resp;

}
