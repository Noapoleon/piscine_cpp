/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:08:02 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 14:05:16 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

static void	test(int nZombies, const std::string& name)
{
	Zombie	*horde = zombieHorde(nZombies, name);
	if (horde == NULL)
	{
		std::cout << "Failed to allocate " << nZombies << " zombies!" << std::endl;
		return ;
	}
	for (int i = 0; i < nZombies; ++i)
		horde[i].announce();
	delete[] horde;
}

int	main(void)
{
	std::cout << "Test 1" << std::endl;
	test(4, "roberto");
	std::cout << std::endl;

	std::cout << "Test 2" << std::endl;
	test(4, "");
	std::cout << std::endl;

	std::cout << "Test 3" << std::endl;
	test(1, "miguel");
	std::cout << std::endl;

	std::cout << "Test 4" << std::endl;
	test(0, "javier");
	std::cout << std::endl;

	std::cout << "Test 5" << std::endl;
	test(-1, "pedro");
	std::cout << std::endl;

	std::cout << "Test 6" << std::endl;
	test(2147483647, "X Æ A-Xii");
	return (0);
}
