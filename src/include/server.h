#pragma once

#include <httpserver.hpp>

#include "resources.h"

namespace BC
{
	class Server
	{
		public:
			Server(int port, int threads);
	};
}