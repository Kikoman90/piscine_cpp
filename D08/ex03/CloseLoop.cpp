/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CloseLoop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:53:50 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:02:12 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CloseLoop.hpp"

CloseLoop::CloseLoop() {}

CloseLoop::CloseLoop(CloseLoop const &src) { *this = src; }

CloseLoop::~CloseLoop() {}

CloseLoop                               &CloseLoop::operator=(CloseLoop const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

std::vector<IInstruction*>::iterator    CloseLoop::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    if (**ptr != 0)
    {
        std::vector<IInstruction*>::iterator  find = it;
        for (std::vector<IInstruction*>::iterator  beg = c.begin(); beg != it && beg != c.end(); ++beg)
        {
            OpenLoop    *o_l = dynamic_cast<OpenLoop*>(*beg);
            if (o_l)
                find = beg;
        }
        return (find);
    }
    return (it);
}