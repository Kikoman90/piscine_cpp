/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:12:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/16 15:42:00 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {

	public:

		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &				operator=( Fixed const & rhs );

		int					getRawBits( void ) const;
		int					setRawBits( int const raw );

	private:

		int					_f;
		const int			_nbBits;

};

#endif
