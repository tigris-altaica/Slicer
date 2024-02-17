#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "UDPClient.h"

UDPClient::UDPClient(size_t bandwidth, sockaddr_in serverAddr)
    : bandwidth(bandwidth),
      serverAddr(serverAddr),
      dataBuffer(bandwidth, 'A')
{
    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        std::cout << "Failed to create epoll file descriptor" << std::endl;
        return;
    }
}

int UDPClient::addClient(sockaddr_in clientAddr) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cout << "Failed to create client socket" << std::endl;
        return -1;
    }

    int bindRes = bind(sock, (sockaddr *)&clientAddr, sizeof(clientAddr));
    if (bindRes < 0) {
        std::cout << "Failed to bind client socket to IP address" << std::endl;
        return -1;
    }

    epoll_event event;

    event.events = EPOLLIN;
    event.data.fd = sock;

    int ctlRes = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock, &event);
    if (ctlRes < 0) {
        std::cout << "Failed to add client socket to epoll, error " << errno << std::endl;
        return -1;
    }

    return sock;
}

void UDPClient::receiveData() {
    int numReady = epoll_wait(epoll_fd, events, maxClients, 100);
    if (numReady < 0) {
        std::cout << "Failed to wait for events on epoll instance, error " << errno << std::endl;
        return;
    }

    for (int i = 0; i < numReady; i++) {
        const size_t readSize = bandwidth;
        char readBuffer[bandwidth];

        size_t bytesRead = read(events[i].data.fd, readBuffer, readSize);
        if (bytesRead < 0) {
            std::cout << "Failed to read data on socket " << events[i].data.fd << std::endl;
            continue;
        }

        std::cout << "Received " << bytesRead << " bytes on socket " << events[i].data.fd << std::endl;

        sendData(events[i].data.fd);
    }
}

void UDPClient::sendData(int clientSocket) {
    int sendRes = sendto(clientSocket, dataBuffer.data(), bandwidth, MSG_NOSIGNAL, (sockaddr *)&serverAddr, sizeof(sockaddr_in));
    if (sendRes < 0) {
        std::cout << "Failed to send data to server" << std::endl;
        return;
    }
}

UDPClient::~UDPClient() {
    close(epoll_fd);
}
