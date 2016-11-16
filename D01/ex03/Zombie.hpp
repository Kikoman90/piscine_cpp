/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:30:53 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 14:57:42 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void		announce(void) const;
		void		initZombie(std::string name, std::string type);
		
	private:
		
		std::string	_name;
		std::string	_type;
};

#endif
