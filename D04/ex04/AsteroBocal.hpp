/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroBocal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:36:18 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:38:38 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERO_BOCAL_HPP
# define ASTERO_BOCAL_HPP

# include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid {

    private:
        std::string         _name;

    public:
        AsteroBocal(void);
        AsteroBocal(AsteroBocal const &src);
        ~AsteroBocal(void);

        AsteroBocal         &operator=(AsteroBocal const &rhs);

        std::string         beMined(StripMiner*) const;
        std::string         beMined(DeepCoreMiner*) const;

        std::string         getName(void) const;

};

#endif