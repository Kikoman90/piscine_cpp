/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:53:14 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:53:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap    FragTrap("FragTrap");
    ScavTrap    ScavT("ScavTrap");
    ScavTrap    ScavTrap2(ScavT);

    FragTrap.beRepaired(20);
    FragTrap.meleeAttack("Bullymong");
    FragTrap.rangedAttack("Bullymong");
    FragTrap.takeDamage(30);
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.beRepaired(20);


    ScavT.beRepaired(20);
    ScavT.meleeAttack("Bullymong");
    ScavT.rangedAttack("Bullymong");
    ScavT.takeDamage(30);
    ScavT.challengeNewcomer("Bullymong");
    ScavT.challengeNewcomer("Bullymong");
    ScavT.challengeNewcomer("Bullymong");
    ScavT.beRepaired(20);
}
