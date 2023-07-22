/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:49:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/22 14:36:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " [DEBUG | INFO | WARNING | ERROR]"
			<< std::endl;
		return (1);
	}

	harl.setLevel(std::string(av[1]));
	if (harl.getLevel() == 0)
		return (std::cout << "[ Probably complaining about unsignificant problems ]" << std::endl, 0);
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}
