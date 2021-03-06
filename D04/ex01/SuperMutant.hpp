/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:23:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/30 20:37:29 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {

    public:
        SuperMutant(void);
        SuperMutant(SuperMutant const &src);
        ~SuperMutant(void);

        SuperMutant     &operator=(SuperMutant const &rhs);

        void            takeDamage(int);

    private:

};

#endif
