/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:50:54 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/23 13:54:50 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class   ClapTrap{

public:
    ClapTrap(std::string const name);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap(void);

    ClapTrap &operator=(ClapTrap const &rhs);

    void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    std::string const   name;

protected:
    ClapTrap(void);

    void    log() const;

    unsigned int        hitPoints;
    unsigned int        maxHitPoints;
    unsigned int        energyPoints;
    unsigned int        maxEnergyPoints;
    unsigned int        level;
    unsigned int        meleeAttackDamage;
    unsigned int        rangedAttackDamage;
    unsigned int        armorDamageReduction;
};

#endif
