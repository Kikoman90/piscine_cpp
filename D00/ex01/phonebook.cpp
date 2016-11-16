/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 03:06:57 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/02 05:13:10 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static int		display_contacts(Contact *book, int i)
{
	int		j;
	char	buf[64];

	j = 0;
	if (i == 0)
		return 0;
	while (j < i)
	{
		std::cout << "|" << j + 1 << "         |";
		add_column(book[j].first_name);
		add_column(book[j].last_name);
		add_column(book[j].nickname);
		std::cout << std::endl;
		j++;
	}
	std::cout << "-Please enter the index of the contact" << std::endl;
	std::cin.getline(buf, sizeof(buf));
	if (ft_atoi(buf) < 1 || ft_atoi(buf) > i)
	{
		std::cout << "-Please enter a valid number" << std::endl << std::endl;
		return 0;
	}
	display_search(book[ft_atoi(buf) - 1]);
	return 0;
}

static int		add_contact_com(const char *command, char *info)
{
	char	buf[1024];

	std::cout << "	-" << command << std::endl;
	std::cin.getline(buf, sizeof(buf));
	ft_strcpy(info, buf);
	return 0;
}

static Contact	add_contact(Contact book)
{
	std::cout << "-Please enter the following information about the contact"
		<< std::endl;
	add_contact_com("First name:", book.first_name);
	add_contact_com("Last name:", book.last_name);
	add_contact_com("Nickname:", book.nickname);
	add_contact_com("Login:", book.login);
	add_contact_com("Postal address:", book.p_address);
	add_contact_com("Email address:", book.e_address);
	add_contact_com("Phone number:", book.phone);
	add_contact_com("Birthday date:", book.bday);
	add_contact_com("Favorite meal:", book.fav_meal);
	add_contact_com("Underwear color:", book.underwear_col);
	add_contact_com("Darkest secret:", book.secret);
	std::cout << "-Done!" << std::endl;
	return book;
}

static int		input_command(Contact *book, int i)
{
	char	buf[1024];
	
	std::cin.getline(buf, sizeof(buf));
	if (ft_strcmp(buf, "EXIT") == 0)
		return 0;
	else if (ft_strcmp(buf, "ADD") == 0)
	{
		if (i > 7)
			std::cout <<
			"-We're sorry! This phonebook can only contain up to 8 contacts"
			<< std::endl;
		else
		{
			book[i] = add_contact(book[i]);
			i++;
		}
	}
	else if (ft_strcmp(buf, "SEARCH") == 0)
		display_contacts(book, i);
	else
		std::cout << "-Please enter a valid command" << std::endl;
	std::cout << std::endl;
	input_command(book, i);
	return 0;
}

int				main(void)
{
	Contact		book[8];
	std::cout << "-- Welcome to the Super Amazing PhoneBook! --" << std::endl
		<< "- - - - - - - - - - - - - - - - - - - - - - -" << std::endl
		<< "-Please enter one of the following commands: ADD/SEARCH/EXIT"
		<< std::endl << std::endl;
	input_command(book, 0);
	return 0;
}
