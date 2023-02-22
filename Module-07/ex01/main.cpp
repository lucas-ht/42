#include <iostream>
#include <string>

#include "iter.hpp"

void    f_int(int& i) {
    i++;
}

void    f_str(std::string& s) {
    s = s.append(" f_str !");
}

int main() {
    int a[6] = { 1, 2, 6, 3, 42, -10 };

    ::iter(a, 4, print<int>);
    std::cout << std::endl;

    ::iter(a, 4, f_int);
    ::iter(a, 4, print<int>);


    std::string b[3] = { "hello", "World", "wow", };

    ::iter(b, 3, print<std::string>);
    std::cout << std::endl;

    ::iter(b, 3, f_str);
    ::iter(b, 3, print<std::string>);
}