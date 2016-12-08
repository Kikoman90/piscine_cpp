/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:18:00 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 15:54:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    return ;
}

Intern::Intern(Intern const &src) {
    *this = src;
}

Intern::~Intern() {
    return ;
}

Intern          &Intern::operator=(Intern const &rhs) {
    (void)rhs;
    return (*this);
}

Form            *Intern::makeForm(std::string const formName, std::string const target)
{
    Form    *creatForm;

    if (formName == "shrubbery creation")
        creatForm = (Form *)new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        creatForm = (Form *)new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        creatForm = (Form *)new PresidentialPardonForm(target);
    else
    {
        throw(InvalidFormNameException::InvalidFormNameException());
        return (NULL);
    }
    std::cout << "intern creates " << creatForm->getName() << std::endl;
    return (creatForm);
}

Intern::InvalidFormNameException::InvalidFormNameException() {
    return ;
}

Intern::InvalidFormNameException::InvalidFormNameException(InvalidFormNameException const &src) {
    *this = src;
}

Intern::InvalidFormNameException::~InvalidFormNameException() throw() {
    return ;
}

Intern::InvalidFormNameException    &Intern::InvalidFormNameException::operator=(InvalidFormNameException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const                  *Intern::InvalidFormNameException::what(void) const throw()
{
    return ("name of form is invalid");
}