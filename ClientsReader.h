#include <string>
#include <unordered_set>
#include <arpa/inet.h>

#include "UDPClient.h"


class ClientsReader {
public:
    ClientsReader(const std::string& fn);

    void read(UDPClient& ClientsReader);

private:
    const std::string filename;
    std::unordered_set<in_addr_t> clients;
};          