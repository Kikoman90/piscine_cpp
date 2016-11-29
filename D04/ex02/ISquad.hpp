/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:32 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:43:32 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SQUAD_HPP
# define I_SQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
    public:
        virtual                 ~ISquad() {}
        virtual int             getCount() const = 0;
        virtual ISpaceMarine*   getUnit(int) = 0;
        virtual int             push(ISpaceMarine*) = 0;
};

#endif
