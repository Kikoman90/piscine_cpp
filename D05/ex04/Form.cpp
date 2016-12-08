/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:49:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 18:38:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int sg, int eg) : _name(name), _signGrade(sg), _execGrade(eg), _isSigned(false)
{
    if (sg < 1 || eg < 1)
        throw (Form::GradeTooHighException());
    if (sg > 150 || eg > 150)
        throw (Form::GradeTooLowException());
}

Form::Form(Form const &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
    *this = src;
}

Form::~Form()
{
    return ;
}

Form                &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs.getIsSigned();
    return (*this);
}

void                Form::beSigned(Bureaucrat const &bur)
{
    if (bur.getGrade() > this->_signGrade)
        throw (GradeTooLowException());
    this->_isSigned = true;
}

void                Form::execute(Bureaucrat const & executor) const
{
    if (this->_isSigned == false)
        throw(FormNotSignedException::FormNotSignedException());
    if (executor.getGrade() > this->_execGrade)
        throw(GradeTooLowException::GradeTooLowException());
}

const std::string   Form::getName() const
{
    return (this->_name);
}

int                 Form::getSignGrade() const
{
    return (this->_signGrade);
}

int                 Form::getExecGrade() const
{
    return (this->_execGrade);
}

bool                Form::getIsSigned() const
{
    return (this->_isSigned);
}

std::ostream        &operator<<(std::ostream &o, Form const &rhs)
{
    o << "<form> " << rhs.getName() << " <grade to be signed> " << rhs.getSignGrade() << " <grade to be executed> " << rhs.getExecGrade() << std::endl;
    return o;
}

Form::FormNotSignedException::FormNotSignedException()
{
    return ;
}

Form::FormNotSignedException::FormNotSignedException(FormNotSignedException const &src)
{
    *this = src;
}

Form::FormNotSignedException::~FormNotSignedException() throw()
{
    return ;
}

Form::FormNotSignedException   &Form::FormNotSignedException::operator=(FormNotSignedException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::FormNotSignedException::what() const throw()
{
	return ("form must be signed before it can be executed!");
}

Form::GradeTooHighException::GradeTooHighException()
{
    return ;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
    *this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
    return ;
}

Form::GradeTooHighException   &Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade of form is too high!");
}

Form::GradeTooLowException::GradeTooLowException()
{
    return ;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
    *this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
    return ;
}

Form::GradeTooLowException   &Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade of form is too low!");
}