/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:49:22 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:40:27 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_TOKEN_HPP
# define OP_TOKEN_HPP

# include "IToken.hpp"

class   OpToken : public IToken {

    public:
        OpToken(char op);
        OpToken(OpToken const &src);
        ~OpToken();

        OpToken     &operator=(OpToken const &rhs);

        IToken      *clone() const;

        char        getOp() const;

        std::string display() const;
        void        completeDisplay(unsigned int length) const;

        int         operation(int n1, int n2) const;

    private:
        char        _op;

};

#endif