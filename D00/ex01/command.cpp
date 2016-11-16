/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 04:56:29 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/02 05:04:30 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void		add_column(char *str)
{
	int		i;

	i = 0;
	if (ft_length(str) >= 10)
	{
		while (i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << '.';
	}
	else
	{
		std::cout << str;
		while (i < 10 - ft_length(str))
		{
			std::cout << " ";
			i++;
		}
	}
	std::cout << '|';
}

static void	display_info(const char *buf, char *info)
{
	std::cout << buf << info << std::endl;
}

void		display_search(Contact book)
{
	std::cout << "-Informations about the contact:" << std::endl;
	display_info("	-First name: ", book.first_name);
	display_info("	-Last name: ", book.last_name);
	display_info("	-Nickname: ", book.nickname);
	display_info("	-Login: ", book.login);
	display_info("	-Postal address: ", book.p_address);
	display_info("	-Email address: ", book.e_address);
	display_info("	-Phone number: ", book.phone);
	display_info("	-Birthday date: ", book.bday);
	display_info("	-Favorite meal: ", book.fav_meal);
	display_info("	-Underwear color: ", book.underwear_col);
	display_info("	-Darkest secret: ", book.secret);
	std::cout << std::endl;
}
