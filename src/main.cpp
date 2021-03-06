#define DEBUG

#include <iostream>
#include <fstream>

#include <json/value.h>
#include <json/json.h>

#include <block.h>
#include <blockchain.h>
#include <validator.h>
#include <server/server.h>

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
    
    int size = config["configuration"]["blocks"].size();
    uint32_t difficulty = config["configuration"]["difficulty"].asUInt();

    BC::Blockchain chain(difficulty);

    for(int i = 0; i < size; ++i) 
    {
        #ifdef DEBUG
        std::cout << "Mining Block with data: " << config["configuration"]["blocks"][i]["data"].asString() << std::endl;
        #endif

        chain.addBlock(BC::Block(i, config["configuration"]["blocks"][i]["data"].asString()));
    }

    BC::Server s(["configuration"]["serverConfig"]["port"].asInt(), ["configuration"]["serverConfig"]["threads"].asInt());

    s.startServer();
}