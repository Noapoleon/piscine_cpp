/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:29:06 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/14 18:44:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Constructors
//template < typename T >
//Array::Array(void) : _arr(NULL), _size(0) {}
//Array::Array(const Array& copy);
//Array::Array(unsigned int n);

// Destructors
//template < typename T >
//Array::~Array(void)
//{
//	if (_arr)
//		delete[] _arr;
//}

// Operators
//Array&	Array::operator=(const Array& copy);

// Utils
template < typename T >
unsigned int	Array::size(void)
{ return (_size); }
