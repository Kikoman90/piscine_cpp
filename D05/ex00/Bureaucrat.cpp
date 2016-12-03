/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:12:31 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/03 17:29:00 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

Bureaucrat          &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

void                Bureaucrat::incGrade()
{
    if ((_grade - 1) < 1)
        throw (Bureaucrat::GradeTooHighException());
    _grade -= 1;
}

void                Bureaucrat::decGrade()
{
    if ((_grade + 1) > 150)
        throw (Bureaucrat::GradeTooLowException());
    _grade += 1;
}

std::string const   Bureaucrat::getName() const
{
    return (this->_name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream        &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
    *this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
    return ;
}

Bureaucrat::GradeTooHighException   &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade of bureaucrat is too high!");
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
    *this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
    return ;
}

Bureaucrat::GradeTooLowException   &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade of bureaucrat is too low!");
}