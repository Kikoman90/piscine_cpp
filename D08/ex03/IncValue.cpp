/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncValue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:00 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:02:52 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncValue.hpp"

IncValue::IncValue() {}

IncValue::IncValue(IncValue const &src) { *this = src; }

IncValue::~IncValue() {}

IncValue                                &IncValue::operator=(IncValue const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

std::vector<IInstruction*>::iterator    IncValue::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    static_cast<void>(c);
    **ptr += 1;
    return (it);
}