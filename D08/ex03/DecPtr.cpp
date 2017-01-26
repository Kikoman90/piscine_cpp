/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecPtr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:46:32 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:02:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecPtr.hpp"

DecPtr::DecPtr() {}

DecPtr::DecPtr(DecPtr const &src) { *this = src; }

DecPtr::~DecPtr() {}

DecPtr                                  &DecPtr::operator=(DecPtr const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

std::vector<IInstruction*>::iterator    DecPtr::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    static_cast<void>(c);
    *ptr -= 1;
    return (it);
}