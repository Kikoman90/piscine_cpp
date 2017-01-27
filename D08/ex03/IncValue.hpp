/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncValue.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:38:49 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:41:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_VALUE_HPP
# define INC_VALUE_HPP

# include "IInstruction.hpp"

class   IncValue : public IInstruction {

    public:
        IncValue();
        IncValue(IncValue const &src);
        ~IncValue();

        IncValue                                &operator=(IncValue const &rhs);

        IInstruction                            *clone() const;
        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **Value) const;

};

#endif