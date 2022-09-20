#pragma once

#include <string>
#include <vector>

namespace Utils
{
	std::string vectorToString(std::vector vec)
	{
		str::string str(vec.begin(), vec.end());
		return str;
	}
}