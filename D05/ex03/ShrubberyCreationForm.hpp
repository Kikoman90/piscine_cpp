/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:55:03 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 18:39:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {

    private:
        std::string                 _target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm       &operator=(ShrubberyCreationForm const &rhs);

        void                        execute(Bureaucrat const & executor) const;

};

#endif