/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:14:48 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/16 00:39:27 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructors
template < typename T >
Array<T>::Array(void) : _arr(NULL), _size(0) {}
template < typename T >
Array<T>::Array(const Array<T>& copy) : _arr(NULL), _size(0) { *this = copy; }
template < typename T >
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

// Destructors
template < typename T >
Array<T>::~Array(void)
{
	if (_arr && _size)
		delete[] _arr;
}

// Operators
template < typename T >
Array<T>&	Array<T>::operator=(const Array<T>& copy)
{
	unsigned int copySize = copy.size();

	if (this == &copy)
		return (*this);
	if (_arr && _size)
		delete[] _arr;
	_arr = new T[copySize];
	for (unsigned int i = 0; i < copySize; ++i)
		_arr[i] = copy[i]; // implement [] operator later
	_size = copySize;
	return (*this);
}
template < typename T >
T&	Array<T>::operator[](const unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return (_arr[i]);
}
template < typename T >
const T&	Array<T>::operator[](const unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (_arr[i]);
}

// Utils
template < typename T >
unsigned int	Array<T>::size(void) const
{ return (_size); }
