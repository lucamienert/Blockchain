#pragma once

#include <httpserver.hpp>

#include "resources.h"

namespace BC
{
	class Server
	{
		private:
			httpserver::webserver ws;
		public:
			Server(int port, int threads);
			void startServer();
			void stopServer();
			void registerResources();
	};
}