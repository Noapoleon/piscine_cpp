/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 15:26:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors
HumanA::HumanA(const HumanA &copy) :
	_name(copy._name),
	_weapon(copy._weapon) {}
HumanA::HumanA(const std::string& name, const Weapon& weapon) :
	_name(name),
	_weapon(weapon) {}

// Destructors
HumanA::~HumanA(void) {}

// Operators
HumanA&	HumanA::operator=(const HumanA &copy)
{
	if (this == &copy)
		return (*this);
	_name = copy._name;
	return (*this);
}

// Utils
void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
