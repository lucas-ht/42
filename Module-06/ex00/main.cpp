#include "Converter.hpp"

int main(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        try {
            Converter   c(av[i]);
            c.print();
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}