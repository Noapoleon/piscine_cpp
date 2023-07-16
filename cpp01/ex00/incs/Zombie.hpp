/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:11:00 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/16 05:33:30 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:
	Zombie(void) = delete;
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void) const;
private:
	std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
