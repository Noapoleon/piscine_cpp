/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 14:50:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(void) : _type("divine stick") {}
Weapon::Weapon(const Weapon &copy) : _type(copy._type) {}
Weapon::Weapon(const std::string &type) : _type(type) {}

// Destructors
Weapon::~Weapon(void) {}

// Getters / Setters
const std::string&	Weapon::getType() const
{ return (_type); }
void	Weapon::setType(const std::string &newType)
{ _type = newType; }

// Operators
Weapon& Weapon::operator=(const Weapon &copy)
{
	if (this == &copy)
		return (*this);
	_type = copy._type;
	return (*this);
}
