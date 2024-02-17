#include <fstream>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>

#include "ClientsReader.h"


ClientsReader::ClientsReader(const std::string& filename) : filename(filename) { }

void ClientsReader::read(UDPClients& udpClients) const {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cout << "Failed to open " << filename << std::endl;
        return;
    }

    std::string ip;
    size_t lineCounter = 0;

    while (ifs >> ip) {
        lineCounter++;

        sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));  

        int ret = inet_aton(ip.c_str(), &clientAddr.sin_addr);
        if (ret == 0) {
            std::cout << "Invalid client address on line " << lineCounter << ": " << ip << std::endl;
            continue;
        }

        if (udpClients.hasClient(clientAddr.sin_addr.s_addr)) {
            continue;
        }

	    clientAddr.sin_family = AF_INET;  
        clientAddr.sin_port = htons((uint16_t)8888);

        udpClients.addClient(clientAddr);
    }
}
