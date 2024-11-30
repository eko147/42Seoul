#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &humanWeapon) : _name(name), _weapon(humanWeapon) {}

HumanA::~HumanA() {}
