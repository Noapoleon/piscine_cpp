/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:44:05 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 22:25:13 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal(void)
{
	std::cout << "\e[38;2;0;255;0mAnimal\e[0m default \e[34mconstructor\e[0m called" << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type)
{
	std::cout << "\e[38;2;0;255;0mAnimal\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
}

// Destructors
Animal::~Animal(void)
{
	std::cout << "\e[38;2;0;255;0mAnimal\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
Animal&	Animal::operator=(const Animal& copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

// Utils
std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*breathing*" << std::endl;
}
