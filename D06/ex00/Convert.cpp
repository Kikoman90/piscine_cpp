/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:41:10 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/18 16:53:28 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(Convert const &src) { *this = src; }

Convert::~Convert() {}

Convert         &Convert::operator=(Convert const &rhs)
{ 
    static_cast<void>(rhs);
    return (*this);
}

int             Convert::getPrecision(char *str)
{
    unsigned int bf;
    unsigned int aft;

    bf = 0;
    while (str[bf] && str[bf] != '.')
        bf++;
    aft = bf + 1;
    while (str[aft] && isdigit(str[aft]))
        aft++;
    aft = aft - bf;
    if (strlen(str) == bf || aft == 1)
        return (1);
    return (aft - 1);
}

char            Convert::my_dtoc(double d)
{
    char    c;
    
    if (isnan(d) == true)
        throw (Convert::ImpossibleException());
    c = static_cast<char>(d);
    if (std::isprint(c) == false)
        throw (Convert::NonDisplayableException());
    return (c);
}

int             Convert::my_dtoi(double d)
{
    if (isnan(d) == true || isinf(d) == true)
        throw (Convert::ImpossibleException());
    if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
        throw (Convert::ImpossibleException());
    return (static_cast<int>(d));
}

float           Convert::my_dtof(double d) { return (static_cast<float>(d)); }

double          Convert::my_dtod(double d) { return (static_cast<double>(d)); }

Convert::NonDisplayableException::NonDisplayableException() {}

Convert::NonDisplayableException::NonDisplayableException(Convert::NonDisplayableException const &src) { *this = src; }

Convert::NonDisplayableException::~NonDisplayableException() throw() {}

Convert::NonDisplayableException    &Convert::NonDisplayableException::operator=(Convert::NonDisplayableException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

const char                          *Convert::NonDisplayableException::what() const throw() { return("Non displayable"); }

Convert::ImpossibleException::ImpossibleException() {}

Convert::ImpossibleException::ImpossibleException(Convert::ImpossibleException const &src) { *this = src; }

Convert::ImpossibleException::~ImpossibleException() throw() {}

Convert::ImpossibleException    &Convert::ImpossibleException::operator=(Convert::ImpossibleException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

const char                          *Convert::ImpossibleException::what() const throw() { return("impossible"); }