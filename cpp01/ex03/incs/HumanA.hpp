/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 15:14:51 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
public:
	// Constructors
	HumanA(const HumanA& copy);
	HumanA(const std::string& name, const Weapon& weapon);

	// Destructors
	~HumanA(void);

	// Operators
	HumanA& operator=(const HumanA& copy);

	// Utils
	void	attack(void);
private:
	HumanA(void);

	std::string		_name;
	const Weapon&	_weapon;
};

#endif
