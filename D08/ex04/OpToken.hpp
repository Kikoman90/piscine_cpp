/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:49:22 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/01 23:35:05 by fsidler          ###   ########.fr       */
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

        void        display() const;

    private:
        char        _op;

};

#endif