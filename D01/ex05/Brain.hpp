/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:05:00 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 18:14:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class	Brain
{
	public:

		Brain(void);
		~Brain(void);

		std::string		identify(void) const;	

	private:

		unsigned int 	_iq;
		std::string		_address;

};

#endif
