/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:27:14 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 19:13:10 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cmath>

class Convert {

    public:

        class NonDisplayableException : public std::exception {

			public:

				NonDisplayableException();
				NonDisplayableException(NonDisplayableException const &src);
				virtual ~NonDisplayableException() throw();

				NonDisplayableException &operator=(NonDisplayableException const &rhs);

				const char              *what() const throw();
                
		};

		class ImpossibleException : public std::exception {

			public:

                ImpossibleException();
				ImpossibleException(ImpossibleException const &src);
				virtual ~ImpossibleException() throw();

				ImpossibleException     &operator=(ImpossibleException const &rhs);

				const char              *what() const throw();

		};

        Convert();
        Convert(Convert const &src);
        ~Convert();

        Convert                         &operator=(Convert const &rhs);

        static int                      getPrecision(char *str);

        static char                     my_dtoc(double d);
        static int                      my_dtoi(double d);
        static float                    my_dtof(double d);
        static double                   my_dtod(double d);

};

#endif