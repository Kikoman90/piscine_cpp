/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:23:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 19:05:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
	std::cout << "_creating the 3 different forms_" << std::endl;
	ShrubberyCreationForm	shrubbery_form("elysee");
	RobotomyRequestForm		robotomy_form("Patrick");
	PresidentialPardonForm	presidential_form("DSK");
	Bureaucrat				president("president", 1);
	Bureaucrat				premier_ministre("1er ministre", 50);
	Bureaucrat				stagiaire("stagiaire", 146);

	std::cout << "_signing and executing PresidentialPardonForm_" << std::endl;
	try
	{
		std::cout << presidential_form;
		std::cout << president;
		president.executeForm(presidential_form);
		president.signForm(presidential_form);
		president.executeForm(presidential_form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "_signing and executing RobotomyRequestForm_" << std::endl;
	try
	{
		std::cout << robotomy_form;
		std::cout << premier_ministre;
		premier_ministre.signForm(robotomy_form);
		premier_ministre.executeForm(robotomy_form);
		president.executeForm(robotomy_form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "_signing and executing ShrubberyCreationForm_" << std::endl;
	try
	{
		std::cout << shrubbery_form;
		std::cout << stagiaire;
		stagiaire.signForm(shrubbery_form);
		premier_ministre.signForm(shrubbery_form);
		premier_ministre.executeForm(shrubbery_form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}