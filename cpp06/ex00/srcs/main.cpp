/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:57 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/11 20:17:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <climits>
#include "ScalarConverter.hpp"

int	main(void)
{
	// ScalarConverter sc1; // Won't compile
	//long	a = 2147483647l * 234234;
	//int		b = a;
	//float	c = 42.0f;
	//double	d = 2147483647;

	//std::cout << "long ---> " << a << std::endl;
	//std::cout << "int ----> " << b << std::endl;
	//std::cout << "float --> " << c << std::endl;
	//std::cout << "double -> " << d << std::endl;

	//std::cout << "double to int -> " << static_cast<int>(b) << std::endl;

	ScalarConverter::convert("a");
	return (0);
}
