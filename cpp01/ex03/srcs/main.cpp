/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:59:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 18:08:44 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//int	main(void)
//{
//	// Weapon tests
//	Weapon w1;
//	w1.setType("bow");
//
//	Weapon w2(w1);
//	std::cout << "w2 is " << w2.getType() << std::endl;
//
//	Weapon w3("sword");
//	std::cout << "w3 is " << w3.getType() << std::endl;
//
//	Weapon w4;
//	std::cout << "w4 is " << w3.getType() << std::endl;
//
//	//// Human tests
//	HumanA h1("bob", w1);
//	HumanA h2(h1);
//	HumanA h3("larry", w3);
//	HumanA h4("larry", w4);
//	
//	h1.attack();
//	h2.attack();
//	h3.attack();
//	h4.attack();
//	return (0);
//}


int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
