/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:21:21 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:21:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer {

    public:
        Sorcerer(std::string const name, std::string const title);
        Sorcerer(Sorcerer const &src);
        ~Sorcerer(void);

        Sorcerer    &operator=(Sorcerer const &rhs);

        void        polymorph(Victim const &target) const;

        std::string getName(void) const;
        std::string getTitle(void) const;

    private:
        std::string   _name;
        std::string   _title;
        Sorcerer(void);

};

std::ostream        &operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
