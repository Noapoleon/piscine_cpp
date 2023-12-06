/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:49:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 18:27:04 by nlegrand         ###   ########.fr       */
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

	harl.complain(std::string(av[1]));
	return (0);
}
