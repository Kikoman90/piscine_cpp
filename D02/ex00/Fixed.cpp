/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:17:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/16 15:43:01 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _nbBits(8) {
	
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);

	return ;
}

Fixed::Fixed( Fixed const & src ) : _nbBits(8) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return;
}

int			Fixed::setRawBits( int const raw ) {

	this->_f = raw;
	return (this->_f);
}

int			Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_f);
}

Fixed &		Fixed::operator=( Fixed const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_f = rhs.getRawBits();

	return *this;
}
