/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:33:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:14:07 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ASTEROID_HPP
# define I_ASTEROID_HPP

# include <iostream>

class DeepCoreMiner;
class StripMiner;

class IAsteroid
{
    public:
        virtual ~IAsteroid() {}
        virtual std::string beMined(StripMiner*) const = 0;
        virtual std::string beMined(DeepCoreMiner*) const = 0;
        virtual std::string getName() const = 0;
};

#endif