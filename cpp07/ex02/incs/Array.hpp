/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:50:55 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/19 15:49:26 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

template < typename T >
class Array
{
public:
	// Constructors
	Array(void);
	Array(const Array& copy);
	Array(unsigned int n);

	// Destructors
	~Array(void);

	// Operators
	Array&		operator=(const Array& copy);
	T&			operator[](const unsigned int i);
	const T&	operator[](const unsigned int i) const;

	// Utils
	unsigned int	size(void) const;

private:
	T*				_arr;
	unsigned int	_size;
};

#include "Array.tpp"

#endif // ARRAY_HPP
