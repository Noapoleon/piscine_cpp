/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:09:32 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/18 17:36:07 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <stdexcept>

int	rpn(const std::string& format)
{
	//long			res = 0;
	//std::stack<
	std::cout << format << std::endl;
	for 
	return (0);
}

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
		rpn(av[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (rpn(av[1]));
}
