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

Weapon::Weapon(std::string type) : type(type)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string   Weapon::getType()
{
    return (this->type);
}

void                Weapon::setType(std::string type)
{
    this->type = type;
}
