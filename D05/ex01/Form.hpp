/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:26:23 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 19:07:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        Form();

        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _isSigned;

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

        Form(const std::string name, int sg, int eg);
        Form(Form const &src);
        ~Form();

        Form                &operator=(Form const &rhs);

        void                beSigned(Bureaucrat const &);

        const std::string   getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getIsSigned() const;

};

std::ostream                &operator<<(std::ostream &o, Form const &rhs);

#endif