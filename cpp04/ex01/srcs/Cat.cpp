/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:45 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 18:30:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal()
{
	std::cout << "\e[38;2;0;180;70mCat\e[0m default \e[34mconstructor\e[0m called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "\e[38;2;0;180;70mCat\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

// Destructors
Cat::~Cat(void)
{
	if (this->brain)
		delete this->brain;
	std::cout << "\e[38;2;0;180;70mCat\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operator
Cat&	Cat::operator=(const Cat& copy)
{
	if (this == &copy)
		return (*this);
	Animal::operator=(copy);
	if (this->brain && copy.brain)
		*(this->brain) = *(copy.brain);
	return (*this);
}

// Utils
void	Cat::makeSound(void) const
{
	std::cout << "*moew*" << std::endl;
}
