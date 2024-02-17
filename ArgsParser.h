#include <netinet/in.h>


class ArgsParser {
    using Args = std::tuple<std::string, ssize_t, sockaddr_in>;

public:
    ArgsParser(int argc, const char **argv);

    Args parse() const;

private:
    int argc;
    const char **argv;
};