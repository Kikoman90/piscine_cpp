/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IToken.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:42:19 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/30 20:30:20 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_TOKEN_HPP
# define I_TOKEN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <stack>
# include <list>
# include <vector>

class   IToken {

    public:
        virtual     ~IToken() {}

        virtual IToken  *clone() const = 0;

        virtual void    display() const = 0;
        //void    completeDisplay() const;                                                                    } put in derived classes Num and Op

        //std::stack<int> execute(std::stack<int> &st); si ca marche pas: std::stack< int, std::vector<int> > } put in derived classes Num and Op

};

#endif