#include <unistd.h>  
#include <iostream>
#include <sys/socket.h> 
#include <arpa/inet.h>

#include "UDPClient.h"


UDPClient::UDPClient(size_t bandwidth) : bandwidth(bandwidth) {
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
		std::cout << "Failed to create epoll file descriptor" << std::endl;
        return;
	}
}

void UDPClient::addClient(sockaddr_in clientAddr) {
    int s = socket(AF_INET, SOCK_DGRAM, 0);  
	if (s < 0) {
		std::cout << "Failed to create client socket" << std::endl;
        return;
    }

    if (bind(s, (sockaddr*)&clientAddr, sizeof(clientAddr)) < 0)  {
		std::cout << "Failed to bind client socket to IP address" << std::endl;
        return;
    }

    epoll_event event;

    event.events = EPOLLIN;
	event.data.fd = s;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event) != 0) {
		std::cout << "Failed to add client socket to epoll" << std::endl;
		return;
	}
}

void UDPClient::receiveData() {
    int readyCount = epoll_wait(epoll_fd, events, maxEvents, 100);
		
    for (int i = 0; i < readyCount; i++) {
        const size_t readSize = 1024;
	    char readBuffer[readSize];

        size_t bytesRead = read(events[i].data.fd, readBuffer, readSize);

        sendData(events[i].data.fd, readBuffer, bytesRead);
    }
}

void UDPClient::sendData(int clientSocket, char buffer[], size_t size) {

}
