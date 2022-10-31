#ifndef REQUESTS_H
#define REQUESTS_H

#include <boost/asio/io_context.hpp>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>
#include <httpparser/request.h>
#include <httpparser/response.h>
#include <httpparser/httpresponseparser.h>

class RequestsExec
{
public:
    RequestsExec(std::string server_addr);

    httpparser::Response exec(httpparser::Request req);

private:
    std::string             server_addr;
    boost::asio::io_context context;
};

#endif // REQUESTS_H
