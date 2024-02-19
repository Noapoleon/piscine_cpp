/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:36:06 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 18:48:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Span.hpp"

int	main(void)
{
	// test 1
	std::cout << "\e[32;7;1mTest 1: Subject test\e[0m" << std::endl;
	Span sp = Span(5);

	std::cout << "\e[1;2;4mBefore adding:\e[0m" << std::endl;
	try {
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Fail: " << e.what() << std::endl;
	}


	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "\e[1;2;4mAfter adding:\e[0m" << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
	sp.show();

	std::cout << "\e[1;2;4mSpan full:\e[0m" << std::endl;
	try {
		sp.addNumber(11);
	} catch (const std::exception& e) {
		std::cerr << "Fail: " << e.what() << std::endl;
	}

	// test 2
	std::cout << "\e[32;7;1mTest 2: Worst case scenario (20000)\e[0m" << std::endl;
	Span sp2 = Span(20000);
	try {
		for (int i = 20000; i > 0; --i)
		sp2.addNumber(i);
	} catch (const std::exception& e) {
		std::cerr << "Fail: " << e.what() << std::endl;
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	// sp2.show(); // too much ouput

	return (0);
}

// SUBJECT TEST
//int main()
//{
//	Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//	return 0;
//}
