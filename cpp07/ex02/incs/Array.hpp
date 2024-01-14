/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:50:55 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/14 18:50:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

template < typename T >
class Array
{
public:
	// Constructors
	Array(void) : _arr(NULL), _size(0) {}
	Array(const Array& copy);
	Array(unsigned int n);

	// Destructors
	~Array(void)
	{
		if (_arr)
			delete[] _arr;
	}

	// Operators
	Array&	operator=(const Array& copy);

	// Utils
	unsigned int	size(void);

private:
	T*				_arr;
	unsigned int	_size;
};

#endif // ARRAY_HPP
