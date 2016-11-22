/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:57:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:59:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 60;
    this->maxHitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->armorDamageReduction = 0;
    std::srand(std::time(NULL));
    log();
    std::cout << name << " appears out of nowhere: 'Yaaaaaa!'" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
    log();
    std::cout << name << " has duplicated" << std::endl;
    *this = src;
}

NinjaTrap::~NinjaTrap(void)
{
    log();
    std::cout << name << " vanishes in a cloud of smoke" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
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

void    NinjaTrap::ninjaShoebox(const NinjaTrap &ninja) const
{
    log();
    std::cout << "Yaaaaaa Ninja!" << std::endl;
    ninja.getName();
}

void    NinjaTrap::ninjaShoebox(const ScavTrap &scav) const
{
    log();
    std::cout << "We will never be scaves! i mean... slaves" << std::endl;
    scav.getName();
}

void    NinjaTrap::ninjaShoebox(const FragTrap &frag) const
{
    log();
    std::cout << "fraggedy frag i'm the fragtrap!" << std::endl;
    frag.getName();
}

void    NinjaTrap::ninjaShoebox(const ClapTrap &clap) const
{
    log();
    std::cout << "*clap clap clap* wait how do i even clap with my tiny robotic arms?" << std::endl;
    clap.getName();
}
