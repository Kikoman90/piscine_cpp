/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecValue.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:37:01 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:41:26 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEC_VALUE_HPP
# define DEC_VALUE_HPP

# include "IInstruction.hpp"

class   DecValue : public IInstruction {

    public:
        DecValue();
        DecValue(DecValue const &src);
        ~DecValue();

        DecValue                                &operator=(DecValue const &rhs);

        IInstruction                            *clone() const;
        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif