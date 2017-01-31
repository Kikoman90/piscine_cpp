/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumToken.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:26:26 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 18:29:53 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_TOKEN_HPP
# define NUM_TOKEN_HPP

# include "IToken.hpp"

class   NumToken : public IToken {

    public:
        NumToken(int num);
        NumToken(NumToken const &src);
        ~NumToken();

        NumToken    &operator=(NumToken const &rhs);

        IToken      *clone() const;

        void        display() const;

    private:
        int         _num;

};

#endif