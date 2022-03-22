#include "include/server.h"

BC::Server(int port, int threads)
{
	httpserver::webserver ws = httpserver::create_webserver(port)
        .start_method(httpserver::http::http_utils::INTERNAL_SELECT)
        .max_threads(threads);

    BC::TestResource hwr;
    ws.register_resource("/hello", &hwr, true);
    ws.start(true);
}