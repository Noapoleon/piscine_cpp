/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:44:05 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 18:42:49 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal(void)
{
	std::cout << "\e[38;2;0;255;0mAAnimal\e[0m default \e[34mconstructor\e[0m called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type)
{
	std::cout << "\e[38;2;0;255;0mAAnimal\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
}

// Destructors
AAnimal::~AAnimal(void)
{
	std::cout << "\e[38;2;0;255;0mAAnimal\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
AAnimal&	AAnimal::operator=(const AAnimal& copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

// Utils
std::string	AAnimal::getType(void) const
{
	return (this->type);
}
