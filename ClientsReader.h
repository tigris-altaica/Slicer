#include <string>

#include "UDPClients.h"


class ClientsReader {
public:
    ClientsReader(const std::string& filename);

    void read(UDPClients& ClientsReader) const;

private:
    const std::string filename;
};          