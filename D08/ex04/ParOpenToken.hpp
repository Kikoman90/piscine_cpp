/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpenToken.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:57:20 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 19:02:42 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAR_OPEN_TOKEN_HPP
# define PAR_OPEN_TOKEN_HPP

# include "IToken.hpp"

class   ParOpenToken : public IToken {

    public:
        ParOpenToken();
        ParOpenToken(ParOpenToken const &src);
        ~ParOpenToken();

        ParOpenToken    &operator=(ParOpenToken const &rhs);

        IToken          *clone() const;

        void            display() const;

};

#endif