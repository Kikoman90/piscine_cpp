/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:48:45 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:59:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINING_BARGE_HPP
# define MINING_BARGE_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class MiningBarge
{
    private:
        IMiningLaser    *_tab[4];

        void            _freeTab(void);

    public:
        MiningBarge(void);
        MiningBarge(MiningBarge const &src);
        ~MiningBarge(void);

        MiningBarge     &operator=(MiningBarge const &rhs);

        IMiningLaser    *getTab(int idx) const;

        void            equip(IMiningLaser*);
        void            mine(IAsteroid*) const;
};

#endif