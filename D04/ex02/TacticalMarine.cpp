/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:47 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:43:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src)
{
    *this = src;
}

TacticalMarine::~TacticalMarine(void)
{
    std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine              &TacticalMarine::operator=(TacticalMarine const &rhs)
{
    (void)rhs;
    return (*this);
}

ISpaceMarine                *TacticalMarine::clone(void) const
{
    ISpaceMarine *clone = new TacticalMarine(*this);
    
    return (clone);
}

void                        TacticalMarine::battleCry(void) const
{
    std::cout << "For the holy PLOT !" << std::endl;
}

void                        TacticalMarine::rangedAttack(void) const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void                        TacticalMarine::meleeAttack(void) const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}
