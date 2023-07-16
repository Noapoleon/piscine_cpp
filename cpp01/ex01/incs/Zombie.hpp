/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:11:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/16 18:34:40 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void) const;
	void	setName(std::string name);
private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
