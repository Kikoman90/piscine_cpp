/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:59:27 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 20:00:35 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class   SuperTrap : public FragTrap, public NinjaTrap {

public:
    SuperTrap(std::string const name);
    SuperTrap(SuperTrap const &src);
    ~SuperTrap(void);

    SuperTrap &operator=(SuperTrap const &rhs);

private:
    SuperTrap(void);

};

#endif