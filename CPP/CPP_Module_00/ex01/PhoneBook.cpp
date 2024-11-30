
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _number = 0;
    std::cout << "seokchoi" << std::endl;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::_introducePhoneBook()
{
    std::cout << std::endl;
    std::cout << "♥♡------------EJ's-PHONEBOOK-----------♡♥" << std::endl;
    std::cout << "♥♡------*------------------------------♡♥" << std::endl;
    std::cout << "♥♡--☺☺--*-ADD--------------------------♡♥" << std::endl;
    std::cout << "♥♡------*----add-your-number-----------♡♥" << std::endl;
    std::cout << "♥♡------*-SEARCH-----------------------♡♥" << std::endl;
    std::cout << "♥♡------*----search-others-number------♡♥" << std::endl;
    std::cout << "♥♡------*-EXIT-------------------------♡♥" << std::endl;
    std::cout << "♥♡------*----exit-from-phonebook-------♡♥" << std::endl;
    std::cout << "♥♡------*------------------------------♡♥" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void PhoneBook::openPhoneBook()
{
    std::string line;
    while (1)
    {
        _introducePhoneBook();
        std::cout << "Type Command : ";
        line = getInput();
        if (line == "ADD")
            _add();
        else if (line == "SEARCH")
            _search();
        else if (line == "EXIT")
            std::exit(0);
        else
            std::cout << "Wrong Input" << std::endl;
    }
}

std::string PhoneBook::getInput()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.fail())
    {
        std::cout << std::endl
                  << "Error occurred during input." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    else if (line.length() == 0)
        return ("");
    return (line);
}

void PhoneBook::_add()
{
    std::string fristname, lastname, nickname, phonenumber, darkestsecret;
    std::string inputInfo[5] = {"first name", "last name", "nickname", "phone number", "darkestsecret"};
    std::string input[5];
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter " << inputInfo[i] << " : " << std::endl;
        input[i] = getInput();
        if (input[i].length() == 0)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }
    _contacts[_number].setFirstName(input[0]);
    _contacts[_number].setLastName(input[1]);
    _contacts[_number].setNickname(input[2]);
    _contacts[_number].setPhoneNumber(input[3]);
    _contacts[_number].setDarkestSecret(input[4]);
    _number++;
    if (_number == 8)
        _number = 0;
    return;
}

void checkLengthAndPrint(std::string info)
{
    if (info.length() > 10)
    {
        std::string subStr = info.substr(0, 9);
        std::cout << "|" << subStr << ".";
    }
    else
        std::cout << "|" << std::setw(10) << info;
}

void PhoneBook::_search()
{
    int index = -1;
    std::string strNum;

    std::cout << "|" << std::setw(10) << "index";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname"
              << "|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|" << std::setw(10) << i;
        checkLengthAndPrint(_contacts[i].getFirstName());
        checkLengthAndPrint(_contacts[i].getLastName());
        checkLengthAndPrint(_contacts[i].getNickname());
        std::cout << "|" << std::endl;
    }

    std::cout << "Enter Index : ";
    strNum = getInput();
    std::istringstream toIndex(strNum);
    toIndex >> index;
    if (!toIndex.eof() || index > 7 || index < 0)
    {
        std::cout << "Invalid Index." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "first name" << std::setw(6) << ": " << _contacts[index].getFirstName() << std::endl;
    std::cout << "last name" << std::setw(7) << ": " << _contacts[index].getLastName() << std::endl;
    std::cout << "nickname" << std::setw(8) << ": " << _contacts[index].getNickname() << std::endl;
    std::cout << "phone number" << std::setw(4) << ": " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "darkest secret"
              << ": " << _contacts[index].getDarkestSecret() << std::endl;

    return;
}
