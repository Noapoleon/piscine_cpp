/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/08 23:02:23 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	_val = val << _frac;
}
Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	_val = static_cast<int>(roundf(val * (1 << _frac)));
}

// Destructors
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Operators
void	Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_val = copy.getRawBits();
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

// Stream operators
std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
