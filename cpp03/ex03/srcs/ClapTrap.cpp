/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 12:57:20 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void)
{
	std::cout << this->getClassName() << " default \e[34mconstructor\e[0m called" << std::endl;
	this->_name = "DefaultName";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << this->getClassName() << " copy \e[34mconstructor\e[0m called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << this->getClassName() << " string \e[34mconstructor\e[0m called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Destructors
ClapTrap::~ClapTrap(void)
{
	std::cout << this->getClassName() << " default \e[31mdestructor\e[0m called" << std::endl;
}

// Operators
ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
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
	if (this->_canDoAction("Attack") == false)
		return ;
	--(this->_energyPoints);
	std::cout << this->getClassName() << " " << getName() << " attacks "
		<< target << ", causing " << this->_attackDamage
		<< " points of damage with its flimsy yellow claws!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << this->getClassName() << " " << getName() << " took "
		<< amount << " points of damage and now has " << this->_hitPoints
		<< " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_canDoAction("Repair") == false)
		return ;
	--(this->_energyPoints);
	this->_hitPoints += amount;
	std::cout << this->getClassName() << " " << getName()
		<< " repaired itself and now has " << this->_hitPoints
		<< " hit points left." << std::endl;
}

std::string	ClapTrap::getName(void) const
{ return (this->_name); }
int	ClapTrap::getHitPoints(void) const
{ return (_hitPoints); }
int	ClapTrap::getEnergyPoints(void) const
{ return (_energyPoints); }
int	ClapTrap::getAttackDamage(void) const
{ return (_attackDamage); }

// Stream Operators
//std::ostream&	operator<<(std::ostream& os, const ClapTrap& c)
//{
//	os << c.getClassName() << c.getName() << " info: ";
//	return (os);
//}

std::string	ClapTrap::getClassName(void) const
{
	return ("\e[38;2;0;255;0mClapTrap\e[0m");
}

void	ClapTrap::displayInfo(void) const
{
	std::cout << "Name: " << getName();
	std::cout << ", Hit points: " << this->_hitPoints;
	std::cout << ", Energy points: " << this->_energyPoints;
	std::cout << ", Attack damage: " << this->_attackDamage << std::endl;
}

// Private utils
bool	ClapTrap::_canDoAction(const std::string& action) const
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		std::cout << this->getClassName() << " " << getName()
			<< " has no energy or hit points left. " << action
			<< " failed." << std::endl;
		return false;
	}
	return true;
}
