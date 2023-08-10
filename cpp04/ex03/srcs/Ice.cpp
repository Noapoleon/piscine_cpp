/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:08:37 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 23:11:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}
Ice(const Ice& copy) : AMateria(copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

// Destructors
~Ice(void);

// Operators
Ice&	operator=(const Ice& copy);

// Utils
virtual	Ice*	clone(void) const;
