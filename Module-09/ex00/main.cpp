#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Wrong number of argument" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.parseInput(av[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
