#define DEBUG

#include <iostream>
#include <fstream>

#include <json/value.h>
#include <json/json.h>

#include "include/block.h"
#include "include/blockchain.h"
#include "include/validator.h"

int main(int argc, char **argv)
{

    if(argc < 2)
    {
        #ifdef DEBUG
        std::cout << "Please specify a configuration file" << std::endl;
        #endif

        exit(0);
    }
    
    Json::Value config;
    std::ifstream config_file(argv[1]);
    config_file >> config;
    
    int size = config["blocks"].size();
    uint32_t difficulty = config["difficulty"].asUInt();

    BC::Blockchain chain(difficulty);

    for(int i = 0; i < size; ++i) 
    {
        #ifdef DEBUG
        std::cout << "Mining Block with data: " << config["blocks"][i]["data"].asString() << std::endl;
        #endif

        chain.addBlock(BC::Block(i, config["blocks"][i]["data"].asString()));
    }
}