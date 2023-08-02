/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/02 18:15:58 by nlegrand         ###   ########.fr       */
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
Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_val = val << this->_frac;
}
Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(val * (1 << this->_frac));
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
		this->_val = copy.getRawBits();
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

// Stream operators
std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
