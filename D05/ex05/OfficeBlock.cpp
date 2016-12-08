/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:22:11 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 17:52:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(NULL), _signer(NULL), _executor(NULL)
{
    return ;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) : _intern(intern), _signer(signer), _executor(executor)
{
    return ;
}

OfficeBlock::~OfficeBlock()
{
    return ;
}

OfficeBlock     &OfficeBlock::operator=(OfficeBlock const &rhs)
{
    if (this != &rhs)
    {
        _intern = rhs._intern;
        _signer = rhs._signer;
        _executor = rhs._executor;
    }
    return (*this);
}

void            OfficeBlock::setIntern(Intern &ntrn)
{
    _intern = &ntrn;
}

void            OfficeBlock::setSigner(Bureaucrat &sgnr)
{
    _signer = &sgnr;
}

void            OfficeBlock::setExecutor(Bureaucrat &xctr)
{
    _executor = &xctr;
}

void            OfficeBlock::doBureaucracy(std::string const formName, std::string const target) const
{
    Form    *forml;
    
    if (!_intern)
        throw (NoInternException::NoInternException());
    if (!_signer)
        throw (NoSignerException::NoSignerException());
    if (!_executor)
        throw (NoExecutorException::NoExecutorException());

    try
    {
        forml = _intern->makeForm(formName, target);
    }
    catch (std::exception &e)
    {
        std::cout << "intern cannot create form because " << e.what() << std::endl;
        throw (BureaucracyFailedException::BureaucracyFailedException());
    }

    try
    {
        _signer->signForm(*forml);
    }
    catch (std::exception &e)
    {
        std::cout << "signer " << _signer->getName() << " cannot sign form because " <<e.what() << std::endl;
    }

    try
    {
        _executor->executeForm(*forml);
    }
    catch (std::exception &e)
    {
        std::cout << "executor " << _executor->getName() << " cannot execute form because " << e.what() << std::endl;
        throw (BureaucracyFailedException::BureaucracyFailedException());
    }
}

OfficeBlock::NoInternException::NoInternException() {
    return ;
}

OfficeBlock::NoInternException::NoInternException(OfficeBlock::NoInternException const &src) {
    *this = src;
}

OfficeBlock::NoInternException::~NoInternException() throw() {
    return ;
}

OfficeBlock::NoInternException  &OfficeBlock::NoInternException::operator=(OfficeBlock::NoInternException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const                      *OfficeBlock::NoInternException::what(void) const throw()
{
    return ("Missing intern in the office block");
}

OfficeBlock::NoSignerException::NoSignerException() {
    return ;
}

OfficeBlock::NoSignerException::NoSignerException(OfficeBlock::NoSignerException const &src) {
    *this = src;
}

OfficeBlock::NoSignerException::~NoSignerException() throw() {
    return ;
}

OfficeBlock::NoSignerException  &OfficeBlock::NoSignerException::operator=(OfficeBlock::NoSignerException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const                      *OfficeBlock::NoSignerException::what(void) const throw()
{
    return ("Missing signer in the office block");
}

OfficeBlock::NoExecutorException::NoExecutorException() {
    return ;
}

OfficeBlock::NoExecutorException::NoExecutorException(OfficeBlock::NoExecutorException const &src) {
    *this = src;
}

OfficeBlock::NoExecutorException::~NoExecutorException() throw() {
    return ;
}

OfficeBlock::NoExecutorException    &OfficeBlock::NoExecutorException::operator=(OfficeBlock::NoExecutorException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const                          *OfficeBlock::NoExecutorException::what(void) const throw()
{
    return ("Missing executor in the office block");
}

OfficeBlock::BureaucracyFailedException::BureaucracyFailedException() {
    return ;
}

OfficeBlock::BureaucracyFailedException::BureaucracyFailedException(OfficeBlock::BureaucracyFailedException const &src) {
    *this = src;
}

OfficeBlock::BureaucracyFailedException::~BureaucracyFailedException() throw() {
    return ;
}

OfficeBlock::BureaucracyFailedException    &OfficeBlock::BureaucracyFailedException::operator=(OfficeBlock::BureaucracyFailedException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const                  *OfficeBlock::BureaucracyFailedException::what(void) const throw()
{
    return ("A problem occured in the bureaucracy process...");
}