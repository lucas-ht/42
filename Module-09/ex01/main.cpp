#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Wrong number of argument" << std::endl;
        return 1;
    }

    RPN rpn;

    try {
        rpn.parse(av[1]);
        rpn.calculate();
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
