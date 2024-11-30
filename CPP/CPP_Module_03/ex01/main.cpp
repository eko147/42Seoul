
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("apple");
    ScavTrap ScavTrap("pineapple");

    std::cout << std::endl;
    clapTrap.attack("banana");
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    clapTrap.takeDamage(9);
    std::cout << std::endl;
    ScavTrap.attack("banana");
    ScavTrap.guardGate();
    ScavTrap.attack("banana");
    ScavTrap.takeDamage(100);
    ScavTrap.beRepaired(2);
    std::cout << std::endl;
    return 0;
}
