#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap"), _hitPoints(10), _energyPoints(10),_attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    _name = name;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has already died" << std::endl;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int attackAmount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has already died" << std::endl;
    }
    else if (_hitPoints <= attackAmount)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has died." << std::endl;
    }
    else
    {
        _hitPoints -= attackAmount;
        std::cout << _name << " is taking " << attackAmount << " damage." << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int repairAmount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has already died" << std::endl;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
    }
    else
    {
        _hitPoints += repairAmount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired " << repairAmount
                  << " hit points. Remaining hit points: " << _hitPoints << std::endl;
    }
}
