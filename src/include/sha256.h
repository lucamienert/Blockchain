#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <openssl/sha.h>

namespace BC
{
    std::string sha256(const std::string string);
}