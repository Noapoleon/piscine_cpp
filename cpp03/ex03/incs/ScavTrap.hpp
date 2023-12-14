/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 09:39:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
public:
	// Constructors
	ScavTrap(void);
	ScavTrap(const ScavTrap& copy);
	ScavTrap(const std::string& name);

	// Operators
	ScavTrap&	operator=(const ScavTrap& copy);

	// Destructors
	virtual ~ScavTrap(void);

	// Utils
	void				attack(const std::string& target);
	void				guardGate(void);
	virtual std::string	getName(void) const; // virtual so it gets right name??
	std::string			getClassName(void) const;
};

# endif
