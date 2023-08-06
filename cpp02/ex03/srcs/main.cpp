/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:34:07 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/06 16:15:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	//tri 1
	Point	tri1_1(0.0f, 0.0f);
	Point	tri1_2(5.0f, 0.0f);
	Point	tri1_3(0.0f, 5.0f);

	Point	test_1(1.0f, 1.0f); // true
	Point	test_2(0.0f, 0.0f); // false
	Point	test_3(5.0f, 0.0f); // false
	Point	test_4(2.5f, 0.0f); // false

	std::cout << "test 1 -> " << bsp(test_1, tri1_1, tri1_2, tri1_3) << std::endl;
	std::cout << "test 2 -> " << bsp(test_2, tri1_1, tri1_2, tri1_3) << std::endl;
	std::cout << "test 3 -> " << bsp(test_3, tri1_1, tri1_2, tri1_3) << std::endl;
	std::cout << "test 4 -> " << bsp(test_4, tri1_1, tri1_2, tri1_3) << std::endl;
	return (0);
}
