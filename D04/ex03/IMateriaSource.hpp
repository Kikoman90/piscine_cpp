/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:30:17 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 17:32:34 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

    public:
        virtual ~IMateriaSource() {}
        virtual void        learnMateria(AMateria *m) = 0;
        virtual AMateria    *createMateria(std::string const & type) = 0;

};

#endif
