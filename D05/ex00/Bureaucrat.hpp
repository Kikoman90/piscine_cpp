/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:41:46 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 19:06:38 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {

    private:
        Bureaucrat();

        const std::string   _name;
        int                 _grade;

    public:
        class GradeTooHighException : public std::exception {

            public:
                GradeTooHighException();
                GradeTooHighException(GradeTooHighException const &src);
                virtual ~GradeTooHighException() throw();

                GradeTooHighException   &operator=(GradeTooHighException const &rhs);

                char const              *what(void) const throw();

        };
        class GradeTooLowException : public std::exception {

            public:
                GradeTooLowException();
                GradeTooLowException(GradeTooLowException const &src);
                virtual ~GradeTooLowException() throw();

                GradeTooLowException   &operator=(GradeTooLowException const &rhs);

                char const              *what(void) const throw();

        };
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();

        Bureaucrat          &operator=(Bureaucrat const &rhs);

        void                incGrade();
        void                decGrade();

        std::string const   getName() const;
        int                 getGrade() const;

};

std::ostream                &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif