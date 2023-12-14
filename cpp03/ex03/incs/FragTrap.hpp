/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/14 09:46:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
public:
	// Constructors
	FragTrap(void);
	FragTrap(const FragTrap& copy);
	FragTrap(const std::string& name);

	// Operators
	FragTrap&	operator=(const FragTrap& copy);

	// Destructors
	virtual ~FragTrap(void);

	// Utils
	void				attack(const std::string& target);
	void				highFiveGuys(void);
	virtual std::string	getName(void) const; // virtual so it gets right name??
	std::string			getClassName(void) const;
};

# endif
