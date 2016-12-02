/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:03:46 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:21:05 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

int         main()
{
    std::cout << "_creating barge_" << std::endl;
    MiningBarge     *barge = new MiningBarge();
    std::cout << "_creating 2 asteroids_" << std::endl;
    IAsteroid       *ast1 = new AsteroBocal();
    IAsteroid       *ast2 = new BocalSteroid();
    std::cout << "_creating 2 lasers_" << std::endl;
    IMiningLaser    *laser1 = new DeepCoreMiner();
    IMiningLaser    *laser2 = new StripMiner();

    std::cout << "_equipping barge with lasers_" << std::endl;
    barge->equip(laser1);
    barge->equip(laser2);

    std::cout << "_mining both asteroids_" << std::endl;
    barge->mine(ast1);
    barge->mine(ast2);

    IMiningLaser    *laser3 = new DeepCoreMiner();
    IMiningLaser    *laser4 = new DeepCoreMiner();
    IMiningLaser    *laser5 = new StripMiner();
    barge->equip(laser3);
    barge->equip(laser4);
    std::cout << "_trying to add a 5th laser_" << std::endl;
    barge->equip(laser5);

    std::cout << "_mining with all 4 lasers_" << std::endl;
    barge->mine(ast2);
    return 0;
}