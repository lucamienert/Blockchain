#include "../include/resources.h"

/**
 * @brief Initialising Resource
 * 
 * @param httpserver::http_request 
 */
const std::shared_ptr<httpserver::http_response> BC::TestResource::render(const httpserver::http_request&)
{
	return std::shared_ptr<httpserver::http_response>(new httpserver::string_response("Test"));
}