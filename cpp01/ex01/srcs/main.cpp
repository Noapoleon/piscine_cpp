/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:08:02 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/16 19:21:52 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

static void	test(int nZombies)
{
	Zombie	*horde = zombieHorde(nZombies, "roberto");
	if (horde == NULL)
	{
		std::cout << "Failed to allocateo " << nZombies << " zombies!"
			<< std::endl;
		return ;
	}
	for (int i = 0; i < nZombies; ++i)
		horde[i].announce();
	delete[] horde;
}

int	main(void)
{
	test(4);
	std::cout << std::endl;
	test(1);
	std::cout << std::endl;
	test(0);
	std::cout << std::endl;
	test(-1);
	return (0);
}
