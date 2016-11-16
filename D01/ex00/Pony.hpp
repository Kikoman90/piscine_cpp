/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:53:39 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 13:59:12 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class	Pony
{
	public:

		static unsigned int	getNbPony(void);

		Pony(float height, int age, std::string name, std::string color);
		~Pony(void);

		void				displayPonyInfos(void) const;
		
	private:
		
		static unsigned int	_nbPony;

		float				_height;
		unsigned int		_age;
		std::string			_name;
		std::string			_color;
};

#endif
