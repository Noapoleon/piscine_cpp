/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 19:20:45 by nlegrand         ###   ########.fr       */
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
	HumanB(void);
	HumanB(const HumanB &copy);
	HumanB(std::string name, Weapon *weapon);

	// Destructors
	~HumanB(void);

	// Operators
	void	operator=(const HumanB &copy);

	// Utils
	void	attack(void);
private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
