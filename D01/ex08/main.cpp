/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:17:56 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 14:19:32 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human human;

	human.action("melee", "thalmor");
	human.action("ranged", "whiterun_gard");
	human.action("intimidating", "Ysolda");
	human.action("melee", "draugr");
	return (0);
}
