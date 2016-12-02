/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:06:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:06:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MINING_LASER_HPP
# define I_MINING_LASER_HPP

# include <iostream>
# include "IAsteroid.hpp"

class IAsteroid;

class IMiningLaser
{
    public:
        virtual ~IMiningLaser() {}
        virtual void mine(IAsteroid*) = 0;
};

#endif