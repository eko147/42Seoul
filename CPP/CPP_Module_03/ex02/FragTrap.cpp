#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _name = "FragTrap";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
    *this = obj;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " has already died" << std::endl;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy to high-five!" << std::endl;
    }
    else
    {
        _energyPoints--;
        std::cout << "FragTrap " << _name << " says : make some high-five!" << std::endl;
    }
}