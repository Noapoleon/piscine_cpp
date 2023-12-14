/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:46 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 14:21:43 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap t4("Roberto");
	DiamondTrap t5(t4);
	DiamondTrap t6;
	t4.attack("Ritupon Baishya");
	t4.whoAmI();
	t5.attack("Ritupon Baishya");
	t5.whoAmI();
	t6.attack("Ritupon Baishya");
	t6.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;
	t4.displayInfo();
	t5.displayInfo();
	t6.displayInfo();
	std::cout << std::endl;
	std::cout << std::endl;

	t4.guardGate();
	t4.highFiveGuys();
	t4.takeDamage(99);
	t4.beRepaired(20);
	t4.guardGate();
	t4.highFiveGuys();
	t4.guardGate();
	t4.highFiveGuys();

	std::cout << std::endl;
	t4.displayInfo();
	t5.displayInfo();
	t6 = t4;
	t6.displayInfo();
	std::cout << std::endl;
	std::cout << std::endl;
	
	ClapTrap* ct = new DiamondTrap();
	ct->attack("Bonjouj");
	delete ct;
	return (0);
}
