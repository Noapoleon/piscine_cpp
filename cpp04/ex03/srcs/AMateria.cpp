/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:46:59 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 22:11:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors
AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria& copy)
{
	this->type = copy.type;
}
AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

// Destructors
AMateria::~AMateria(void) {}

// Operators
AMateria&	AMateria::operator=(const AMateria& copy)
{
	(void)copy;
	return (*this);
}

// Utils
std::string const & AMateria::getType(void) const // Returns the materia type
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* using abstract materia on " << target.getName() << " *" << std::endl;
}
