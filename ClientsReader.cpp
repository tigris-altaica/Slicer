#include <fstream>
#include <iostream>
#include <string.h>

#include "ClientsReader.h"


ClientsReader::ClientsReader(const std::string& fn) : fileName(fn) { }

void ClientsReader::read() {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    std::string ip;
    size_t lineCounter = 0;

    while (ifs >> ip) {
        lineCounter++;

        sockaddr_in clientAddr;

        memset(&clientAddr, 0, sizeof(clientAddr));  
	    clientAddr.sin_family = AF_INET;  

        int ret = inet_aton(ip.c_str(), &clientAddr.sin_addr);
        if (ret == 0) {
            std::cout << "Invalid client address on line " << lineCounter << ": " << ip << std::endl;
            continue;
        }

        clientAddr.sin_port = htons((ushort)8000);

        if (!clients.contains(ip)) {
            clients.insert(ip);
            //udpc.addClient(clientAddr);
        }
    }
}
