/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:56:35 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 15:33:10 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include "Zombie.hpp"

class	ZombieHorde
{
	public:

		ZombieHorde(int N);
		~ZombieHorde(void);

		void	announce(void) const;

	private:

		static std::string	_nameTab[10];
		Zombie				*_horde;
		int					_nb;
				
};

#endif
