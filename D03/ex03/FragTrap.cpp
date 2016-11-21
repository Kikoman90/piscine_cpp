#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
        std::srand(std::time(NULL));
    log();
    std::cout << name << " appears" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    log();
    std::cout << name << " has duplicated" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void)
{
    log();
    std::cout << name << " disappears" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    if (this !=&rhs)
    {
        log();
        std::cout << this->name << " copies the characteristics of " << rhs.name << std::endl;
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

void    FragTrap::makeJoke(std::string const &target)
{
    log();
    std::cout << this->name << " says: Times like these, I really start to question the meaning of my existence. Then I get distra-hey! What's this? This looks cool! at " << target << std::endl;
}

void    FragTrap::makeSpin(std::string const &target)
{
    log();
    std::cout << this->name << " does a really cool spin in front of " << target << std::endl;
}

void    FragTrap::makeOffensiveGesture(std::string const &target)
{
    log();
    std::cout << this->name << " makes an offensive gesture at " << target << std::endl;
}

void    FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (this->energyPoints >= 25)
    {
        int i = rand() % 7;

        if ((i == 0 || i == 1) && (this->energyPoints -= 25))
            makeJoke(target);
        else if((i == 2 || i == 3) && (this->energyPoints -= 25))
            makeOffensiveGesture(target);
        else if (i == 4 && (this->energyPoints -= 25))
            makeSpin(target);
        else if (i == 5 && (this->energyPoints -= 15))
            meleeAttack(target);
        else
        {
            this->energyPoints -= 15;
            rangedAttack(target);
        }
    }
    else
    {
        log();
        std::cout << "Not enough energy" << std::endl;
    }
}