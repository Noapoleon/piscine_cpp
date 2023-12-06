/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:49:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 17:59:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac > 2 || (ac == 2 &&
		(std::string(av[1]) != "DEBUG"
		 && std::string(av[1]) != "INFO"
		 && std::string(av[1]) != "WARNING"
		 && std::string(av[1]) != "ERROR")))
	{
		std::cout << "Usage: " << av[0] << " [DEBUG | INFO | WARNING | ERROR]"
			<< std::endl;
		return (1);
	}

	if (ac == 2) // av[1] test
		harl.complain(std::string(av[1]));
	else if (ac != 2) // automated test
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	harl.complain("lalala\n"); // wont print anything
	return (0);
}
