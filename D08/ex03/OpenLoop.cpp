/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenLoop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:51:57 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:03:04 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenLoop.hpp"

OpenLoop::OpenLoop() {}

OpenLoop::OpenLoop(OpenLoop const &src) { *this = src; }

OpenLoop::~OpenLoop() {}

OpenLoop                                &OpenLoop::operator=(OpenLoop const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

std::vector<IInstruction*>::iterator    OpenLoop::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    if (**ptr == 0)
    {
        for (std::vector<IInstruction*>::iterator it_cpy = it; it_cpy != c.end(); ++it_cpy)
        {
            CloseLoop   *c_l = dynamic_cast<CloseLoop*>(*it_cpy);
            if (c_l)
                return (it_cpy);
        }
        return (c.end());
    }
    return (it);
}