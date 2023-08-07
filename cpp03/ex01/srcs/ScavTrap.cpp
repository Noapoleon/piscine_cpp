/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/07 20:44:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "DefaultName";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Destructors
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap default destructor called" << std::endl;
}

// Operators
ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

// Utils
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no energy or hit points left. Attack failed." << std::endl;
		return ;
	}
	--(this->_energyPoints);
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount
		<< " points of damage and now has " << this->_hitPoints
		<< " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no energy or hit points left. Repair failed." << std::endl;
		return ;
	}
	--(this->_energyPoints);
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repaired itself and now has "
		<< this->_hitPoints << " hit points left." << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}
