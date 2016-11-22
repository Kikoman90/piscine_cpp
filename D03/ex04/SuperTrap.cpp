/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:57:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:59:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
    std::srand(std::time(NULL));
    log();
    std::cout << name << ": 'I'm the best claptrap. yeeeee!'" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src), FragTrap(src), NinjaTrap(src)
{
    log();
    std::cout << name << " has duplicated" << std::endl;
    *this = src;
}

SuperTrap::~SuperTrap(void)
{
    log();
    std::cout << name << ": 'See you losers hahahaha!'" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs)
{
    if (this != &rhs)
    {
        log();
        this->name = rhs.getName();
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