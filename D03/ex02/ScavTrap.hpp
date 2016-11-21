/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:53:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:53:11 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap{

public:
    ScavTrap(std::string const name);
    ScavTrap(ScavTrap const &src);
    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &rhs);

    void    challengeNewcomer(std::string const &target);

private:
    ScavTrap(void);

};

#endif
