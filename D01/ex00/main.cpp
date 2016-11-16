/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:40:17 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 13:54:08 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

static void	ponyOnTheHeap(void)
{
	std::cout << "ponyOnTheHeap() begin" << std::endl;
	Pony	*jim = new Pony(1.35, 1, "Jim", "purple");
	jim->displayPonyInfos();
	delete jim;
	std::cout << "ponyOnTheHeap() end" << std::endl;
}

static void	ponyOnTheStack(void)
{
	std::cout << "ponyOnTheStack() begin" << std::endl;
	Pony	robin = Pony(3.50, 2, "Robin", "blond");
	robin.displayPonyInfos();
	std::cout << "ponyOnTheStack() end" << std::endl;
}

int			main(void)
{
	std::cout << "main() begin" << std::endl << std::endl;
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << std::endl << "main() end" << std::endl;
	return (0);
}
