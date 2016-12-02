/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:29:22 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:30:03 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner(void)
{
    return ;
}

StripMiner::StripMiner(StripMiner const &src)
{
    *this = src;
}

StripMiner::~StripMiner(void)
{
    return ;
}

StripMiner               &StripMiner::operator=(StripMiner const &rhs)
{
    (void)rhs;
    return (*this);
}

void                        StripMiner::mine(IAsteroid* ast)
{
    std::cout << "* strip mining ... got " << ast->beMined(this) << " ! *" << std::endl;
}