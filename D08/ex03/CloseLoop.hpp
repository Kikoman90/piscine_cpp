/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CloseLoop.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:51:14 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:02:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_LOOP_HPP
# define CLOSE_LOOP_HPP

# include "IInstruction.hpp"
# include "OpenLoop.hpp"

class   CloseLoop : public IInstruction {

    public:
        CloseLoop();
        CloseLoop(CloseLoop const &src);
        ~CloseLoop();

        CloseLoop                               &operator=(CloseLoop const &rhs);

        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif