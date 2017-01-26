/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:24:50 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:01:53 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_INSTRUCTION_HPP
# define I_INSTRUCTION_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <vector>

class   IInstruction {

    public:
        virtual                                         ~IInstruction() {}
        
        virtual std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const = 0;

};

#endif