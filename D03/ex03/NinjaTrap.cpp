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

void    NinjaTrap::ninjaShoebox(std::string const &target)
{
    int i = rand() % 3;
    
    log();
    if (i == 0)
        std::cout << this->name << " challenges " << target << " to stand on a foot or on a wheel for as long as it can" << std::endl;
    else if (i == 1)
        std::cout << this->name << " challenges " << target << " to piss farther than him" << std::endl;
    else if (i == 2)
        std::cout << this->name << " challenges " << target << " to do the moonwalk better than him" << std::endl;
}
