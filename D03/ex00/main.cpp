/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:51:41 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/19 17:51:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap    ClapTrap("ClapTrap");

    ClapTrap.beRepaired(20);
    ClapTrap.meleeAttack("Bullymong");
    ClapTrap.rangedAttack("Bullymong");
    ClapTrap.takeDamage(30);
    ClapTrap.vaulthunter_dot_exe("Bullymong");
    ClapTrap.vaulthunter_dot_exe("Bullymong");
    ClapTrap.vaulthunter_dot_exe("Bullymong");
    ClapTrap.vaulthunter_dot_exe("Bullymong");
    ClapTrap.beRepaired(20);
}
