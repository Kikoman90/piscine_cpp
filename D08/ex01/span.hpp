/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:14:43 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 14:46:45 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template< typename T = std::vector<int> >
class   Span {

    public:
        Span(unsigned int N);
        Span(Span const &src);
        ~Span();

        Span            &operator=(Span const &rhs);

        void            addNumber(int number);
        void            addNumber(int number, const typename T::const_iterator begin, const typename T::const_iterator end);

        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
        
        unsigned int    getSize() const;

    private:
        Span();

        unsigned int    _maxSize;
        T               _cont;
        
        class           NoSpanException : public std::exception {

            public:
                NoSpanException();
                NoSpanException(NoSpanException const &src);
                virtual ~NoSpanException() throw();

                NoSpanException &operator=(NoSpanException const &rhs);

                char const      *what() const throw();

        };

};

#endif