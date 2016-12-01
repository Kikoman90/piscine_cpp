/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/30 20:35:50 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

    public:

        Ice(void);
        Ice(Ice const &src);
        ~Ice(void);

        Ice             &operator=(Ice const &rhs);

        AMateria        *clone() const;
        void            use(ICharacter&);

};

#endif