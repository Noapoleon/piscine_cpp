/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:15:58 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 14:02:06 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructors
Zombie::Zombie() {}
Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie '" << name << "' constructor called." <<  std::endl;
}

// Destructors
Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << this->_name << "' destructor called."
		<<  std::endl;
}

// Utils
void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
