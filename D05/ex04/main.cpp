/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:23:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 15:52:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
	Intern      idiotOne;
    Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 7);
    Bureaucrat  bob = Bureaucrat("Bobby Bobson", 80);
	Bureaucrat	jim = Bureaucrat("Jimmy Neutron", 20);
    OfficeBlock ob;

	std::cout << "_empty office block_" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "elysee");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(idiotOne);
	std::cout << std::endl << "_missing signer in the office block_" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "elysee");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    ob.setSigner(bob);
	std::cout << std::endl << "_missing executor in the office block_" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "elysee");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
    ob.setExecutor(hermes);
	std::cout << std::endl << "_perfect bureaucracy_" << std::endl;
	try 
	{
		ob.doBureaucracy("shrubbery creation", "elysee");
    }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "_invalid form_" << std::endl;
	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "_signer grade too low_" << std::endl;
	try
	{
		ob.doBureaucracy("robotomy request", "snake");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setSigner(jim);
	std::cout << std::endl << "_executor grade too low_" << std::endl;
	try
	{
		ob.doBureaucracy("presidential pardon", "leonarda(mdr)");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}