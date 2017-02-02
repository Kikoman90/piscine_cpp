/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IToken.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:42:19 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:43:00 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_TOKEN_HPP
# define I_TOKEN_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <algorithm>
# include <stack>
# include <list>
# include <vector>

class   IToken {

    public:
        virtual             ~IToken() {}

        virtual IToken      *clone() const = 0;

        virtual std::string display() const = 0;

};

#endif