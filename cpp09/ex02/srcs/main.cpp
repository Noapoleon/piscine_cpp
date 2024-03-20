/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:54 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 22:43:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <ctime>
#include "PmergeMe.hpp"

static bool	checkSettings(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Bad arguments" << std::endl;
		if (ac > 0)
			std::cout << "Usage: " << av[0] << " <num1> <num2> ... <numN>" << std::endl;
		else
			std::cout << "Usage: PmergeMe <num1> <num2> ... <numN>" << std::endl;
		return (false);
	}
	return (true);
}

template<typename T>
static void	showOrdered(T container)
{
	for (typename T::size_type i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
}

static void	makeString(std::string& str, int ac, char** av)
{
	for (int i = 1; i < ac; ++i)
	{
		str += av[i];
		str += ' ';
	}
}

static void	showTimings(clock_t time1, clock_t time2, std::vector<unsigned int>::size_type size)
{
	clock_t		smallest = (time1 < time2) ? time1 : time2;
	clock_t		precision = (static_cast<double>(smallest) /
							static_cast<double>(CLOCKS_PER_SEC) < 0.001)
							? 1000000 : 1000;
	std::string	unit = (precision == 1000) ? " ms" : " us" ;

	std::cout << "Time to process a range of " << size << " elements with std::vector : ";
	std::cout << static_cast<double>(time1) / (static_cast<double>(CLOCKS_PER_SEC / precision));
	std::cout << unit << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque  : ";
	std::cout << static_cast<double>(time2) / (static_cast<double>(CLOCKS_PER_SEC / precision));
	std::cout << unit << std::endl;
}

int	main(int ac, char** av)
{
	// info
	clock_t		time1;
	clock_t		time2;
	clock_t		start;
	std::string	str;
	
	// containers
	std::vector<unsigned int>	c1;
	std::deque<unsigned int>	c2;

	if (!checkSettings(ac, av))
		return (1);
	try {
		// format inputs
		makeString(str, ac, av);

		// Vector
		start = clock();
		PmergeMe::sort(str, c1);
		time1 = clock() - start;

		// Deque
		start = clock();
		PmergeMe::sort(str, c2);
		time2 = clock() - start;

		// Before
		std::cout << "Before:\t";
		for (int i = 1; i < ac; ++i)
			std::cout << av[i] << " ";
		std::cout << std::endl;
		// After
		std::cout << "After:\t";
		showOrdered(c1);
		std::cout << std::endl;
		// Timings
		showTimings(time1, time2, c1.size());
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
