/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:57:43 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:57:44 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap{

public:
    FragTrap(std::string const name);
    FragTrap(FragTrap const &src);
    ~FragTrap(void);

    FragTrap &operator=(FragTrap const &rhs);


    void    makeJoke(std::string const  &target);
    void    makeSpin(std::string const &target);
    void    makeOffensiveGesture(std::string const &target);
    void    vaulthunter_dot_exe(std::string const & target);

private:
    FragTrap(void);

};

#endif
