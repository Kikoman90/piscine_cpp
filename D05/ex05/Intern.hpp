/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:10:09 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 19:10:06 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {

    public:
        
        class InvalidFormNameException : public std::exception {

            public:
                InvalidFormNameException();
                InvalidFormNameException(InvalidFormNameException const &src);
                virtual ~InvalidFormNameException() throw();

                InvalidFormNameException    &operator=(InvalidFormNameException const &rhs);

                char const                  *what(void) const throw();

        };

        Intern();
        Intern(Intern const &src);
        ~Intern();

        Intern      &operator=(Intern const &rhs);

        Form        *makeForm(std::string const formName, std::string const target);
        
};

#endif