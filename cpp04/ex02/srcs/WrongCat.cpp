/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:45 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:01:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "\e[38;2;0;180;70mWrongCat\e[0m default \e[34mconstructor\e[0m called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "\e[38;2;0;180;70mWrongCat\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
	this->type = copy.type;
}

// Destructors
WrongCat::~WrongCat(void)
{
	std::cout << "\e[38;2;0;180;70mWrongCat\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	if (this == &copy)
		return (*this);
	WrongAnimal::operator=(copy);
	return (*this);
}

// Utils
void	WrongCat::makeSound(void) const
{
	std::cout << "*vroom*" << std::endl;
}
