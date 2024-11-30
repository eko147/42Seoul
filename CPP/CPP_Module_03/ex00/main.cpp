#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("apple");

    clapTrap.attack("banana");
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    clapTrap.takeDamage(9);
    clapTrap.attack("42");

    return 0;
}