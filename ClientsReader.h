#include <string>
#include <unordered_set>
#include <arpa/inet.h>


class ClientsReader {
public:
    ClientsReader(const std::string& fn);

    void read();

private:
    const std::string fileName;
    std::unordered_set<std::string> clients;
};          