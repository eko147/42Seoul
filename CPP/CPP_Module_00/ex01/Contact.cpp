
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string firstName)
{
    _first_name = firstName;
}
void Contact::setLastName(std::string lastName)
{
    _last_name = lastName;
}
void Contact::setNickname(std::string nickName)
{
    _nick_name = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
    _phone_number = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSectret)
{
    _darkest_secret = darkestSectret;
}

std::string Contact::getFirstName()
{
    return _first_name;
}
std::string Contact::getLastName()
{
    return _last_name;
}
std::string Contact::getNickname()
{
    return _nick_name;
}
std::string Contact::getPhoneNumber()
{
    return _phone_number;
}
std::string Contact::getDarkestSecret()
{
    return _darkest_secret;
}