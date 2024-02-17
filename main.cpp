#include <iostream>
#include <chrono>
#include <thread>

#include "ArgsParser.h"
#include "ClientsReader.h"
#include "UDPClient.h"


int main(int argc, const char** argv) {
    ArgsParser ap(argc, argv);
    if (ap.parse() != 0) {
        return -1;
    }

    ClientsReader cr(ap.getClientsIPfile());
    UDPClient udpc(ap.getBandwidth(), ap.getEchoServer());

    while (true) {
        cr.read(udpc);

        udpc.receiveData();

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

    return 0;
}
