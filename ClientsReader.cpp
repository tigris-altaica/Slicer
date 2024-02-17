#include <fstream>
#include <iostream>
#include <string.h>

#include "ClientsReader.h"


ClientsReader::ClientsReader(const std::string& fn) : filename(fn) { }

void ClientsReader::read(UDPClient& udpc) {
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
	    clientAddr.sin_family = AF_INET;  

        int ret = inet_aton(ip.c_str(), &clientAddr.sin_addr);
        if (ret == 0) {
            std::cout << "Invalid client address on line " << lineCounter << ": " << ip << std::endl;
            continue;
        }

        clientAddr.sin_port = htons((ushort)8888);

        if (!clients.contains(clientAddr.sin_addr.s_addr)) {
            clients.insert(clientAddr.sin_addr.s_addr);

            int sock = udpc.addClient(clientAddr);
            if (sock != -1) {
                udpc.sendData(sock);
            }
        }
    }
}
