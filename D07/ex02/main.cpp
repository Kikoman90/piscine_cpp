/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:16:49 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 20:00:24 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int     main(void)
{
    std::cout << "_creating an array of int_" << std::endl;
    try
	{
		Array<int> tab(5);

		tab[0] = 42;
		tab[1] = 420;
		tab[2] = 9000;
		tab[3] = 69;
		tab[4] = 987;
		for (int i = 0 ; i < 5 ; i++)
			std::cout << tab[i] << " ";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "_creating an array of string_" << std::endl;
	try
	{
		Array<std::string> tab(4);

		tab[0] = "Ah";
		tab[1] = "Bah";
		tab[2] = "Bravo";
		tab[3] = "Niels!";
		for (int i = 0 ; i < 4 ; i++)
			std::cout << tab[i] << " ";
        std::cout << std::endl << "_trying to access an inaccessible element_" << std::endl;
        tab[4] = "inaccessible";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << std::endl << "_testing the copy constructor and operator_" << std::endl;
    try
    {
        std::cout << "_creating tab1_" << std::endl;
        Array<float> tab1(3);
        
        tab1[0] = 42;
        tab1[1] = 9000;
        tab1[2] = 67.7;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab1[i] << "/";
            
        std::cout << std::endl << "_copy construction: creating tab2(tab1)_" << std::endl;
        Array<float> tab2(tab1);
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab2[i] << "/";
        std::cout << std::endl <<  "_modifying the values of tab2_" << std::endl;
        tab2[0] = 53.3;
        tab2[1] = 420.69;
        tab2[2] = 505;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab2[i] << "/";
        std::cout << std::endl << "_without modifying the values of tab1_" << std::endl;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab1[i] << "/";
            
        std::cout << std::endl << "_creating tab3_" << std::endl;
        Array<float> tab3(3);
        tab3[0] = 95;
        tab3[1] = 96;
        tab3[2] = 97;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab3[i] << "/";
        std::cout << std::endl << "_copy by operator: tab3 = tab2_" << std::endl;
        tab3 = tab2;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab3[i] << "/";
        std::cout << std::endl << "_modifying the values of tab3_" << std::endl;
        tab3[0] = 345;
        tab3[1] = 456;
        tab3[2] = 567;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab3[i] << "/";
        std::cout << std::endl << "_without modifying the values of tab2_" << std::endl;
        for (int i = 0 ; i < 3 ; i++)
			std::cout << tab2[i] << "/";
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}