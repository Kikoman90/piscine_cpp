/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:10:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 15:27:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void)
{
    return ;
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &src)
{
    *this = src;
}

DeepCoreMiner::~DeepCoreMiner(void)
{
    return ;
}

DeepCoreMiner               &DeepCoreMiner::operator=(DeepCoreMiner const &rhs)
{
    (void)rhs;
    return (*this);
}

void                        DeepCoreMiner::mine(IAsteroid* ast)
{
    std::cout << "* mining deep ... got " << ast->beMined(this) << " ! *" << std::endl;
}