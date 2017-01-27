/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CloseLoop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:53:50 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:46:18 by fsidler          ###   ########.fr       */
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

IInstruction                            *CloseLoop::clone() const { return ((IInstruction*)new CloseLoop(*this)); }

std::vector<IInstruction*>::iterator    CloseLoop::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    if (**ptr != 0)
    {
        int p = 0;
        typedef std::reverse_iterator<std::vector<IInstruction*>::iterator> revIter;
        --it;
        for (revIter rev_it(it); rev_it != c.rend(); ++rev_it)
        {
            CloseLoop   *c_l = dynamic_cast<CloseLoop*>(*rev_it);
            if (c_l)
                p++;
            else
            {
                OpenLoop    *o_l = dynamic_cast<OpenLoop*>(*rev_it);
                if (o_l && p == 0)
                    return (--rev_it.base());
                else if (o_l)
                    p--;
            }
        }
        return (c.begin());
        /*also works*. /*int p = 0;
        --it;
        for ( ; it != c.begin(); --it)
        {
            CloseLoop   *c_l = dynamic_cast<CloseLoop*>(*it);
            if (c_l)
                p++;
            else
            {
                OpenLoop    *o_l = dynamic_cast<OpenLoop*>(*it);
                if (o_l && p == 0)
                    return (it);
                else if (o_l)
                    p--;
            }
        }
        return (c.begin());*/ /*also works*/
    }
    return (it);
}