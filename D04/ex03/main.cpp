/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:47 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:43:28 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    std::cout << "_learning materials_" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "_creating character_" << std::endl;
    ICharacter* zaz = new Character("zaz");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    zaz->equip(tmp);
    tmp = src->createMateria("cure");
    zaz->equip(tmp);
    std::cout << "_unequip material at wrong index_" << std::endl;
    zaz->equip(tmp);
    tmp = src->createMateria("ice");
    zaz->equip(tmp);
    std::cout << "_trying to equip in a full inventory_" << std::endl;
    zaz->equip(tmp);
    zaz->unequip(10);

    ICharacter* bob = new Character("bob");

    std::cout << "XP of inv[1]: " << tmp->getXP() << std::endl;
    zaz->use(0, *bob);
    std::cout << "_use inv[1]_" << std::endl;
    zaz->use(1, *bob);
    std::cout << "XP of inv[1]: " << tmp->getXP() << std::endl;
    std::cout << "_unequiping inv[1]_" << std::endl;
    zaz->unequip(1);

    std::cout << "_using unexisting material_" << std::endl;
    zaz->use(1, *bob);
    std::cout << "_calling use() with wrong index_" << std::endl;
    zaz->use(4, *bob);
    
    delete bob;
    delete zaz;
    delete src;
    
    return 0; 
}