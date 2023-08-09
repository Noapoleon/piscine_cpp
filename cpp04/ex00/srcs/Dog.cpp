/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:45 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 22:38:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal()
{
	std::cout << "\e[38;2;70;180;0mDog\e[0m default \e[34mconstructor\e[0m called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "\e[38;2;70;180;0mDog\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
	this->type = copy.type;
}

// Destructors
Dog::~Dog(void)
{
	std::cout << "\e[38;2;70;180;0mDog\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
Dog&	Dog::operator=(const Dog& copy)
{
	if (this == &copy)
		return (*this);
	Animal::operator=(copy);
	return (*this);
}

// Utils
void	Dog::makeSound(void) const
{
	std::cout << "*woof*" << std::endl;
}
