#pragma once
#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
    int         last;
    Contact     contacts[8];
    void        print();

public:
    PhoneBook();
    PhoneBook(const PhoneBook &);

    ~PhoneBook();
    PhoneBook & operator = (const PhoneBook &);

    void        add();
    void        search();
};

#endif