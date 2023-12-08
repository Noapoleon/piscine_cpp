/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/08 23:58:52 by nlegrand         ###   ########.fr       */
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
	_val = val << _frac;
}

Fixed::Fixed(float const val)
{
	_val = static_cast<int>(roundf(val * (1 << _frac)));
}

// Destructors
Fixed::~Fixed(void) {}

// Operators
Fixed&	Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		_val = copy._val;
	return (*this);
}

bool	Fixed::operator>(const Fixed& f) const
{
	return (_val > f._val);
}

bool	Fixed::operator<(const Fixed& f) const
{
	return (_val < f._val);
}

bool	Fixed::operator>=(const Fixed& f) const 
{
	return (_val >= f._val);
}

bool	Fixed::operator<=(const Fixed& f) const
{
	return (_val <= f._val);
}

bool	Fixed::operator==(const Fixed& f) const
{
	return (_val == f._val);
}

bool	Fixed::operator!=(const Fixed& f) const
{
	return (_val != f._val);
}

Fixed Fixed::operator+(const Fixed& f) const
{
	return (this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed& f) const
{
	return (this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed& f) const
{
	return (this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f) const
{
	return (this->toFloat() / f.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++_val;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	float const	tmp = this->toFloat();

	++_val;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	--_val;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	float const	tmp = this->toFloat();

	--_val;
	return (tmp);
}

// Utils
int	Fixed::getRawBits(void) const
{
	return (_val);
}

void	Fixed::setRawBits(int const raw)
{
	_val = raw;
}

int		Fixed::toInt(void) const
{
	return (_val >> _frac);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_val) / (1 << _frac));
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

// Stream operators
std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

