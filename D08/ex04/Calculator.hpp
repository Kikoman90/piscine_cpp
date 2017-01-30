/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:10:25 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/30 19:48:53 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP

# include "IToken.hpp"
# include "NumToken.hpp"
# include "OpToken.hpp"
# include "ParOpenToken.hpp"
# include "ParCloseToken.hpp"

class   Calculator {

    public:
        Calculator(char *str);
        Calculator(Calculator const &src);
        ~Calculator();

        Calculator              &operator=(Calculator const &rhs);

        void                    tokenize();
        //void                    result();

    private:
        class   InvalidTokenException : public std::exception {
            
            public:
                InvalidTokenException();
                InvalidTokenException(InvalidTokenException const &src);
                virtual ~InvalidTokenException() throw();

                InvalidTokenException       &operator=(InvalidTokenException const &rhs);

                char const                  *what() const throw();

        };

        class   InvalidOperationException : public std::exception {
            
            public:
                InvalidOperationException();
                InvalidOperationException(InvalidOperationException const &src);
                virtual ~InvalidOperationException() throw();

                InvalidOperationException   &operator=(InvalidOperationException const &rhs);

                char const                  *what() const throw();

        };

        Calculator();

        void                    _print_list(std::vector<IToken*> const &) const;
        //void                    _convertToPostfix();

        char                    *_input;
        std::vector<IToken*>    _operationList;
        //std::vector<IToken*>    _postfixList;

};

#endif