/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:45:43 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 14:11:31 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mindopen.hpp"

int     main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0])
	{
        Mindopen    mind_open(argv[1]);

        mind_open.readStr();
        mind_open.executeInstructions();
    }
    else
        std::cout << "usage: ./mindopen input_file" << std::endl;
    return (0);
}