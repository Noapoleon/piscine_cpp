/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:08:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 22:56:14 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructors
Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure& copy) : AMateria(copy) {}

// Destructors
Cure::~Cure(void) {}

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
	if (tmp == NULL)
		std::cout << AMATERIA_ERROR "Failed to clone " << this->getType() << "materia!" << std::endl;
	return (tmp);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
