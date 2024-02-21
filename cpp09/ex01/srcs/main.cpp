/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:09:32 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/21 01:40:39 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Missing arguments" << std::endl;
		if (ac == 1)
			std::cerr << "Usage: " << av[0] << " <formula>" << std::endl;
		else
			std::cerr << "Usage: RPN <formula>" << std::endl;
		return (1);
	}
	try {
		std::cout << RPN::rpn(av[1]) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
