#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType()
{
    const std::string &typeref = _type;
    return (typeref);
}
void Weapon::setType(std::string str)
{
    _type = str;
}