/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:26:10 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/07 18:26:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class   HumanA {

public:
    HumanA(std::string name, Weapon::Weapon& weapon);
    ~HumanA();

    void    attack();

private:
    Weapon 		&_weapon;
    std::string	_name;

};

#endif
