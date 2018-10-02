/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:26:31 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/07 18:26:39 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class   HumanB {

public:
    HumanB(std::string name);
    ~HumanB();

    void    setWeapon(Weapon::Weapon &weapon);
    void    attack();

private:
    std::string	_name;
    Weapon      *_weapon;

};

#endif
