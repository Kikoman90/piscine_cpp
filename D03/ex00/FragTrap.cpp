/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:51:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/19 17:51:25 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : name(name), hitPoints(100),
    maxHitPoints(100), energyPoints(100), maxEnergyPoints(100), level(1),
    meleeAttackDamage(30), rangedAttackDamage(20), armorDamageReduction(5)
{
        std::srand(std::time(NULL));
    log();
    std::cout << name << " appears" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
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
        std::cout << this->name << " copies the characteristics of " << rhs.name;
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

void    FragTrap::log() const
{
    std::cout << "[FR4G-TP] ";
}

void    FragTrap::takeDamage(unsigned int amount)
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
        this->~FragTrap();
    }
}

void    FragTrap::beRepaired(unsigned int amount)
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

void    FragTrap::rangedAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " uses ranged attack on " << target << " causing " << this->rangedAttackDamage << " damage" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
}

void    FragTrap::meleeAttack(std::string const & target)
{
    log();
    if (this->energyPoints > 10 && (this->energyPoints -= 10))
        std::cout << this->name << " uses melee attack on " << target << " causing " << this->meleeAttackDamage << " damage" << std::endl;
    else
        std::cout << "Not enough energy" << std::endl;
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
