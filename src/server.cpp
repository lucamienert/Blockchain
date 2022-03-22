#include "include/server.h"

/**
 * @brief Construct a new BC::Server::Server object
 */
BC::Server::Server(int port, int threads)
{
	this->ws = httpserver::create_webserver(port)
        .start_method(httpserver::http::http_utils::INTERNAL_SELECT)
        .max_threads(threads);

    registerResources();
}

void registerResources()
{
	BC::TestResource testResource;

    this->ws.register_resource("/hello", &testResource, true);
}

void BC::Server::startServer()
{
	this->ws.start(true);
}

void BC::Server::stopServer()
{
	this->ws.start(false);
}