/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:09 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/05 13:01:12 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon {

    private:
        AWeapon(void);
        std::string			_name;
        int					_apcost;
        int					_damage;

    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const &src);
        virtual ~AWeapon(void);

        AWeapon				&operator=(AWeapon const &rhs);

        std::string const	&getName(void) const;
        int					getAPCost(void) const;
        int					getDamage(void) const;

        void				setName(std::string const &);
        void				setDamage(int);
        void				setAPCost(int);

        virtual void		attack(void) const = 0;
};

#endif
