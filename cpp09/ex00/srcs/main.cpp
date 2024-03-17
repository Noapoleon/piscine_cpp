/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:25:25 by noa               #+#    #+#             */
/*   Updated: 2024/03/17 19:45:16 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Missing arguments" << std::endl;
		if (ac == 1)
			std::cerr << "Usage: " << av[0] << " <inputfile>" << std::endl;
		else
			std::cerr << "Usage: btc <inputfile>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange::btc("data.csv", av[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
