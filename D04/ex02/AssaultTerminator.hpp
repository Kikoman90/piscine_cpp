/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:41:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:41:27 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

    public:
        AssaultTerminator(void);
        AssaultTerminator(AssaultTerminator const &src);
        ~AssaultTerminator(void);

        AssaultTerminator      &operator=(AssaultTerminator const &rhs);

        ISpaceMarine        *clone(void) const;
        void                battleCry(void) const;
        void                rangedAttack(void) const;
        void                meleeAttack(void) const;

};

#endif
