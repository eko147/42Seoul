#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << _name << " is created" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}
