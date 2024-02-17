#include <iostream>
#include <chrono>
#include <thread>

#include "ArgsParser.h"
#include "ClientsReader.h"
#include "UDPClients.h"


int main(int argc, const char** argv) {
    ArgsParser argsParser(argc, argv);
    auto [clientsIPfile, bandwidth, echoServerAddr] = argsParser.parse();

    ClientsReader clientsReader(clientsIPfile);

    UDPClients udpClients(bandwidth, echoServerAddr);
    

    auto periodEnd = std::chrono::system_clock::now();

    while (true) {
        periodEnd += std::chrono::seconds(1);

        clientsReader.read(udpClients);

        udpClients.sendData();

        udpClients.waitAndRecieveData();

        std::this_thread::sleep_until(periodEnd);
    }

    return 0;
}
