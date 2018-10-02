/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:57:45 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/01 14:57:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string		get_info(const std::string prefix) {
	
	std::string info;

	std::cout << '\t' << prefix << " : ";
	std::getline(std::cin, info);
	return (info);

}

void			show_info(const std::string prefix, std::string info) {
	std::cout << '\t' << prefix << " : " << info << std::endl;
}

void			Contact::feed(void) {

	first_name = get_info("first name");
	last_name = get_info("last name");
	nickname = get_info("nickname");
	login = get_info("login");
	postal_address = get_info("postal address");
	email_address = get_info("email address");
	phone = get_info("phone number");
	birthday = get_info("birthday date");
	favorite_meal = get_info("favorite meal");
	underwear_color = get_info("underwear color");
	darkest_secret = get_info("darkest_secret");

}

void			Contact::row_block(std::string str) const {

	std::cout << std::setfill(' ') << std::setw(10);
	if (str.length() > 10)
		std::cout << std::left << str.substr(0, 9) + '.';
	else
		std::cout << std::right << str;

}

void			Contact::display_row(unsigned int index) const {

	index++;
	std::cout << '|';
	row_block(std::to_string(index));
	std::cout << '|';
	row_block(first_name);
	std::cout << '|';
	row_block(last_name);
	std::cout << '|';
	row_block(nickname);
	std::cout << '|' << std::endl;

}

void			Contact::display_list(void) const {
	
	show_info("first name", first_name);
	show_info("last name", last_name);
	show_info("nickname", nickname);
	show_info("login", login);
	show_info("postal address", postal_address);
	show_info("email address", email_address);
	show_info("phone number", phone);
	show_info("birthday date", birthday);
	show_info("favorite meal", favorite_meal);
	show_info("underwear color", underwear_color);
	show_info("darkest secret", darkest_secret);

}
