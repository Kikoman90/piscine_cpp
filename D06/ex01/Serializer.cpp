/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:34:29 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/19 21:09:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() { srand(time(NULL)); }

Serializer::Serializer(Serializer const &src)
{
    srand(time(NULL));
    *this = src;
}

Serializer::~Serializer() {}

Serializer      &Serializer::operator=(Serializer const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void            *Serializer::serialize( void )
{
    Data *newData = new Data();

    newData->s1 = _GenerateString();
    newData->n = rand() % 10;
    newData->s2 = _GenerateString();
    return (reinterpret_cast<void *>(newData));
}

Data            *Serializer::deserialize( void * raw )
{
    Data *data = reinterpret_cast<Data *>(raw);
    return (data);
}

std::string     Serializer::_GenerateString() const
{
    int         i = 0;
    std::string arrAlphaNum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	std::string str;
	while (i < 8)
	{
        str += arrAlphaNum.at(rand() % 61);
        i++;
    }
    return (str);
}