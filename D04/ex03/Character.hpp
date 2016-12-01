/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:39:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:11:45 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
    
    private:
        Character(void);

        AMateria            *_inv[4];
        std::string         _name;

        void                _freeInv();

    public:
        Character(std::string const name);
        Character(Character const &src);
        ~Character(void);

        Character           &operator=(Character const &rhs);
        
        std::string const   &getName() const;
        AMateria            *getInv(int idx) const;
        
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);
};

#endif