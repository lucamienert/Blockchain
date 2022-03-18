#pragma once

#include "block.h"
#include "blockchain.h"
#include "sha256.h"

namespace BC
{
    bool isValidNewBlock(BC::Block block, BC::Block prevBlock);
    bool isValidChain(BC::Blockchain blockchain);
}