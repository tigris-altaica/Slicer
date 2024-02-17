#include <tuple>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>

#include "ArgsParser.h"


ArgsParser::ArgsParser(int argc, const char **argv) : argc(argc), argv(argv) { }

ArgsParser::Args ArgsParser::parse() const {
    if (argc < 5) {
        std::cout << "Too few arguments: " << argc - 1 << std::endl;
        exit(-1);
    }

    if (argc > 5) {
        std::cout << "Too many arguments: " << argc - 1 << std::endl;
        exit(-1);
    }

    std::string clientsIPfile;
    ssize_t bandwidth;
    sockaddr_in echoServerAddr;


    clientsIPfile = argv[1];


    bandwidth = atol(argv[2]);
    if (bandwidth <= 0) {
        std::cout << "Invalid bandwidth: " << argv[2] << std::endl;
        exit(-1);
    }


    memset(&echoServerAddr, 0, sizeof(echoServerAddr));  
	echoServerAddr.sin_family = AF_INET;  

    int ret = inet_aton(argv[3], &echoServerAddr.sin_addr);
    if (ret == 0) {
        std::cout << "Invalid echo server address: " << argv[3] << std::endl;
        exit(-1);
    }


    int echoServerPort = atoi(argv[4]);
    if (!(echoServerPort >= 0 && echoServerPort <= 65535)) {
        std::cout << "Invalid echo server port: " << argv[4] << std::endl;
        exit(-1);
    }
	echoServerAddr.sin_port = htons((uint16_t)echoServerPort);  
    

    return std::make_tuple(clientsIPfile, bandwidth, echoServerAddr);
}
