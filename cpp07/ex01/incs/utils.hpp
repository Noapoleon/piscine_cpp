/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:15:16 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/13 17:42:43 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "iter.hpp"

template < typename T >
void	print(const T& x)
{
	std::cout << x << " ";
}

template < typename T, typename U >
void	test(T* arr, size_t size, U fun)
{
	static int	testNum;

	std::cout << "Test " << ++testNum << ":" << std::endl;
	std::cout << "Before: ";
	iter(arr, size, print<T>);
	std::cout << std::endl;

	iter(arr, size, fun);

	std::cout << "After: ";
	iter(arr, size, print<T>);
	std::cout << std::endl << std::endl;
}

# endif // UTILS_HPP
