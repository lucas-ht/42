#pragma once
#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>

class Contact {
public:
    std::string     firstName;
    std::string     lastName;
    std::string     nickName;
    std::string     phone;
    std::string     secret;

    Contact();
    Contact(std::string, std::string, std::string, std::string, std::string);
    Contact(const Contact &);

    ~Contact();
    Contact & operator = (const Contact &);
};

#endif