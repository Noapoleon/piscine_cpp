/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:25:25 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/02 18:16:54 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed(void);
	Fixed(const Fixed &copy);

	// Destructors
	~Fixed(void);

	// Operators
	void	operator=(const Fixed &copy);

	// Utils
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_val;
	static int const	_frac = 8;
};

#endif
