#include <iostream>
#include <string.h>
#include <arpa/inet.h>

#include "ArgsParser.h"


ArgsParser::ArgsParser(int argc, const char **argv) : argc(argc), argv(argv) { }

int ArgsParser::parse() {
    if (argc < 5) {
        std::cout << "Too few arguments: " << argc - 1 << std::endl;
        return -1;
    }

    if (argc > 5) {
        std::cout << "Too many arguments: " << argc - 1 << std::endl;
        return -1;
    }


    clientsIPfile = argv[1];


    bandwidth = atol(argv[2]);


    memset(&echoServerAddr, 0, sizeof(echoServerAddr));  
	echoServerAddr.sin_family = AF_INET;  

    int ret = inet_aton(argv[3], &echoServerAddr.sin_addr);
    if (ret == 0) {
        std::cout << "Invalid echo server address: " << std::string(argv[3]) << std::endl;
        return -1;
    }


    int echoServerPort = atoi(argv[4]);
    if (!(echoServerPort >= 0 && echoServerPort <= 65535)) {
        std::cout << "Invalid echo server port: " << echoServerPort << std::endl;
        return -1;
    }
	echoServerAddr.sin_port = htons((ushort)echoServerPort);  

    return 0;
}

std::string ArgsParser::getClientsIPfile() const {
    return clientsIPfile;
}

size_t ArgsParser::getBandwidth() const {
    return bandwidth;
}

sockaddr_in ArgsParser::getEchoServer() const {
    return echoServerAddr;
}
