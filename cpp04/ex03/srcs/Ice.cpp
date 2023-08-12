/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:08:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:22:27 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Constructors
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}
Ice::Ice(const Ice& copy) : AMateria(copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

// Destructors
Ice::~Ice(void)
{
	std::cout << "Ice default destructor called" << std::endl;
}

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
	return (tmp);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
