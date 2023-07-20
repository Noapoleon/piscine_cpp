/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 18:11:07 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors
HumanA::HumanA(const HumanA &copy) : _weapon(copy._weapon)
{
	this->_name = copy._name;
}
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
}

// Destructors
HumanA::~HumanA(void) {}

// Operators
void	HumanA::operator=(const HumanA &copy)
{
	this->_name = copy._name;
	this->_weapon = copy._weapon;
}

// Utils
void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}
