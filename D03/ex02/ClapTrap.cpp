/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:50:32 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:51:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), level(1)
{
    std::srand(std::time(NULL));
    log();
    std::cout <<"A new ClapTrap comes" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : name(src.name)
{
    log();
    std::cout << name << " has duplicated" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void)
{
    log();
    std::cout << "The ClapTrap leaves" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    if (this !=&rhs)
    {
        log();
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

void    ClapTrap::log() const
{
    std::cout << "[FR4G-TP] ";
}

void    ClapTrap::takeDamage(unsigned int amount)
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
        this->~ClapTrap();
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
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

void    ClapTrap::rangedAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage << " points of damage !" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
}

void    ClapTrap::meleeAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage << " points of damage !" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
}
