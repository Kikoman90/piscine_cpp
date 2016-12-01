/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:44:00 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:41:21 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    std::cout << "_constructor_" << std::endl;
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISpaceMarine* bob_clone = bob->clone();
    ISpaceMarine* null = NULL;

    ISquad* vlc = new Squad;

    std::cout << "_pushing units_" << std::endl;
    std::cout << "_nb of units: " << vlc->push(bob) << std::endl;
    std::cout << "_nb of units: " << vlc->push(jim) << std::endl;
    vlc->push(bob_clone);
    
    std::cout << "_nb of units:" << vlc->getCount() << std::endl;
    std::cout << "_pushing null or already existing units_" << std::endl;
    vlc->push(bob);
    vlc->push(null);
    std::cout << "_nb of units:" << vlc->getCount() << std::endl;
    std::cout << "_calling units_" << std::endl;
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    std::cout << "_delete/destructor_" << std::endl;
    delete vlc;

    return 0;
}
