/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:42:29 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 18:02:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class	Human
{
	public:

		Human(void);
		~Human(void);

		Brain			getBrain(void) const;
		std::string		identify(void) const;	

	private:

		const Brain		_humanBrain;

};

#endif
