#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->last = 0;
}

PhoneBook::PhoneBook(const PhoneBook &p) {
    this->last = p.last;
    for (int i = 0; i < 8; i++)
        this->contacts[i] = p.contacts[i];
};

PhoneBook::~PhoneBook() {};

PhoneBook & PhoneBook::operator = (const PhoneBook &p) {
    this->last = p.last;
    for (int i = 0; i < 8; i++)
        this->contacts[i] = p.contacts[i];
    return *this;
}

void    PhoneBook::add() {
    std::cout << "First name : ";
    std::string firstName;
    std::cin >> firstName;

    std::cout << "Last name : ";
    std::string lastName;
    std::cin >> lastName;

    std::cout << "Nick name : ";
    std::string nickName;
    std::cin >> nickName;

    std::cout << "Phone : ";
    std::string phone;
    std::cin >> phone;

    std::cout << "Secret : ";
    std::string secret;
    std::cin >> secret;

    this->contacts[this->last++] = Contact(firstName, lastName, nickName, phone, secret);
    if (this->last == 8) { this->last = 0; }
}

static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    PhoneBook::print() {
    for (int i = 0; i < 8; i++) {
        std::cout << std::left << std::setw(10) << i;
        std::cout << '|';
        std::cout << std::left << std::setw(10) << truncate(this->contacts[i].firstName);
        std::cout << '|';
        std::cout << std::left << std::setw(10) << truncate(this->contacts[i].lastName);
        std::cout << '|';
        std::cout << std::left << std::setw(10) << truncate(this->contacts[i].nickName);
        std::cout << std::endl;
    }
}

void    PhoneBook::search() {
    this->print();

    int index;
    std::cout << "Please enter the index of the contact you want more detail : ";
    if (!(std::cin >> index) || index < 0 || index >= 8) {
        std::cout << "Wrong index" << std::endl;
        std::cin.clear();
		std::cin.ignore();
        return;
    }

    std::cout << std::left  << std::setw(10) << "index";
    std::cout << " : " << index << std::endl;
    std::cout << std::left  << std::setw(10) << "firstName";
    std::cout << " : " << this->contacts[index].firstName << std::endl;
    std::cout << std::left  << std::setw(10) << "lastName";
    std::cout << " : " << this->contacts[index].lastName << std::endl;
    std::cout << std::left  << std::setw(10) << "nickName";
    std::cout << " : " << this->contacts[index].nickName << std::endl;
    std::cout << std::left  << std::setw(10) << "phone";
    std::cout << " : " << this->contacts[index].phone << std::endl;
    std::cout << std::left  << std::setw(10) << "secret";
    std::cout << " : " << this->contacts[index].secret << std::endl;
}