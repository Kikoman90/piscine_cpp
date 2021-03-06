/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:21:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:21:52 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
    Sorcerer    Sorc("Robert", "the Magnificent");
    
    Victim      Vict("Pierre-Baptiste");
    Peon        Pe("Jerem");

    std::cout << Sorc << Vict << Pe;

    Sorc.polymorph(Vict);
    Sorc.polymorph(Pe);

    return 0;
}
