#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : name(name), hitPoints(100),
    maxHitPoints(100), energyPoints(50), maxEnergyPoints(50), level(1),
    meleeAttackDamage(20), rangedAttackDamage(15), armorDamageReduction(3)
{
        std::srand(std::time(NULL));
    log();
    std::cout << name << " cry: I'm here!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    log();
    std::cout << name << " has duplicated" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap(void)
{
    log();
    std::cout << name << " cry: I leave!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    if (this !=&rhs)
    {
        log();
        std::cout << this->name << " have same characteristics of " << rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->maxHitPoints = rhs.maxHitPoints;
        this->energyPoints = rhs.energyPoints;
        this->maxEnergyPoints = rhs.maxEnergyPoints;
        this->level = rhs.level;
        this->meleeAttackDamage = rhs.meleeAttackDamage;
        this->rangedAttackDamage = rhs.rangedAttackDamage;
        this->armorDamageReduction = rhs.armorDamageReduction;
    }
    return (*this);
}

void    ScavTrap::log() const
{
    std::cout << "[FR4G-TP] ";
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints + this->armorDamageReduction - amount > 0
        && this->armorDamageReduction < amount)
        {
            log();
            std::cout << this->name << " has taken " << amount << " damage" << std::endl;
            this->hitPoints -= amount - armorDamageReduction;
        }
    else if (this->hitPoints + this->armorDamageReduction <= amount)
    {
        std::cout << this->name << " has taken too much damage" << std::endl;
        this->~ScavTrap();
    }
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    log();
    if (this->hitPoints + amount > this->maxHitPoints)
    {
        std::cout << this->name << " is full health" << std::endl;
        this->hitPoints = this->maxHitPoints;
    }
    else
    {
        std::cout << this->name << " has been repaired by " << amount << std::endl;
        this->hitPoints += amount;
    }
    log();
    if (this->energyPoints + amount > this->maxEnergyPoints)
    {
        std::cout << this->name << " is full energy" << std::endl;
        this->energyPoints = this->maxEnergyPoints;
    }
    else
    {
        std::cout << this->name << " recovers " << amount << " energy" << std::endl;
        this->energyPoints += amount;
    }
}

void    ScavTrap::rangedAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage << " points of damage !" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage << " points of damage !" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
}

void    ScavTrap::challengeNewcomer(std::string const &target)
{
    int i = rand() % 3;
    
    log();
    if (i == 0)
        std::cout << this->name << " challenges " << target << " to stand on a foot or on a wheel for as long as it can." << std::endl;
    else if (i == 1)
        std::cout << this->name << " challenges " << target << " to piss farther than him." << std::endl;
    else if (i == 2)
        std::cout << this->name << " challenges " << target << " to do the moonwalk better than him." << std::endl;
}