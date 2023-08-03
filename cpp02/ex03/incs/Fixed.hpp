/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:25:25 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/03 17:41:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	// Constructors
	Fixed(void);
	Fixed(const Fixed& copy);
	Fixed(int const val);
	Fixed(float const val);

	// Destructors
	~Fixed(void);

	// Operators
	Fixed&					operator=(const Fixed& copy);
	friend std::ostream&	operator<<(std::ostream& os, const Fixed& f);
	friend bool				operator>(const Fixed& f1, const Fixed& f2);
	friend bool				operator<(const Fixed& f1, const Fixed& f2);
	friend bool				operator>=(const Fixed& f1, const Fixed& f2);
	friend bool				operator<=(const Fixed& f1, const Fixed& f2);
	friend bool				operator==(const Fixed& f1, const Fixed& f2);
	friend bool				operator!=(const Fixed& f1, const Fixed& f2);
	friend Fixed			operator+(const Fixed& f1, const Fixed& f2);
	friend Fixed			operator-(const Fixed& f1, const Fixed& f2);
	friend Fixed			operator*(const Fixed& f1, const Fixed& f2);
	friend Fixed			operator/(const Fixed& f1, const Fixed& f2);
	Fixed&					operator++(void);
	Fixed					operator++(int);
	Fixed&					operator--(void);
	Fixed					operator--(int);

	// Utils
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
	static Fixed&		min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&		max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
	//Fixed&	min(const Fixed& f1, const Fixed& f2) const;

private:
	int					_val;
	static int const	_frac = 8;
};

#endif
