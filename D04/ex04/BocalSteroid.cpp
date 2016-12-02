/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BocalSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:47:07 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:48:13 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BocalSteroid.hpp"

BocalSteroid::BocalSteroid(void)
{
    return ;
}

BocalSteroid::BocalSteroid(BocalSteroid const &src)
{
    *this = src;
}

BocalSteroid::~BocalSteroid(void)
{
    return ;
}

BocalSteroid         &BocalSteroid::operator=(BocalSteroid const &rhs)
{
    (void)rhs;
    return (*this);
}

std::string         BocalSteroid::beMined(StripMiner* miner) const
{
    (void)miner;
    return ("Krpite");
}

std::string         BocalSteroid::beMined(DeepCoreMiner* miner) const
{
    (void)miner;
    return ("Zazium");
}

std::string         BocalSteroid::getName(void) const
{
    return ("BocalSteroid");
}