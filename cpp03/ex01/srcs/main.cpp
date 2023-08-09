/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:46 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:17:39 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	st1("Pedro");
	ScavTrap	st2("Miguel");
	ScavTrap	st3;

	st1.beRepaired(3234);
	st1.displayInfo();
	st3.displayInfo();
	st3 = st1;
	st3.displayInfo();

	st1.guardGate();
	st1.displayInfo();
	st1.attack("Ritupon");
	st1.beRepaired(23);
	st2.guardGate();
	st2.takeDamage(-1);
	st2.guardGate();

	ScavTrap st4("Ritu");
	ClapTrap st5("Pon");

	st4.attack("Xavier");
	st5.attack("Niel");

	return (0);
}
