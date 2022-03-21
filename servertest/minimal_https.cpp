#include <iostream>

#include <httpserver.hpp>

class hello_world_resource : public httpserver::http_resource {
 public:
     const std::shared_ptr<httpserver::http_response> render(const httpserver::http_request&);
     void set_some_data(const std::string &s) {data = s;}
     std::string data;
};

// Using the render method you are able to catch each type of request you receive
const std::shared_ptr<httpserver::http_response> hello_world_resource::render(const httpserver::http_request& req) {
    std::cout << "Data was: " << data << std::endl;
    std::string datapar = req.get_arg("data");
    set_some_data(datapar == "" ? "no data passed!!!" : datapar);
    std::cout << "Now data is:" << data << std::endl;
    return std::shared_ptr<httpserver::http_response>(new httpserver::string_response("Hello World!!!", 200));
}

int main() {
    httpserver::webserver ws = httpserver::create_webserver(8080).start_method(httpserver::http::http_utils::INTERNAL_SELECT).max_threads(5);

    hello_world_resource hwr;
    ws.register_resource("/hello", &hwr, true);
    ws.start(true);
    return 0;
}