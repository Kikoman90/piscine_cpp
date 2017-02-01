/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:45:43 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/01 20:45:05 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"

int     main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0])
	{
        Calculator  calc(argv[1]);

        try
        {
            calc.tokenize();
            calc.result();
        }
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }
    else
        std::cout << "usage: ./calculator input" << std::endl;
    return (0);
}