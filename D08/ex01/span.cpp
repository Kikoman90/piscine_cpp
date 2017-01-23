/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:27:09 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 14:51:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span<T>(unsigned int N) : _cont(new T[N]), _maxSize(N) {}

Span::Span<T>(Span const &src) : _maxSize(src._maxSize)
{
    delete[] _cont;
    _cont = new T[_maxSize];
    //ici
}

Span::~Span<T>() { delete _cont; }

Span    &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this._cont = rhs._cont;
        //deep copy!
    }
    return (*this);
}

