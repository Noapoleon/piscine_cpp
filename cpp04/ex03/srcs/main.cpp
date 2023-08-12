/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:39:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:39:27 by nlegrand         ###   ########.fr       */
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
	Character noa("Noa");
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
	rb.equip(m1); // equipped in first slot
	rb.use(0, noa); // uses ice
	rb.use(1, noa); // uses nothing
	rb.use(4, noa); // prints error
	rb.use(-1, noa); // prints error
	rb.equip(m1); // error already equipped
	rb.equip(m2); // equipped in second slot
	rb.unequip(0); // remove Ice from slot 0, sent to trash
	rb.unequip(3); // nothing in slot yet, so error printed
	rb.equip(m3); // equip Cure in slot 0
	rb.equip(m4->clone()); // equip cure clone in slot 2
	rb.equip(m4->clone()); // equip cure clone in slot 3
	rb.equip(m4->clone()); // error inv full, deletes ice trash and replaces it with cure
	rb.displayInfo();
	rb.use(0, noa); // uses cure
	rb.use(1, noa); // uses ice
	std::cout << std::endl;


	//delete m1;
	//delete m2;
	//delete m3;
	delete m4;
	return (0);
}
