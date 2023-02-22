#include <iostream>
#include "Span.hpp"

int main() {

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    Span sp2 = Span(100000);

    std::srand(std::time(nullptr));

    for (int i = 0; i < 100000; i++)
        sp2.addNumber(std::rand());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    try {
        sp2.addNumber(std::rand());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}