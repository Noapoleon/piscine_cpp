/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/10 15:48:43 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void	truc(int& x)
{
	x += 2;
}

void	show(int& x)
{
	std::cout << x << " ";
}

int main( void )
{
	int	arr1[10];

	std::cout << "Before: ";
	iter(arr1, 10, show);
	std::cout << std::endl;

	iter(arr1, 10, truc);

	std::cout << "After: ";
	iter(arr1, 10, show);
	std::cout << std::endl;
	return (0);
}
