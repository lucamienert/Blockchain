#pragma once

#include <cstdint>
#include <iostream>
#include <sstream>

#include "sha256.h"

namespace BC
{
    class Block
    {
        private:
            uint32_t index;
            uint32_t nonce;
            std::string data;
            time_t time;

            std::string calculateHash() const;

        public:
            std::string hash;
            std::string prevHash;

            Block(uint32_t index, const std::string &data);
            void mine(uint32_t diff);
    };
}