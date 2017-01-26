/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:37:18 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:39:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include "IInstruction.hpp"
# include "AffPtr.hpp"
# include "DecPtr.hpp"
# include "IncPtr.hpp"
# include "DecValue.hpp"
# include "IncValue.hpp"
# include "OpenLoop.hpp"
# include "CloseLoop.hpp"

# include <fstream>
# include <sstream>

class   IInstruction;

class   Mindopen {

    public:
        Mindopen(char *str);
        Mindopen(Mindopen const &src);
        ~Mindopen();

        Mindopen                    &operator=(Mindopen const &rhs);

        void                        readStr();
        void                        executeInstructions();

    private:
        Mindopen();

        std::string                 _fileName;
        std::vector<IInstruction*>  _container;

};

#endif