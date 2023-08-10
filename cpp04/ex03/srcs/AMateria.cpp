/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:46:59 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 23:04:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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
	if (this == &copy)
		return (*this);
	//this->type = copy.type;
	return (*this);
}

// Utils
std::string const & AMateria::getType(void) const // Returns the materia type
{
	return (this->type);
}

//void	AMateria::use(ICharacter& target)
void	AMateria::use(std::string target)
{

	std::cout << "* cant use " <<  this->type << " on " << target
		<< std::endl;
	//std::cout << "* cant use " <<  this->type << " on " << target.getName()
	//	<< std::endl;
}
