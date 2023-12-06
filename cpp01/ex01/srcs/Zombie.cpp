/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:15:58 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 14:02:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructors
Zombie::Zombie(void) : _name("DefaultName")
{
	std::cout << "Zombie '" << _name << "' default constructor called." <<  std::endl;
}
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie '" << _name << "' string constructor called." <<  std::endl;
}

// Destructors
Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << _name << "' destructor called." <<  std::endl;
}

// Utils
void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setName(std::string name)
{
	std::cout << "Zombie '" << _name << "' set name to '" << name << "'." << std::endl;
	_name = name;
}
