/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:01:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 17:47:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
public:
	// Constructors
	Weapon(void);
	Weapon(const Weapon &copy);
	Weapon(const std::string &type);

	// Destructors
	~Weapon(void);

	// Getters / Setters
	const std::string	&getType() const;
	void				setType(const std::string &newType);

	// Operators
	Weapon &operator=(const Weapon &copy);

private:
	std::string	_type;
};

#endif
