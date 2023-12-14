/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 09:36:55 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
public:
	// Constructors
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap(const std::string& name);

	// Operators
	DiamondTrap&	operator=(const DiamondTrap& copy);

	// Destructors
	~DiamondTrap(void);

	// Utils
	void				attack(const std::string& target);
	void				whoAmI(void);
	std::string			getClassName(void) const;
	virtual std::string	getName(void) const; // virtual??

private:
	std::string	_name;
};

# endif
