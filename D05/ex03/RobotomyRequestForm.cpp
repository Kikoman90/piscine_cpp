/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:27:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 12:12:41 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("robotomy request", 72, 45), _target(target)
{
    std::srand(std::time(NULL));
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form("robotomy request", 72, 45)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

RobotomyRequestForm       &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

void                        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);

    int     i;
    std::cout << "* loud drilling noises *" << std::endl;
    
    i = rand() % 2;
    if (i == 1)
        std::cout << this->_target << "has been robotomized successfully" << std::endl;
    else if (i == 0)
        std::cout << "robotomy of " << this->_target << " has failed" << std::endl;
}