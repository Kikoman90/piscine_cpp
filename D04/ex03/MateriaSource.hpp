/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:32:01 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:11:49 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

    private:
        AMateria    *_mat[4];

        void        _freeMat(void);

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        ~MateriaSource(void);

        MateriaSource       &operator=(MateriaSource const &rhs);

        void                learnMateria(AMateria*);
        AMateria            *createMateria(std::string const &type);

        AMateria            *getMat(int idx) const;
};

#endif