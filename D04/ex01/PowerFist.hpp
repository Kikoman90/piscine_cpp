/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:50 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/30 20:37:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon {

    public:
        PowerFist(void);
        PowerFist(PowerFist const &src);
        ~PowerFist(void);

        PowerFist     &operator=(PowerFist const &rhs);
        
        void            attack(void) const;

    private:
};

#endif
