/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:08:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 22:55:28 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Constructors
Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(const Ice& copy) : AMateria(copy) {}

// Destructors
Ice::~Ice(void) {}

// Operators
Ice&	Ice::operator=(const Ice& copy)
{
	(void)copy;
	return (*this);
}

// Utils
AMateria*	Ice::clone(void) const
{
	AMateria *tmp = new Ice();
	if (tmp == NULL)
		std::cout << AMATERIA_ERROR "Failed to clone " << this->getType() << "materia!" << std::endl;
	return (tmp);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
