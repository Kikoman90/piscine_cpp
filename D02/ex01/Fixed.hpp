/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:12:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/16 17:15:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

	public:

		Fixed( void );
		Fixed( int const nb );
		Fixed( float const nb );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &				operator=( Fixed const & rhs );

		int					toInt( void ) const;
		float				toFloat( void ) const;

		int					getRawBits( void ) const;
		int					setRawBits( int const raw );

	private:

		int					_f;
		const int			_nbBits;

};

std::ostream & operator<<( std::ostream & o, Fixed const &rhs );

#endif
