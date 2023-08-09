/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:22:35 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class	ClapTrap
{
public:
	// Constructors
	ClapTrap(void);
	ClapTrap(const ClapTrap& copy);
	ClapTrap(const std::string& name);

	// Destructors
	virtual ~ClapTrap(void);

	// Operators
	ClapTrap&	operator=(const ClapTrap& copy);

	// Utils
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName(void) const;
	virtual		std::string	getClassName(void) const;
	void		displayInfo(void) const;

protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	// Private Utils
	bool			_canDoAction(const std::string& action) const;
};

# endif
