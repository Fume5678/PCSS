#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H


#include <httpparser/request.h>
#include <httpparser/response.h>

class RequestHandler {
public:
    std::string get_response(httpparser::Request request);
    httpparser::Response route(httpparser::Request request);

    // REST API
    httpparser::Response task_1(httpparser::Request req);
    httpparser::Response task_2(httpparser::Request req);
    httpparser::Response task_3(httpparser::Request req);
    httpparser::Response task_4(httpparser::Request req);
    httpparser::Response task_5(httpparser::Request req);

};

#endif // REQUESTHANDLER_H
