#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &obj);
    ScavTrap &operator=(const ScavTrap &obj);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif
