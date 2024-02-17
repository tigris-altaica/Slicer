#pragma once

#include <vector>
#include <unordered_map>
#include <sys/epoll.h>


class UDPClients {
public:
    UDPClients(size_t bandwidth, sockaddr_in serverAddr);

    void addClient(sockaddr_in clientAddr);

    bool hasClient(const in_addr_t clientAddr) const;

    void sendData() const;

    void waitAndRecieveData() const;

    ~UDPClients();

private:
    void receiveDataOnSocket(int clientSocket) const;

    void sendDataOnSocket(int clientSocket) const;

    
    std::unordered_map<in_addr_t, int> clientSockets;
    const sockaddr_in serverAddr;
    int epollFd;

    static const size_t writeBufferSize = 8192;
    std::array<char, writeBufferSize> writeBuffer;

    size_t bytesPerSecond;
};