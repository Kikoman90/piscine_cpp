/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:27:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/07 18:27:04 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class   Weapon{

public:
    Weapon(std::string type);
    ~Weapon();

    const std::string   &getType();
    void                setType(std::string type);

private:
    std::string			_type;

};

#endif
