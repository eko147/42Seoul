#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"
#include <sstream>
#include <iomanip>

class PhoneBook
{
private:
    Contact _contacts[8];
    void _add();
    void _search();
    int _number;
    std::string getInput();
    void _introducePhoneBook();

public:
    PhoneBook();
    ~PhoneBook();

    void openPhoneBook();
};

#endif