/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 18:04:37 by nlegrand         ###   ########.fr       */
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
	HumanA(const HumanA &copy);
	HumanA(std::string name, Weapon &weapon);

	// Destructors
	~HumanA(void);

	// Operators
	void	operator=(const HumanA &copy);

	// Utils
	void	attack(void);
private:
	HumanA(void); // move

	std::string	_name;
	Weapon		&_weapon;

};

#endif
