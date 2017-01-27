/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncPtr.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:37:46 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:41:39 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_PTR_HPP
# define INC_PTR_HPP

# include "IInstruction.hpp"

class   IncPtr : public IInstruction {

    public:
        IncPtr();
        IncPtr(IncPtr const &src);
        ~IncPtr();

        IncPtr                                  &operator=(IncPtr const &rhs);

        IInstruction                            *clone() const;
        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif