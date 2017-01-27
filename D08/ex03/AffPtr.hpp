/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AffPtr.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:48:14 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:41:06 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFF_PTR_HPP
# define AFF_PTR_HPP

# include "IInstruction.hpp"

class   AffPtr : public IInstruction {

    public:
        AffPtr();
        AffPtr(AffPtr const &src);
        ~AffPtr();

        AffPtr                                  &operator=(AffPtr const &rhs);

        IInstruction                            *clone() const;
        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif