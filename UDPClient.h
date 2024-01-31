#include <sys/epoll.h>


class UDPClient {
public:
    UDPClient(size_t bandwidth);

    void receiveData();

    void addClient(sockaddr_in clientAddr);

    bool hasClient();

private:
    void sendData(int clientSocket, char buffer[], size_t size);

    static const size_t maxEvents = 10;
    size_t bandwidth;
    int epoll_fd; 
    epoll_event events[maxEvents];
};