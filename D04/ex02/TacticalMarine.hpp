/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:43:52 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

    public:
        TacticalMarine(void);
        TacticalMarine(TacticalMarine const &src);
        ~TacticalMarine(void);

        TacticalMarine      &operator=(TacticalMarine const &rhs);

        ISpaceMarine        *clone(void) const;
        void                battleCry(void) const;
        void                rangedAttack(void) const;
        void                meleeAttack(void) const;

};

#endif
