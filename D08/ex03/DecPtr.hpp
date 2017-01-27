/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecPtr.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:35:09 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:41:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEC_PTR_HPP
# define DEC_PTR_HPP

# include "IInstruction.hpp"

class   DecPtr : public IInstruction {

    public:
        DecPtr();
        DecPtr(DecPtr const &src);
        ~DecPtr();

        DecPtr                                  &operator=(DecPtr const &rhs);

        IInstruction                            *clone() const;
        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif