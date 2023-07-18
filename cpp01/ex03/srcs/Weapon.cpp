/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 19:16:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(void)
{
	this->_type = "divine stick";
}
Weapon::Weapon(Weapon &copy)
{
	this->_type = copy._type;
}
Weapon::Weapon(const std::string &type)
{
	this->_type = type;
}

// Destructors
Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor called" << std::endl;
}

// Getters / Setters
const std::string	&Weapon::getType() const
{
	return (this->_type);
}
void	Weapon::setType(const std::string &newType)
{
	this->_type = newType;
}

// Operators
void	Weapon::operator=(const Weapon &copy)
{
	this->_type = copy._type;
}
