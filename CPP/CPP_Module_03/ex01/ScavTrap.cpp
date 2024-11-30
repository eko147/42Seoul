#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    _name = "ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    *this = obj;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_hitPoints == 0)
        std::cout << "ScavTrap " << _name << " has already died." << std::endl;
    else if (_energyPoints == 0)
        std::cout << "ScavTrap " << _name << " has no energy to guard." << std::endl;
    else
    {
        std::cout << "ScavTrap " << _name << " has entered Gate keeper mode." << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has already died." << std::endl;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}
