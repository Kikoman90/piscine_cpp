/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:43 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 17:53:00 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class	ZombieEvent
{
	public:

		ZombieEvent(void);
		~ZombieEvent(void);
	
		void				setZombieType(std::string type);
		Zombie				*newZombie(std::string name);
		Zombie				*randomChump(void);	
		
	private:

		std::string				_zombieType;
		static std::string		_nameTab[10];
				
};

#endif
