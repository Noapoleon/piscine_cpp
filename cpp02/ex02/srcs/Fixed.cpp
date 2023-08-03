/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/03 17:45:44 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _val(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(int const val)
{
	this->_val = val << this->_frac;
}

Fixed::Fixed(float const val)
{
	this->_val = static_cast<int>(roundf(val * (1 << this->_frac)));
}

// Destructors
Fixed::~Fixed(void) {}

// Operators
Fixed&	Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_val = copy._val;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

bool	operator>(const Fixed& f1, const Fixed& f2)
{
	return (f1._val > f2._val);
}

bool	operator<(const Fixed& f1, const Fixed& f2)
{
	return (f1._val < f2._val);
}

bool	operator>=(const Fixed& f1, const Fixed& f2)
{
	return (f1._val >= f2._val);
}

bool	operator<=(const Fixed& f1, const Fixed& f2)
{
	return (f1._val <= f2._val);
}

bool	operator==(const Fixed& f1, const Fixed& f2)
{
	return (f1._val == f2._val);
}

bool	operator!=(const Fixed& f1, const Fixed& f2)
{
	return (f1._val != f2._val);
}

Fixed operator+(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() + f2.toFloat());
}

Fixed operator-(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() - f2.toFloat());
}

Fixed operator*(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() * f2.toFloat());
}

Fixed operator/(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() / f2.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++(this->_val);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	float const	tmp = this->toFloat();

	++(this->_val);
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	--(this->_val);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	float const	tmp = this->toFloat();

	--(this->_val);
	return (tmp);
}

// Utils
int	Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->_val = raw;
}

int		Fixed::toInt(void) const
{
	return (this->_val >> this->_frac);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_val) / (1 << this->_frac));
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}
