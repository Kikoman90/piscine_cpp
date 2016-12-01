/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:32:18 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/30 20:35:54 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

    public:

        Cure(void);
        Cure(Cure const &src);
        ~Cure(void);

        Cure             &operator=(Cure const &rhs);

        AMateria        *clone() const;
        void            use(ICharacter&);

};

#endif