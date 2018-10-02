/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:05:22 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 18:46:30 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::ostringstream address_stream;

	std::srand(std::time(NULL));
	this->_iq = rand() % 151;
	address_stream << this;
	this->_address = address_stream.str();
	return ;
}

std::string	Brain::identify(void) const { return (this->_address); }

Brain::~Brain(void)
{
	return ;
}
