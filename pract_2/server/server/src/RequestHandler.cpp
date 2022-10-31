#include <RequestHandler.h>
#include <string>
#include <utility>
#include <iostream>
#include <nlohmann/json.hpp>
#include <bitset>

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
    }
    if (url == std::tuple("POST", "/task_25")) {
        return task_25(request);
    }
    if (url == std::tuple("POST", "/task_28")) {
        return task_28(request);
    }
    if (url == std::tuple("POST", "/task_1")) {
        return task_1(request);
    }
    if (url == std::tuple("POST", "/task_4")) {
        return task_4(request);
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

httpparser::Response RequestHandler::task_25(httpparser::Request req) {
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
    if (val > 0 && (val & (val - 1)) == 0){
        val = log2(val);
        body = std::to_string(val);
    } else {
        body = "Not a power of 2";
    }

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}

httpparser::Response RequestHandler::task_28(httpparser::Request req) {
    float X, Y;
    try {
        json   data = json::parse(req.content_as_str());
        X = data.at("X").get<float>() / 1000;
        Y = data.at("Y").get<float>() / 1000;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        Response resp;
        resp.statusCode = 400;
        resp.status     = "Bad Request";
        return resp;
    }

    std::string body;
    float res = (2 * pow(X, 3) - 4 * pow(X, 2) + X +1) / (9 * pow(Y, 3) + Y + 4) + 3*pow(Y, 2) + 5 * Y;

    body = std::to_string(res);

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}


httpparser::Response RequestHandler::task_1(httpparser::Request req) {
    float val;
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
    float res = val / 100;

    body = std::to_string(res);

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}


httpparser::Response RequestHandler::task_4(httpparser::Request req) {
    std::string val;
    try {
        json   data = json::parse(req.content_as_str());
        val = data.at("val").get<std::string>();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        Response resp;
        resp.statusCode = 400;
        resp.status     = "Bad Request";
        return resp;
    }

    std::string body;
    unsigned long dec = std::bitset<8>(val).to_ulong();

    body = std::to_string(dec);

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}


