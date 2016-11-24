/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:39 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:40 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

    public:
        PlasmaRifle(void);
        PlasmaRifle(PlasmaRifle const &src);
        ~PlasmaRifle(void);

        PlasmaRifle     &operator=(PlasmaRifle const &rhs);
        
        void            attack(void) const;

    private:
};

#endif
