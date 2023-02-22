#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main() {
    std::vector<int>            v;
    std::vector<int>::iterator  it;

    for (int i = 0; i < 50; i++)
        v.push_back(i);

    try {
        int target = 42;
        it = easyfind(v, target);
        std::cout << "Found " << target << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        int target = 180;
        it = easyfind(v, target);
        std::cout << "Found " << target << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}