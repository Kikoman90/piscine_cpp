/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:17:08 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/16 18:00:14 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>

Fixed::Fixed( void ) : _nbBits(8) {

	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);

	return ;
}

Fixed::Fixed( int const nb ) : _nbBits(8) {

	std::cout << "Int constructor called" << std::endl;
	this->_f = nb << this->_nbBits;

	return ;
}

Fixed::Fixed( float const nb ) : _nbBits(8) {

	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(nb * (1 << this->_nbBits)));

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

float		Fixed::toFloat( void ) const {

	return ((float) (this->_f) / (1 << this->_nbBits));
}

int			Fixed::toInt( void ) const {

	return (this->_f >> this->_nbBits);
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

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs) {

	o << rhs.toFloat();

	return (o);
}

bool Fixed::operator>(Fixed const & rhs)
{
	return (this->_f > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs)
{
	return (this->_f < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs)
{
	return (this->_f >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs)
{
	return (this->_f <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs)
{
	return (this->_f == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs)
{
	return (this->_f != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed & Fixed::operator++()
{
	++(this->_f);
	return *this;
}

Fixed & Fixed::operator--()
{
	--(this->_f);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return old;
}

Fixed Fixed::max(Fixed const & a, Fixed const & b)
{
	return (((a.toFloat() > b.toFloat()) ? a : b));
}

Fixed Fixed::min(Fixed const & a, Fixed const & b)
{
	return (((a.toFloat() > b.toFloat()) ? b : a));
}
