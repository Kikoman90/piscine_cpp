/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:00:51 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 12:12:25 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("presidential pardon", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form("presidential pardon", 25, 5)
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