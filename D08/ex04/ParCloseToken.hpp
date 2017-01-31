/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParCloseToken.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:53:49 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 19:02:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAR_CLOSE_TOKEN_HPP
# define PAR_CLOSE_TOKEN_HPP

# include "IToken.hpp"

class   ParCloseToken : public IToken {

    public:
        ParCloseToken();
        ParCloseToken(ParCloseToken const &src);
        ~ParCloseToken();

        ParCloseToken   &operator=(ParCloseToken const &rhs);

        IToken          *clone() const;

        void            display() const;

};

#endif