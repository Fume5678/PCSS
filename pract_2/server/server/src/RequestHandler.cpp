#include <RequestHandler.h>
#include <string>
#include <utility>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace httpparser;
using namespace nlohmann;
using std::string;

std::string RequestHandler::get_response(Request request) {
    return route(request).serialize();
}

Response RequestHandler::route(Request request) {
    std::tuple url(request.method, request.uri);

    if (url == std::tuple("POST", "/task_22")) {
        return task_22(request);
    } else {
        Response resp;
        resp.status     = "Not Found";
        resp.statusCode = 404;
        return resp;
    }
}

httpparser::Response RequestHandler::task_22(httpparser::Request req) {
    int val;
    try {
        json   data = json::parse(req.content_as_str());
        val = data.at("val").get<float>();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        Response resp;
        resp.statusCode = 400;
        resp.status     = "Bad Request";
        return resp;
    }

    std::string body;
    if (val % 2 == 0){
        body = "0";
    } else {
        body = "1";
    }

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}

