#include "BitcoinExchange.hpp"


int main(int ac, char **av) {

    BitcoinExchange btc;
    try {
        btc.loadBtcData();
        btc.loadInputFile((ac == 2) ? av[1] : NULL);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}