/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:39:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:32:16 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void)
{
	Character rb("Ritupon Baishya");
	AMateria *m1 = new Ice();
	AMateria *m2 = m1->clone();
	AMateria *m3 = new Cure();
	AMateria *m4 = new Cure();

	m1->use(rb);
	m2->use(rb);
	m3->use(rb);

	// equip/unequip
	std::cout << std::endl;
	rb.displayInfo();
	std::cout << std::endl;
	rb.equip(m1);
	rb.equip(m1);
	rb.equip(m2);
	rb.unequip(0);
	rb.equip(m3);
	rb.equip(m4->clone());
	rb.equip(m4->clone());
	rb.equip(m4->clone());
	rb.displayInfo();
	std::cout << std::endl;


	//delete m1;
	//delete m2;
	//delete m3;
	delete m4;
	return (0);
}
