#include <cmath>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "UDPClients.h"


UDPClients::UDPClients(size_t bandwidth, sockaddr_in serverAddr)
    : serverAddr(serverAddr)
{
    auto bpsWithHeaders = bandwidth * 128;
    bytesPerSecond = bpsWithHeaders - 28 * std::ceil(bpsWithHeaders / float(writeBufferSize));

    writeBuffer.fill('A');

    epollFd = epoll_create1(0);
    if (epollFd < 0) {
        std::cout << "Failed to create epoll file descriptor" << std::endl;
        return;
    }
}

void UDPClients::addClient(sockaddr_in clientAddr) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cout << "Failed to create client socket" << std::endl;
        return;
    }

    int bindRes = bind(sock, (sockaddr*)&clientAddr, sizeof(clientAddr));
    if (bindRes < 0) {
        std::cout << "Failed to bind client socket to IP address" << std::endl;
        return;
    }

    epoll_event event;

    event.events = EPOLLIN;
    event.data.fd = sock;

    int ctlRes = epoll_ctl(epollFd, EPOLL_CTL_ADD, sock, &event);
    if (ctlRes < 0) {
        std::cout << "Failed to add client socket to epoll, error: " << std::strerror(errno) << std::endl;
        return;
    }

    clientSockets[clientAddr.sin_addr.s_addr] = sock;
}

bool UDPClients::hasClient(const in_addr_t clientAddr) const {
    return clientSockets.contains(clientAddr);
}

void UDPClients::waitAndRecieveData() const {
    const size_t maxEvents = clientSockets.size();
    std::vector<epoll_event> events(maxEvents);

    int numReady = epoll_wait(epollFd, events.data(), maxEvents, 100);
    if (numReady < 0) {
        std::cout << "Failed to wait for events on epoll instance, error: " << std::strerror(errno) << std::endl;
        return;
    }

    for (int i = 0; i < numReady; i++) {
        int sock = events[i].data.fd;

        receiveDataOnSocket(sock);
    }
}

void UDPClients::sendData() const {
    for (const auto& [addr, sock] : clientSockets) {
        sendDataOnSocket(sock);
    }
}

void UDPClients::receiveDataOnSocket(int clientSocket) const {
    const size_t readBufferSize = bytesPerSecond;
    char readBuffer[readBufferSize];

    socklen_t addrSize = sizeof(sockaddr_in);

    auto bytesReceived = recvfrom(clientSocket, readBuffer, readBufferSize, MSG_NOSIGNAL, (sockaddr*)&serverAddr, &addrSize);
    if (bytesReceived < 0) {
        std::cout << "Failed to read data on socket " << clientSocket << std::endl;
        return;
    }
}

void UDPClients::sendDataOnSocket(int clientSocket) const {
    ssize_t totalBytesToSend = bytesPerSecond;

    while (totalBytesToSend > 0) {
        size_t writeSize = (totalBytesToSend > writeBufferSize ? writeBufferSize : totalBytesToSend);

        auto bytesSent = sendto(clientSocket, writeBuffer.data(), writeSize, MSG_NOSIGNAL, (sockaddr*)&serverAddr, sizeof(sockaddr_in));
        if (bytesSent < 0) {
            std::cout << "Failed to send data to server" << std::endl;
            return;
        }

        totalBytesToSend -= bytesSent;
    }
}

UDPClients::~UDPClients() {
    close(epollFd);

    for (const auto& [addr, sock] : clientSockets) {
        close(sock);
    }
}
