/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:23:13 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:23:42 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
    Character* zaz = new Character("zaz");

    std::cout << *zaz;

    Enemy* b = new RadScorpion();
    Enemy* b2 = new SuperMutant();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    zaz->equip(pf);
    std::cout << *zaz;

    zaz->attack(b2);
    std::cout << *zaz;
    zaz->attack(b2);
    zaz->attack(b2);
    std::cout << *zaz;
    zaz->equip(pr);
    zaz->recoverAP();
    std::cout << *zaz;
    zaz->recoverAP();
    zaz->equip(pf);
    zaz->recoverAP();
    std::cout << *zaz;
    zaz->recoverAP();
    std::cout << *zaz;

    zaz->attack(b2);
    zaz->attack(b2);

	delete pr;
	delete pf;
	delete zaz;
    return 0;
}
