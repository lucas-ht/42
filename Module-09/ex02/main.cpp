#include "PmergeMe.hpp"



int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Wrong number of argument" << std::endl;
        return 1;
    }

    PmergeMe    pmergeMe;

    try {
        pmergeMe.parse(ac, av);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::chrono::steady_clock::time_point   begin;
    std::chrono::steady_clock::time_point   end;
    std::chrono::nanoseconds                elapsed;

    std::cout << "Before: ";
    pmergeMe.print();

    begin = std::chrono::steady_clock::now();

    pmergeMe.vectorSort();

    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << "After: ";
    pmergeMe.print();

    std::cout << "Time to process a range of " << ac - 1 <<" elements with std::vector: ";
    std::cout << static_cast<double>(elapsed.count()) / 100 << " µs" << std::endl;


    begin = std::chrono::steady_clock::now();

    pmergeMe.dequeSort();

    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time to process a range of " << ac - 1 <<" elements with std::deque: ";
    std::cout << static_cast<double>(elapsed.count()) / 100 << " µs" << std::endl;

    return 0;
}
