/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:27:09 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/24 16:02:07 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &src) { *this = src; }

Span::~Span() {}

Span                        &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        _vec.erase(_vec.begin(), _vec.begin() + _vec.size());
        _maxSize = rhs._maxSize;
        _vec = rhs._vec;
    }
    return (*this);
}

void                        Span::addNumber(unsigned int number)
{
    if (_vec.size() >= _maxSize)
        throw (Span::ListIsFullException::ListIsFullException());
    _vec.insert(_vec.begin(), number);
}

void                        Span::addNumber(unsigned int number, unsigned int int_begin, unsigned int int_end)
{
    int_begin = (int_begin < int_end) ? int_begin : int_end;
    std::vector<int>::iterator  start = (int_begin > _vec.size()) ? _vec.begin() + _vec.size() : _vec.begin() + int_begin;
    std::vector<int>::iterator  end = (int_end > _vec.size()) ? _vec.begin() + _vec.size(): _vec.begin() + int_end + 1;
    _vec.erase(start, end);
    _vec.insert(start, (int_end - int_begin) + 1, number);
}

void                        Span::print_vec() const
{
    std::vector<int>::const_iterator    it;
    for (it = _vec.begin(); it != _vec.end(); ++it)
         std::cout << *it << " ";
    std::cout << std::endl;
}

unsigned int                Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw (Span::NoSpanException::NoSpanException());
    unsigned int    span = longestSpan();
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
    {
        for (std::vector<int>::const_iterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
        {
            if (it2 != it && *it2 == *it)
                return (0);
            else if (it2 != it && *it2 > *it)
                span = (static_cast<unsigned int>(*it2 - *it) < span) ? *it2 - *it : span;
            else if (it2 != it && *it > *it2)
                span = (static_cast<unsigned int>(*it - *it2) < span) ? *it - *it2 : span;
        }
    }
    return (span);
}

unsigned int                Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw (Span::NoSpanException::NoSpanException());
    return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}

Span::ListIsFullException::ListIsFullException() {}

Span::ListIsFullException::ListIsFullException(ListIsFullException const &src) { *this = src; }

Span::ListIsFullException::~ListIsFullException() throw() {}

Span::ListIsFullException   &Span::ListIsFullException::operator=(ListIsFullException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

char const                  *Span::ListIsFullException::what() const throw() { return ("Int container full: cannot add new number"); }

Span::NoSpanException::NoSpanException() {}

Span::NoSpanException::NoSpanException(NoSpanException const &src) { *this = src; }

Span::NoSpanException::~NoSpanException() throw() {}

Span::NoSpanException       &Span::NoSpanException::operator=(NoSpanException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

char const                  *Span::NoSpanException::what() const throw() { return ("No Span"); }