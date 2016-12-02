/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:30:29 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:12:14 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIP_MINER_HPP
# define STRIP_MINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

    public:
        StripMiner(void);
        StripMiner(StripMiner const &src);
        ~StripMiner(void);

        StripMiner  &operator=(StripMiner const &rhs);

        void        mine(IAsteroid*);

};

#endif