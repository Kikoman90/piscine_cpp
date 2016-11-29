/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:42 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/29 20:43:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

typedef struct      s_unit
{
    int             index;
    ISpaceMarine    *SpaceMarine;
    struct s_unit   *next;
}                   t_unit;

class Squad : public ISquad {

     private:
        t_unit              *_list;

        void                _freeUnitList(void);

    public:
        Squad(void);
        Squad(Squad const &src);
        ~Squad(void);

        Squad               &operator=(Squad const &rhs);

        int                 getCount(void) const;
        int                 push(ISpaceMarine*);

        ISpaceMarine        *getUnit(int);

};

#endif
