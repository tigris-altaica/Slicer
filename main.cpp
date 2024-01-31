#include <iostream>

#include "ArgsParser.h"
#include "ClientsReader.h"
#include "UDPClient.h"


int main(int argc, const char** argv) {
    ArgsParser ap(argc, argv);
    if (ap.parse() != 0) {
        return -1;
    }


    ClientsReader cr(ap.getClientsIPfile());
    //UDPClient udpc(ap.getBandwidth());

    while (true) {
        cr.read();
        //udpc.receiveData();
    }

    return 0;
}
