/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:44:20 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 18:03:20 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	return ;
}

Brain		Human::getBrain(void) const
{
	return (this->_humanBrain);
}

std::string	Human::identify(void) const
{
	return (this->_humanBrain.identify());
}

Human::~Human(void)
{
	return ;
}
