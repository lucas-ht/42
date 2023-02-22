#include "Contact.hpp"

Contact::Contact() {
    this->firstName     = "Empty";
    this->lastName      = "Empty";
    this->nickName      = "Empty";
    this->phone         = "Empty";
    this->secret        = "Empty";
};

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret) :
    firstName(firstName), lastName(lastName), nickName(nickName), phone(phone), secret(secret) {};

Contact::Contact(const Contact &c) {
    this->firstName     = c.firstName;
    this->lastName      = c.lastName;
    this->nickName      = c.nickName;
    this->phone         = c.phone;
    this->secret        = c.secret;
};

Contact::~Contact() {};

Contact & Contact::operator = (const Contact &c) {
    this->firstName     = c.firstName;
    this->lastName      = c.lastName;
    this->nickName      = c.nickName;
    this->phone         = c.phone;
    this->secret        = c.secret;
    return *this;
}
