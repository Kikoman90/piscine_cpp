/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:57:39 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/01 17:02:50 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void			search_book(Contact book[], unsigned int contact_count) {
	
	unsigned int	index;
	std::string		number;

	if (contact_count <= 0) {
		std::cout << '\t' << "-This phonebook is empty" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < contact_count; i++) {
		book[i].display_row(i);
	}
	std::cout << std::endl << "-Please enter an index between " << '1' << " and " << contact_count << std::endl;
	std::getline(std::cin, number);
	if (number.length() != 1 || number[0] < 49 || number[0] > (int)(48 + contact_count)) {
		std::cout << '\t' << "-We're sorry! You entered an invalid index" << std::endl;
		return ;
	}
	index = number[0] - 49;
	book[index].display_list();

}

void			user_command(Contact book[], unsigned int contact_count) {
	
	std::string command;

	while (command != "EXIT") {

		std::cout << "-Please enter one of the following commands: ADD/SEARCH/EXIT" << std::endl << '-';
		std::getline(std::cin, command);

		if (command == "ADD") {

			if (contact_count > 7)
				std::cout << '\t' << "-We're sorry! This phonebook can only contain up to 8 contacts" << std::endl;
			else
			{
				book[contact_count].feed();
				contact_count++;
			}

		} else if (command == "SEARCH") {
			search_book(book, contact_count);
		} else if (command != "EXIT" && command != "")
			std::cout << "-Please enter a valid command" << std::endl;
		std::cout << std::endl;
	}
}

int				main(void) {

	Contact	contact_book[8];

	std::cout << "-- Welcome to the Super Amazing PhoneBook! --" << std::endl
		<< "- - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	user_command(contact_book, 0);
	return (0);

}
