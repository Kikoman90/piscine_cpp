/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:07:34 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:25:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEP_CORE_MINER_HPP
# define DEEP_CORE_MINER_HPP

# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {

    public:
        DeepCoreMiner(void);
        DeepCoreMiner(DeepCoreMiner const &src);
        ~DeepCoreMiner(void);

        DeepCoreMiner       &operator=(DeepCoreMiner const &rhs);

        void                mine(IAsteroid*);

};

#endif