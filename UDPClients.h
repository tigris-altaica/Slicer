#pragma once

#include <vector>
#include <sys/epoll.h>

class UDPClients {
public:
    UDPClients(size_t bandwidth, sockaddr_in serverAddr);

    int addClient(sockaddr_in clientAddr);

    void receiveData();

    void sendData(int clientSocket);

    ~UDPClients();

private:
    static const size_t maxClients = 10000;
    const size_t bandwidth;
    const sockaddr_in serverAddr;
    const std::vector<char> dataBuffer;
    int epoll_fd;
    epoll_event events[maxClients];
};