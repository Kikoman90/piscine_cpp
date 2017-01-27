/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenLoop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:51:57 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 18:53:10 by fsidler          ###   ########.fr       */
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
        int p = 0;
        ++it;
        for (std::vector<IInstruction*>::iterator it_cpy = it; it_cpy != c.end(); ++it_cpy)
        {
            OpenLoop    *o_l = dynamic_cast<OpenLoop*>(*it_cpy);
            if (o_l)
                p++;
            else
            {
                CloseLoop   *c_l = dynamic_cast<CloseLoop*>(*it_cpy);
                if (c_l && p == 0)
                    return (it_cpy);
                else if (c_l)
                    p--;
            }
        }
        return (c.end());
    }
    return (it);
}