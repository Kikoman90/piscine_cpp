/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:00:03 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 12:13:01 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("shrubbery creation", 145, 137), _target(target)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form("shrubbery creation", 145, 137)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

ShrubberyCreationForm       &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

void                        ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);

    std::ofstream   file;
    std::string     fileName;
    fileName = this->_target;
    fileName += "_shrubbery";
    file.open(fileName);

    file << "      ." << std::endl;
    file << "   __/ \\__" << std::endl;
    file << "   \\     /" << std::endl;
    file << "   /.'o'.\\ " << std::endl;
    file << "    .o.'." << std::endl;
    file << "   .'.'o'." << std::endl;
    file << "  o'.o.'.o." << std::endl;
    file << " .'.o.'.'.o." << std::endl;
    file << ".o.'.o.'.o.'." << std::endl;
    file << "   [_____]" << std::endl;
    file << "    \\___/   ";
    file.close();
}