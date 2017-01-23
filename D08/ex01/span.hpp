/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:14:43 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 21:04:33 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

class   Span {

    public:
        Span(unsigned int N);
        Span(Span const &src);
        ~Span();

        Span                                    &operator=(Span const &rhs);

        void                                    addNumber(unsigned int number);
        void                                    addNumber(unsigned int number, unsigned int int_begin, unsigned int int_end);

        void                                    print_vec() const;

        //unsigned int                          shortestSpan() const;
        //unsigned int                          longestSpan() const;

    private:
        Span();

        unsigned int                            _maxSize;
        std::vector<int>                        _vec;
        
        std::vector<int>::iterator              get_iterator_from_int(unsigned int index);

        class                                   ListIsFullException : public std::exception {

            public:
                ListIsFullException();
                ListIsFullException(ListIsFullException const &src);
                virtual ~ListIsFullException() throw();

                ListIsFullException             &operator=(ListIsFullException const &rhs);

                char const                      *what() const throw();

        };

        class                                   NoSpanException : public std::exception {

            public:
                NoSpanException();
                NoSpanException(NoSpanException const &src);
                virtual ~NoSpanException() throw();

                NoSpanException                 &operator=(NoSpanException const &rhs);

                char const                      *what() const throw();

        };

        class                                   InvalidIteratorIndexException : public std::exception {

            public:
                InvalidIteratorIndexException();
                InvalidIteratorIndexException(InvalidIteratorIndexException const &src);
                virtual ~InvalidIteratorIndexException() throw();

                InvalidIteratorIndexException   &operator=(InvalidIteratorIndexException const &rhs);

                char const                      *what() const throw();

        };

};

#endif