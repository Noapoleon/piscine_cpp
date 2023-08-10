/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:09:41 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 21:57:54 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain(void)
{
	std::cout << "\e[35mBrain\e[0m default \e[34mconstructor\e[0m called" << std::endl;
}
Brain::Brain(const Brain& copy)
{
	std::cout << "\e[35mBrain\e[0m copy \e[34mconstructor\e[0m called" << std::endl;
	*this = copy;
}

// Destructors
Brain::~Brain(void)
{
	std::cout << "\e[35mBrain\e[0m default \e[31mdestructor\e[0m called" << std::endl;
}

// Operators
Brain& Brain::operator=(const Brain& copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < BRAIN_CAPACITY; ++i)
	{
		this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}
