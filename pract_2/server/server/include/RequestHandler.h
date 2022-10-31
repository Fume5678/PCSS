#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H


#include <httpparser/request.h>
#include <httpparser/response.h>

class RequestHandler {
public:
    std::string get_response(httpparser::Request request);
    httpparser::Response route(httpparser::Request request);

    // REST API
    httpparser::Response task_22(httpparser::Request req);

};

#endif // REQUESTHANDLER_H
