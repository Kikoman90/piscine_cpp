/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:26:53 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/07 18:26:55 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string   &Weapon::getType()
{
    return (this->_type);
}

void                Weapon::setType(std::string type)
{
    this->_type = type;
}
