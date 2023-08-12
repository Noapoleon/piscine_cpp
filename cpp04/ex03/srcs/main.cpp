/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:39:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 23:32:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

//int	main(void)
//{
//	Character rb("Ritupon Baishya");
//	Character noa("Noa");
//	Character rb2 = rb;
//	AMateria *m1 = new Ice();
//	AMateria *m2 = m1->clone();
//	AMateria *m3 = new Cure();
//	AMateria *m4 = new Cure();
//
//	MateriaSource ms1;
//	ms1.learnMateria(m4);
//	ms1.learnMateria(m1);
//	ms1.learnMateria(m4);
//	ms1.learnMateria(m4);
//	ms1.learnMateria(m4);
//	ms1.displayInfo();
//	ms1.forgetMateria(3);
//	ms1.displayInfo();
//
//	std::cout << std::endl;
//	MateriaSource ms2;
//	ms2.displayInfo();
//	ms2 = ms1;
//	ms2.displayInfo();
//	std::cout << std::endl;
//	MateriaSource ms3 = ms2;
//	ms3.displayInfo();
//	std::cout << std::endl;
//
//	noa.equip(ms1.createMateria("ice"));
//	noa.equip(ms3.createMateria("cure"));
//	noa.equip(ms2.createMateria("caca"));
//
//	m1->use(rb);
//	m2->use(rb);
//	m3->use(rb);
//
//	// equip/unequip
//	std::cout << std::endl;
//	rb.displayInfo();
//	std::cout << std::endl;
//	rb.equip(m1); // equipped in first slot
//	rb.use(0, noa); // uses ice
//	rb.use(1, noa); // uses nothing
//	rb.use(4, noa); // prints error
//	rb.use(-1, noa); // prints error
//	rb.equip(m1); // error already equipped
//	rb.equip(m2); // equipped in second slot
//	rb.unequip(0); // remove Ice from slot 0, sent to trash
//	rb.unequip(3); // nothing in slot yet, so error printed
//	rb.equip(m3); // equip Cure in slot 0
//	rb.equip(m4->clone()); // equip cure clone in slot 2
//	rb.equip(m4->clone()); // equip cure clone in slot 3
//	rb.equip(m4->clone()); // error inv full, deletes ice trash and replaces it with cure
//	rb.displayInfo();
//	rb.use(0, noa); // uses cure
//	rb.use(1, noa); // uses ice
//	std::cout << std::endl;
//
//	// rb copy constructor
//	std::cout << std::endl;
//	rb2.displayInfo();
//	std::cout << std::endl;
//	rb2  = noa;
//	rb2.displayInfo();
//	std::cout << std::endl;
//	rb2 = rb;
//	rb2.displayInfo();
//	std::cout << std::endl;
//
//
//	//delete m1;
//	//delete m2;
//	//delete m3;
//	delete m4;
//	return (0);
//}
