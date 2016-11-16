/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:30:53 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 16:24:35 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:

		Zombie(std::string name, std::string type);
		~Zombie(void);

		void		announce(void) const;
		
	private:
		
		std::string	_name;
		std::string	_type;
};

#endif
