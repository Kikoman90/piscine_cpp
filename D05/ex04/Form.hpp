/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:26:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 18:38:08 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

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
                ~GradeTooHighException() throw();

                GradeTooHighException   &operator=(GradeTooHighException const &rhs);

                char const              *what(void) const throw();

        };

        class GradeTooLowException : public std::exception {

            public:
                GradeTooLowException();
                GradeTooLowException(GradeTooLowException const &src);
                ~GradeTooLowException() throw();

                GradeTooLowException   &operator=(GradeTooLowException const &rhs);

                char const              *what(void) const throw();

        };

        class FormNotSignedException : public std::exception {

            public:
                FormNotSignedException();
                FormNotSignedException(FormNotSignedException const &src);
                ~FormNotSignedException() throw();

                FormNotSignedException  &operator=(FormNotSignedException const &rhs);

                char const              *what(void) const throw();

        };

        Form(const std::string name, int sg, int eg);
        Form(Form const &src);
        ~Form();

        Form                &operator=(Form const &rhs);

        void                beSigned(Bureaucrat const &);
        virtual void        execute(Bureaucrat const & executor) const = 0;

        const std::string   getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getIsSigned() const;

};

std::ostream                &operator<<(std::ostream &o, Form const &rhs);

#endif