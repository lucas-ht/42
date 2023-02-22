#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {
    PhoneBook   myPhoneBook;
    std::string input;
    std::cout << "Welcome back !" << std::endl;
    for (;;) {
        std::cout << std::endl << "What do you want to do ? (ADD, SEARCH, EXIT) : ";
        std::cin >> input;
        if (input == "ADD")     { myPhoneBook.add(); }
        if (input == "SEARCH")  { myPhoneBook.search(); }
        if (input == "EXIT")    { break; }
    }
}
