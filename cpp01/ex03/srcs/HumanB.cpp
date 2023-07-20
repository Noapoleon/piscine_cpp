/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 18:34:47 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructors
HumanB::HumanB(void)
{
	this->_weapon = NULL;
}
HumanB::HumanB(const HumanB &copy)
{
	this->_name = copy._name;
	this->_weapon = copy._weapon;
}
HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}
HumanB::HumanB(std::string name, Weapon *weapon)
{
	this->_name = name;
	this->_weapon = weapon;
}

// Destructors
HumanB::~HumanB(void) {}

// Operators
void	HumanB::operator=(const HumanB &copy)
{
	this->_name = copy._name;
	this->_weapon = copy._weapon;
}

// Utils
void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
}
void	HumanB::setWeapon(const Weapon &w)
{
	this->_weapon = (Weapon *)&w;
}
