/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:22:01 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 15:34:21 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Player uses melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Player uses ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Player uses intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	int	i = 0;
	const std::string	arrName[3] = {"melee", "ranged", "intimidating"};
	void	(Human::*arrPtr[3])(std::string const & target) =
	{&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	while (i < 3)
	{
		if (action_name.compare(arrName[i]) == 0)
			(this->*arrPtr[i])(target);
		i++;
	}
}
