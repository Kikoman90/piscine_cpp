/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:00:50 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 20:00:51 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
    FragTrap    FragTrap("FragTrap");
    ScavTrap    ScavT("ScavTrap");
    ScavTrap    ScavTrap2(ScavT);
    NinjaTrap   Ninj("Ninja");
    SuperTrap   Sup("LameLmao");

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

    Ninj.beRepaired(20);
    Ninj.meleeAttack("Bullymong");
    Ninj.rangedAttack("Bullymong");
    Ninj.takeDamage(30);
    Ninj.ninjaShoebox(FragTrap);
    Ninj.ninjaShoebox(ScavT);
    Ninj.ninjaShoebox(Ninj);
    Ninj.beRepaired(20);

    Sup.beRepaired(20);
    Sup.meleeAttack("Bullymong");
    Sup.rangedAttack("Bullymong");
    Sup.takeDamage(30);
    Sup.ninjaShoebox(FragTrap);
    Sup.ninjaShoebox(ScavT);
    Sup.ninjaShoebox(Ninj);
    Sup.beRepaired(20);
    Sup.vaulthunter_dot_exe("Bullymong");
    Sup.vaulthunter_dot_exe("Bullymong");
    Sup.vaulthunter_dot_exe("Bullymong");
    Sup.vaulthunter_dot_exe("Bullymong");
}
