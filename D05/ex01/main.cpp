/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:23:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/05 21:13:01 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
	std::cout << "_testing bureaucrat class and exceptions_" << std::endl;
	try
	{
		Bureaucrat  joel("Joel", 2);
		std::cout << joel;
		joel.incGrade();
		std::cout << joel;
		joel.incGrade();
		std::cout << joel;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	ellie("Ellie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "_testing form class and exceptions_" << std::endl;
	try
	{
		Form	invalid("contract", 50, 170);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Form contract("contract", 50, 25);
	std::cout << contract;
	Bureaucrat dsk("dsk", 10);
	std::cout << dsk;
	dsk.signForm(contract);
	Bureaucrat sarko("sarko", 67);
	std::cout << sarko;
	sarko.signForm(contract);
	
	return (0);
}