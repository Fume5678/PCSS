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

    if (url == std::tuple("POST", "/task_1")) {
        return task_1(request);
    }
    if (url == std::tuple("POST", "/task_2")) {
        return task_2(request);
    }
    if (url == std::tuple("GET", "/task_3")) {
        return task_3(request);
    }
    if (url == std::tuple("GET", "/task_4")) {
        return task_4(request);
    }
    if (url == std::tuple("GET", "/task_5")) {
        return task_5(request);
    } else {
        Response resp;
        resp.status     = "Not Found";
        resp.statusCode = 404;
        return resp;
    }
}


httpparser::Response RequestHandler::task_1(httpparser::Request req) {
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

    int i = 1;
    int s = 3;

    while (true){
        s = 3 * i;

        if (s >= val){
            break;
        }
        i++;
    }

    std::string body = std::to_string(3*(i-1));

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}


httpparser::Response RequestHandler::task_2(httpparser::Request req) {
    float a;
    try {
        json   data = json::parse(req.content_as_str());
        a = data.at("a").get<float>() / 1000;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        Response resp;
        resp.statusCode = 400;
        resp.status     = "Bad Request";
        return resp;
    }

    float x, y;
    for (x = -2+0.75; x < 8; x += 0.75){
        y = (4*x - 3 * x + tan(x)) / a;
    }

    std::string body;
    body = std::to_string(y);


    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body);
    return resp;
}


httpparser::Response RequestHandler::task_3(httpparser::Request req) {
    std::vector<float> positive_numbers;

    float x, z;
    for (x = 5-1.2; x > -12; x -= 1.2){
        z = sin(x) - 5*cos(x-2);

        if(z > 0){
            positive_numbers.push_back(z);
        }
    }

    nlohmann::json body = {
        {"numbers", positive_numbers}
    };

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body.dump(2));
    return resp;
}


httpparser::Response RequestHandler::task_4(httpparser::Request req) {
    std::vector<float> positive_numbers;

    float x, z;
    for (x = -5+1.2; x < 12; x += 1.2){
        z = sin(x) + 5*cos(x-2);

        if(z > 0){
            positive_numbers.push_back(z);
        }
    }

    nlohmann::json body = {
        {"numbers", positive_numbers}
    };

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body.dump(2));
    return resp;
}


httpparser::Response RequestHandler::task_5(httpparser::Request req) {
    std::vector<float> positive_numbers;

    float x, z;
    for (x = 3; x < 8; x += 0.9){
        z = log(x) + tan(2 * x);

        if(z > 1){
            positive_numbers.push_back(z);
        }
    }

    nlohmann::json body = {
        {"numbers", positive_numbers}
    };

    Response resp;
    resp.statusCode = 200;
    resp.status     = "Ok";
    resp.str_to_content(body.dump(2));
    return resp;
}


