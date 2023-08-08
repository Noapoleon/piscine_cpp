/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/08 21:28:55 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	std::cout << this->getClassName() << " default \e[34mconstructor\e[0m called" << std::endl;
	this->_name = this->ClapTrap::_name;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << this->getClassName() << " copy \e[34mconstructor\e[0m called" << std::endl;
	this->_name = copy._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name), FragTrap(name)
{
	std::cout << this->getClassName() << " string \e[34mconstructor\e[0m called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Operators
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy)
{
	ClapTrap::operator=(copy);
	return (*this);
}

// Destructors
DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->getClassName() << " default \e[31mdestructor\e[0m called" << std::endl;
}

// Utils
void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_canDoAction("Existential crisis") == false)
		return ;
	--(this->_energyPoints);
	std::cout << this->getClassName() << " " << this->_name
		<< " has subobject name " << this->ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getClassName(void) const
{
	return ("\e[38;2;100;180;100mDiamondTrap\e[0m");
}
