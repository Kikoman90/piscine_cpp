/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:36 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:17:02 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type), xp_(0) {
    return ;
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria::~AMateria()
{
    return ;
}

AMateria            &AMateria::operator=(AMateria const &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs.getType();
        this->xp_ = rhs.getXP();
    }
    return (*this);
}

void	            AMateria::use(ICharacter &character)
{
	(void)character;
}

std::string const   &AMateria::getType(void) const
{
    return (this->_type);
}

unsigned int        AMateria::getXP(void) const
{
    return (this->xp_);
}

void                AMateria::increaseXP(void)
{
    this->xp_ += 10;
}