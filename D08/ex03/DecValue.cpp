/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecValue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:47:45 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:02:33 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecValue.hpp"

DecValue::DecValue() {}

DecValue::DecValue(DecValue const &src) { *this = src; }

DecValue::~DecValue() {}

DecValue                                &DecValue::operator=(DecValue const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

std::vector<IInstruction*>::iterator    DecValue::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    static_cast<void>(c);
    **ptr -= 1;
    return (it);
}