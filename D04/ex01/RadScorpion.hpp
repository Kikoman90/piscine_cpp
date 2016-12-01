/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:59 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/30 20:37:26 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy {

    public:
        RadScorpion(void);
        RadScorpion(RadScorpion const &src);
        ~RadScorpion(void);

        RadScorpion     &operator=(RadScorpion const &rhs);

    private:

};

#endif
