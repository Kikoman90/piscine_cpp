/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:28 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:29 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy {

    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const &src);
        virtual         ~Enemy(void);

        Enemy           &operator=(Enemy const &rhs);

        std::string const   getType(void) const;
        int                 getHP(void) const;

        void                setType(std::string const & type);
        void                setHP(int hp);

        virtual void        takeDamage(int);

    private:
        Enemy(void);

        int                 _hp;
        std::string         _type;

};

#endif
