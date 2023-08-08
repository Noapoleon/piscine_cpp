/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/08 20:25:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << this->getClassName() << " default \e[34mconstructor\e[0m called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << this->getClassName() << " copy \e[34mconstructor\e[0m called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << this->getClassName() << " string \e[34mconstructor\e[0m called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Operators
ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	ClapTrap::operator=(copy);
	return (*this);
}

// Destructors
ScavTrap::~ScavTrap(void)
{
	std::cout << this->getClassName() << " default \e[31mdestructor\e[0m called" << std::endl;
}

// Utils
void	ScavTrap::attack(const std::string& target)
{
	if (this->_canDoAction("Attack") == false)
		return ;
	--(this->_energyPoints);
	std::cout << this->getClassName() << " " << this->_name << " attacks "
		<< target << ", causing " << this->_attackDamage
		<< " points of damage with his strong red claws!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_canDoAction("Guarding") == false)
		return ;
	--(this->_energyPoints);
	std::cout << this->getClassName() << " " << this->_name
		<< " is guarding the gate."
		<< std::endl;
}

std::string ScavTrap::getClassName(void) const
{
	return ("\e[38;2;0;180;75mScavTrap\e[0m");
}
