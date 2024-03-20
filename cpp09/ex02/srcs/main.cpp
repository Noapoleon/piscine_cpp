/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:54 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 01:21:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

static bool	checkSettings(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Bad arguments" << std::endl;
		if (ac > 0)
			std::cout << "Usage: " << av[0] << " <num1 num2 ... numN>" << std::endl;
		else
			std::cout << "Usage: PmergeMe <num1 num2 ... numN>" << std::endl;
		return (false);
	}
	return (true);
}

template<typename T>
static void	show(T container)
{
	for (typename T::size_type i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
}

int	main(int ac, char** av)
{
	//time_t time1, time2;
	std::vector<unsigned int>	c1;
	std::deque<unsigned int>	c2;

	if (!checkSettings(ac, av))
		return (1);
	try {
		// time 1
		PmergeMe::sort(av[1], c1);
		// time 2

		//// time 1
		PmergeMe::sort(av[1], c2);
		//// time 2
		

		std::cout << "Before:\t" << av[1] << std::endl;
		std::cout << "After:\t";
		show(c1);
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
