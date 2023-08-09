/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:46 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:22:14 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	//ClapTrap	t1("Pedro");
	//ScavTrap	t2("Miguel");
	//FragTrap	t3("Javier");

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
	t4.guardGate();
	t4.highFiveGuys();
	t4.takeDamage(500);
	t4.guardGate();
	t4.highFiveGuys();
	t4 = t6;
	t4.guardGate();
	t4.highFiveGuys();
	std::cout << std::endl;

	//t1.attack("Ritupon");
	//t2.attack("Ritupon");
	//t3.attack("Ritupon");
	//t3.takeDamage(-1);
	//t3.beRepaired(33);
	
	const ClapTrap* ct = new DiamondTrap();
	delete ct;
	return (0);
}
