/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CloseLoop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:53:50 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 18:53:23 by fsidler          ###   ########.fr       */
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
        /*std::vector<IInstruction*>::iterator  find = it;
        for (std::vector<IInstruction*>::iterator  beg = c.begin(); beg != it && beg != c.end(); ++beg)
        {
            OpenLoop    *o_l = dynamic_cast<OpenLoop*>(*beg);
            if (o_l)
                find = beg;
        }
        return (find);*/
        /*std::cout << "close loop" << std::endl;*/
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

    }
    return (it);
}