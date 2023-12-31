/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:11:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/18 14:02:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:
	// Constructors
	Zombie(void);
	Zombie(std::string name);

	// Destructors
	~Zombie(void);

	// Utis
	void	announce(void) const;

private:
	std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
