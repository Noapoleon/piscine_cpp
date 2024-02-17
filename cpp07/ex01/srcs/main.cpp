/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 16:31:33 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "utils.hpp"
#include "iter.hpp"

// function pointers
template < typename T >
void	plusTwo(T& x)
{
	x += 2;
}
template < typename T >
void	timesTwo(T& x)
{
	x *= 2;
}
void	rot13(std::string& str)
{
	int	size = str.size();

	for (int i = 0; i < size; ++i)
	{
		if (islower(str[i]))
		{
			if (str[i] + 13 > 'z')
				str[i] = 'a' + (13 - ('z' - str[i]) - 1);
			else
				str[i] += 13;
		}
		if (isupper(str[i]))
		{
			if (str[i] + 13 > 'Z')
				str[i] = 'A' + (13 - ('Z' - str[i]) - 1);
			else
				str[i] += 13;
		}
	}
}

#include <stdio.h>
int main( void )
{
	// Arrays
	int			arr1[5] = {1, 2, 3, 4, 5};
	std::string	arr2[6] = {"bonjour", "coucou", "salut", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "la-la la"};
	float		arr3[3] = {42.0f, 69.0f, 1337.0f};

	// int tests (instantiation of function template)
	test(arr1, 5, plusTwo<int>);
	test(arr1, 5, plusTwo<int>);
	test(arr1, 5, timesTwo<int>);

	// string tests (normal function)
	test(arr2, 6, rot13);
	test(arr2, 6, rot13);

	// float tests
	std::ostream oldState(NULL);
	oldState.copyfmt(std::cout);
	test(arr3, 3, plusTwo<float>);
	std::cout.precision(1);
	std::cout << std::fixed;
	test(arr3, 3, plusTwo<float>);
	std::cout.copyfmt(oldState);
	test(arr3, 3, plusTwo<float>);

	// other
	test(arr2, 6, rot13);
	return (0);
}
