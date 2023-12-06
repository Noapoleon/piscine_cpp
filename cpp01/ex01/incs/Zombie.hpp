/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:11:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 14:01:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:
	// Contructors
	Zombie(void);
	Zombie(std::string name);

	// Destructors
	~Zombie(void);

	// Utils
	void	announce(void) const;
	void	setName(std::string name);
private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
