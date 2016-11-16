/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:01:31 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 22:04:55 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

void	catFromInput(void)
{
	std::string	line;

	while (true)
	{
		std::getline(std::cin, line);
		std::cout << line << std::endl;
	}
}

void	catFromFile(char *argv)
{
	std::stringstream	sstr;
	std::string			str;
	sstr << argv;
	str = sstr.str();

	std::ifstream		file;
	file.open(str);
	sstr.str(std::string());
	sstr << file.rdbuf();
	std::cout << sstr.str();
}

//void	catInputToFile();

int		main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		catFromInput();
	else
	{
		while (i < argc)
		{
			catFromFile(argv[i]);
			i++;
		}
	}
	return (0);	
}
