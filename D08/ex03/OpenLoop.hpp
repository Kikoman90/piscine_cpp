/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenLoop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:48 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:03:08 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_LOOP_HPP
# define OPEN_LOOP_HPP

# include "IInstruction.hpp"
# include "CloseLoop.hpp"

class   OpenLoop : public IInstruction {

    public:
        OpenLoop();
        OpenLoop(OpenLoop const &src);
        ~OpenLoop();

        OpenLoop                                &operator=(OpenLoop const &rhs);

        std::vector<IInstruction*>::iterator    execute(std::vector<IInstruction*>::iterator &it,
            std::vector<IInstruction*> &c, char **ptr) const;

};

#endif