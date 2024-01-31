#include <netinet/in.h>


class ArgsParser
{
public:
    ArgsParser(int argc, const char **argv);

    int parse();

    std::string getClientsIPfile() const;

    size_t getBandwidth() const;

    sockaddr_in getEchoServer() const;

private:
    int argc;
    const char **argv;

    std::string clientsIPfile;
    size_t bandwidth;
    sockaddr_in echoServerAddr;
};