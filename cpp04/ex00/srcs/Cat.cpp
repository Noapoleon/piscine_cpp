/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:45 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 22:21:25 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal()
{
	std::cout << "\e[38;2;0;180;70mCat\e[0m default \e[34mconstructor\e[0m called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "\e[38;2;0;180;70mCat\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
	this->type = copy.type;
}

// Destructors
Cat::~Cat(void)
{
	std::cout << "\e[38;2;0;180;70mCat\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
Cat&	Cat::operator=(const Cat& copy)
{
	if (this == &copy)
		return (*this);
	Animal::operator=(copy);
	return (*this);
}

// Utils
void	Cat::makeSound(void) const
{
	std::cout << "*moew*" << std::endl;
}
