/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:39:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 18:29:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	Animal* tab[100];
	// new
	for (int i = 0; i < 50; ++i)
		tab[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		tab[i] = new Cat();

	*(tab[0]) = *(tab[1]);
	// delete
	for (int i = 0; i < 50; ++i)
		delete tab[i];
	for (int i = 50; i < 100; ++i)
		delete tab[i];

	Dog*	d1 = new Dog();
	Dog*	d2 = new Dog();
	*d1 = *d2;
	delete d1;
	delete d2;

	Cat*	c1 = new Cat();
	Cat*	c2 = new Cat();
	*c1 = *c2;
	delete c1;
	delete c2;

	return 0;
}
