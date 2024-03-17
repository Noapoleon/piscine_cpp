/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:54 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/17 19:42:50 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
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

int	main(int ac, char** av)
{
	if (!checkSettings(ac, av))
		return (1);
	try {
		PmergeMe::sort(av[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
