/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:00:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 17:39:41 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("Presidential pardon form", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form("Presidential pardon form", 25, 5)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return ;
}

PresidentialPardonForm       &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

void                        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);

    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}