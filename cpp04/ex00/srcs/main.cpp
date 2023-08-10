/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:39:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 19:03:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// default tests
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	// wrong varient tests
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();

	std::cout << w_i->getType() << std::endl;
	w_i->makeSound(); //will output the animal sound!
	w_meta->makeSound();

	delete w_meta;
	delete w_i;

	// other tests
	Cat* c1 = new Cat();
	Dog* d1 = new Dog();

	std::cout << c1->getType() << std::endl;
	std::cout << d1->getType() << std::endl;
	c1->makeSound();
	d1->makeSound();

	//c1 = dynamic_cast<Cat *>(d1); // segfault
	//std::cout << "hello world" << std::endl;
	//std::cout << c1->getType() << std::endl;
	//c1->makeSound();


	delete c1;
	delete d1;

	return 0;
}
