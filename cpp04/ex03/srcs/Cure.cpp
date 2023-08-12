/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:08:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:22:13 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructors
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}
Cure::Cure(const Cure& copy) : AMateria(copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

// Destructors
Cure::~Cure(void)
{
	std::cout << "Cure default destructor called" << std::endl;
}

// Operators
Cure&	Cure::operator=(const Cure& copy)
{
	(void)copy;
	return (*this);
}

// Utils
AMateria*	Cure::clone(void) const
{
	AMateria *tmp = new Cure();
	return (tmp);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
