#pragma once

#include <vector>
#include <cstdint>

#include "block.h"

namespace BC
{
    class Blockchain
    {
        private:
            uint32_t diff;
            std::vector<Block> chain;

            BC::Block getLastBlock() const;

        public:
            Blockchain(uint32_t diff);
            void addBlock(BC::Block block);
    };
}