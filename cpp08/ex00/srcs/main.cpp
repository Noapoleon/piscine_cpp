/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:36:36 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 17:53:52 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include "easyfind.hpp"

int	main(void)
{
	// Lists
	std::cout << "\e[32;7;1mLists Tests:\e[0m" << std::endl;
	std::list<int>	l1;
	try {
		std::cout << "Found " << *(easyfind(l1, 23423432)) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "exception thrown in main: " << e.what() << std::endl;
	}
	l1.push_back(42);
	l1.push_back(69);
	l1.push_back(420);
	l1.push_back(1337);
	l1.push_back(69420);
	try {
		std::cout << "Found " << *(easyfind(l1, 42)) << std::endl;
		std::cout << "Found " << *(easyfind(l1, 420)) << std::endl;
		std::cout << "Found " << *(easyfind(l1, 69420)) << std::endl;
		std::cout << "Found " << *(easyfind(l1, 23423432)) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "exception thrown in main: " << e.what() << std::endl;
	}

	// Vector
	std::cout << std::endl << "\e[32;7;1mVectors Tests:\e[0m" << std::endl;
	std::vector<int>	v1;
	try {
		std::cout << "Found " << *(easyfind(v1, 23423432)) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "exception thrown in main: " << e.what() << std::endl;
	}
	v1.push_back(42);
	v1.push_back(69);
	v1.push_back(420);
	v1.push_back(1337);
	v1.push_back(69420);
	try {
		std::cout << "Found " << *(easyfind(v1, 42)) << std::endl;
		std::cout << "Found " << *(easyfind(v1, 420)) << std::endl;
		std::cout << "Found " << *(easyfind(v1, 69420)) << std::endl;
		std::cout << "Found " << *(easyfind(v1, 23423432)) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "exception thrown in main: " << e.what() << std::endl;
	}
	return (0);
}
