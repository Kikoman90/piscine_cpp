/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:26:48 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 18:39:18 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {

    private:
        std::string                 _target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();

        RobotomyRequestForm         &operator=(RobotomyRequestForm const &rhs);

        void                        execute(Bureaucrat const & executor) const;

};

#endif