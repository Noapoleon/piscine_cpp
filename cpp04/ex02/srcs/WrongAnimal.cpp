/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:44:05 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 22:56:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal(void)
{
	std::cout << "\e[38;2;0;255;0mWrongAnimal\e[0m default \e[34mconstructor\e[0m called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type)
{
	std::cout << "\e[38;2;0;255;0mWrongAnimal\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
}

// Destructors
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "\e[38;2;0;255;0mWrongAnimal\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

// Utils
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*breathing wrongly*" << std::endl;
}
