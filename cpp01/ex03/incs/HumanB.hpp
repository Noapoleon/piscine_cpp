/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 16:25:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
	// Constructors
	HumanB(const HumanB& copy);
	HumanB(const std::string& name);

	// Destructors
	~HumanB(void);

	// Operators
	HumanB& operator=(const HumanB &copy);

	// Utils
	void	attack(void);
	void	setWeapon(Weapon& w);
private:
	HumanB(void);

	std::string	_name;
	Weapon*		_weapon;
};

#endif
