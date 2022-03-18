#include <iostream>

#include "include/block.h"
#include "include/blockchain.h"

int main(int argc, char **argv)
{
    BC::Blockchain chain;

    for(int i = 0; i < 3; ++i)
    {
        chain.addBlock(BC::Block(i, "Block Data"));
    }
}