/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:18 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

    private:
        Character(void);

        std::string         _name;
        int                 _ap;
        AWeapon             *_weapon;

    public:
        Character(std::string const & name);
        Character(Character const &src);
        ~Character(void);

        Character           &operator=(Character const &rhs);

        void                recoverAP(void);
        void                equip(AWeapon*);
        void                attack(Enemy*);

        std::string const   getName(void) const;
        int                 getAP(void) const;
        AWeapon             *getWeapon(void) const;
};

std::ostream    &operator<<(std::ostream &o, Character const &rhs);

#endif
