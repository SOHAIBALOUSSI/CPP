#include "Harl.hpp"

e_Level parseLogLevel(std::string logLevel)
{
    if (logLevel == "ERROR" || logLevel == "WARNING"
        || logLevel == "INFO" || logLevel == "DEBUG") {
        return (Harl::convertLeveltoEnum(logLevel));
    }
    return UNKNOWN;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << USAGE_ERR;
        return 1;
    }
    Harl obj;
    obj.complain(parseLogLevel(av[1]));
    return 0;
}