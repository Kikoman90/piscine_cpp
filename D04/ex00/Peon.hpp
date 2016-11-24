/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:21:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:21:09 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim {

    public:
        Peon(std::string const name);
        Peon(Peon const &src);
        ~Peon(void);

        virtual void    getPolymorphed(void) const;

        Peon            &operator=(Peon const &rhs);

    private:
        Peon(void);

};

#endif
