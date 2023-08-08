/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/08 18:57:39 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << this->getClassName() << " default \e[34mconstructor\e[0m called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << this->getClassName() << " copy \e[34mconstructor\e[0m called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << this->getClassName() << " string \e[34mconstructor\e[0m called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Operators
FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	ClapTrap::operator=(copy);
	return (*this);
}

// Destructors
FragTrap::~FragTrap(void)
{
	std::cout << this->getClassName() << " default \e[31mdestructor\e[0m called" << std::endl;
}

// Utils
void	FragTrap::highFiveGuys(void)
{
	if (this->_canDoAction("High five") == false)
		return ;
	--(this->_energyPoints);
	std::cout << this->getClassName() << " " << this->_name
		<< " says High Five Guys!" << std::endl;
}

std::string FragTrap::getClassName(void) const
{
	return ("\e[38;2;75;180;0mFragTrap\e[0m");
}
