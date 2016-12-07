/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:59:18 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/07 17:38:32 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {

    private:
        std::string                 _target;
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();

        PresidentialPardonForm       &operator=(PresidentialPardonForm const &rhs);

        void                        execute(Bureaucrat const &executor) const;

};

#endif