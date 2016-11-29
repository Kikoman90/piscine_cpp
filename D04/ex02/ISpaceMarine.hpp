/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:41:38 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:41:39 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SPACE_MARINE_HPP
# define I_SPACE_MARINE_HPP

# include <iostream>

class ISpaceMarine
{
    public:
        virtual                 ~ISpaceMarine() {}
        virtual ISpaceMarine*   clone() const = 0;
        virtual void            battleCry() const = 0;
        virtual void            rangedAttack() const = 0;
        virtual void            meleeAttack() const = 0;
};

#endif
