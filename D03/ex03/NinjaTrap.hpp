/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:59:27 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 20:00:35 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"

class   NinjaTrap : public ClapTrap{

public:
    NinjaTrap(std::string const name);
    NinjaTrap(NinjaTrap const &src);
    ~NinjaTrap(void);

    NinjaTrap &operator=(NinjaTrap const &rhs);

    void    ninjaShoebox(std::string const &target);

private:
    NinjaTrap(void);

};

#endif
