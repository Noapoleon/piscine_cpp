/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:46:59 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:21:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors
AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = copy.type;
}
AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria string constructor called" << std::endl;
	this->type = type;
}

// Destructors
AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor called" << std::endl;
}

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
