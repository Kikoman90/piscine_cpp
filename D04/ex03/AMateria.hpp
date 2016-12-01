/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:30 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:16:31 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    private:
        AMateria(void);

        std::string         _type;
        unsigned int        xp_;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const &src);
        virtual ~AMateria();

        AMateria            &operator=(AMateria const &rhs);

        std::string const   &getType() const;
        unsigned int        getXP() const;

        void                increaseXP();

        virtual AMateria    *clone() const = 0;
        virtual void        use(ICharacter& target);
};

#endif