/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 02:27:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/02 03:44:41 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook.hpp"

class Contact {

public:
	Contact(void);
	~Contact(void);
	char	first_name[30];
	char	last_name[30];
	char	nickname[30];
	char	login[30];
	char	p_address[30];
	char	e_address[30];
	char	phone[30];
	char	bday[30];
	char	fav_meal[30];
	char	underwear_col[30];
	char	secret[30];

};

#endif
