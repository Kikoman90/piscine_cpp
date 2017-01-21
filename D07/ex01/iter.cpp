/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:38:38 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 18:07:01 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename T>
void    iter(T *array, unsigned int length, void (*f)(T const &))
{
    if (array)
    {
        for (unsigned int i = 0 ; i < length ; i++)
            f(array[i]);
    }
}

template<typename T>
void    printElem(T const &elem) { std::cout << elem << " "; }

int     main(void)
{
	int         arrInt[] = {42, 420, 9000, 69};
	std::string arrString[] = {"Ah", "bah", "bravo", "Niels", "!"};

	std::cout << "string: "<< std::endl;
	iter(arrString, 5, printElem);
    std::cout << std::endl << std::endl;

	std::cout << "int array: "<< std::endl;
	iter<int>(arrInt, 4, printElem);
	std::cout << std::endl;

	return (0);
}