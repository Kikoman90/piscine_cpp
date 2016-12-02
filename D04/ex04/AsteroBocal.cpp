/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroBocal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:41:42 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:46:56 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroBocal.hpp"

AsteroBocal::AsteroBocal(void)
{
    return ;
}

AsteroBocal::AsteroBocal(AsteroBocal const &src)
{
    *this = src;
}

AsteroBocal::~AsteroBocal(void)
{
    return ;
}

AsteroBocal         &AsteroBocal::operator=(AsteroBocal const &rhs)
{
    (void)rhs;
    return (*this);
}

std::string         AsteroBocal::beMined(StripMiner* miner) const
{
    (void)miner;
    return ("Flavium");
}

std::string         AsteroBocal::beMined(DeepCoreMiner* miner) const
{
    (void)miner;
    return ("Thorite");
}

std::string         AsteroBocal::getName(void) const
{
    return ("AsteroBocal");
}