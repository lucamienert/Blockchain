#pragma once

#include <httpserver.hpp>

namespace BC
{
	class TestResource : public httpserver::http_resource
	{
		public:
			const std::shared_ptr<httpserver::http_response> render(const httpserver::http_request&);
	};
}