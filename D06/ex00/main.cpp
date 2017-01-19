/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:19:33 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/18 16:32:18 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <value>" << std::endl;
        return (0);
    }
    double  d = atof(argv[1]);
    int     prec = Convert::getPrecision(argv[1]);
    if (d == 0 && argv[1][0] != '0')
    {
        std::cout << "Invalid parameter" << std::endl;
        return (0);
    }
    try
	{
		std::cout << "char: ";
		char c = Convert::my_dtoc(d);
		std::cout << "'" << c << "'" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: ";
		std::cout << Convert::my_dtoi(d) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: ";
		std::cout << std::setprecision(prec) << std::fixed << Convert::my_dtof(d) << "f" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
    }
	try
	{
		std::cout << "double: ";
		std::cout << std::setprecision(prec) << std::fixed << Convert::my_dtod(d) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}