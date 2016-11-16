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
	return ;
}

std::string	Brain::identify(void) const
{
	std::ostringstream	address;
	address << this;
	return (address.str());
}

Brain::~Brain(void)
{
	return ;
}
