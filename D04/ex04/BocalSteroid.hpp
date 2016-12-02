/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BocalSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:38:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:43:02 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOCAL_STEROID_HPP
# define BOCAL_STEROID_HPP

# include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid {

    public:
        BocalSteroid(void);
        BocalSteroid(BocalSteroid const &src);
        ~BocalSteroid(void);

        BocalSteroid        &operator=(BocalSteroid const &rhs);

        std::string         beMined(StripMiner*) const;
        std::string         beMined(DeepCoreMiner*) const;

        std::string         getName(void) const;

};

#endif