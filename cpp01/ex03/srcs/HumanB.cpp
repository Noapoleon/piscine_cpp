/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 16:24:43 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructors
HumanB::HumanB(const HumanB &copy) :
	_name(copy._name),
	_weapon(copy._weapon) {}
HumanB::HumanB(const std::string& name) :
	_name(name),
	_weapon(NULL) {}

// Destructors
HumanB::~HumanB(void) {}

// Operators
HumanB&	HumanB::operator=(const HumanB &copy)
{
	if (this == &copy)
		return (*this);
	_name = copy._name;
	_weapon = copy._weapon; // not a deep copy but should be fine for this exercise
	return (*this);
}

// Utils
void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " holds no weapon and failed to attack" << std::endl;
}
void	HumanB::setWeapon(Weapon& w)
{ _weapon = &w; }
//{ _weapon = static_cast<Weapon *>(&w); }
