/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:50:21 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:50:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap    FragTrap("FragTrap");
    ScavTrap    ScavTrap("ScavTrap");

    FragTrap.beRepaired(20);
    FragTrap.meleeAttack("Bullymong");
    FragTrap.rangedAttack("Bullymong");
    FragTrap.takeDamage(30);
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.beRepaired(20);

    ScavTrap.beRepaired(20);
    ScavTrap.meleeAttack("Bullymong");
    ScavTrap.rangedAttack("Bullymong");
    ScavTrap.takeDamage(30);
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.beRepaired(20);
}
