/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:44:00 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/15 17:53:28 by fsidler          ###   ########.fr       */
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

    std::cout << std::endl << "_pushing units_" << std::endl;
    std::cout << "_nb of units: " << vlc->push(bob) << std::endl;
    std::cout << "_nb of units: " << vlc->push(jim) << std::endl;
    std::cout << "_nb of units: " << vlc->push(bob_clone) << std::endl;
    
    std::cout << std::endl << "_pushing null or already existing units_" << std::endl;
    vlc->push(bob);
    std::cout << "_nb of units: " << vlc->push(null) << std::endl;
    std::cout << std::endl << "_calling units_" << std::endl;
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    std::cout << std::endl << "_delete/destructor_" << std::endl;
    delete vlc;

    std::cout << std::endl << "_deep copy with the operator overload and copy construction_" << std::endl;
    ISpaceMarine* bub = new TacticalMarine;
    ISpaceMarine* jom = new AssaultTerminator;
    Squad squadFirst = Squad();
    std::cout << "_pushing units_" << std::endl;
    std::cout << "_nb of units in 1st squad: " << squadFirst.push(bub) << std::endl;
    std::cout << "_nb of units in 1st squad: " << squadFirst.push(jom) << std::endl;
    std::cout << "_copy construction_" << std::endl;
    Squad squadSecond = Squad(squadFirst);
    std::cout << "_nb of units in 2nd squad: " << squadSecond.getCount() << std::endl;
    std::cout << "_operator overload_" << std::endl;
    Squad squadThird = Squad();
    squadThird = squadFirst;
    std::cout << "_nb of units in 3rd squad: " << squadThird.getCount() << std::endl;

    return 0;
}
