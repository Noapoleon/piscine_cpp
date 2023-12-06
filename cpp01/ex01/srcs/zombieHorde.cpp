/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:29:59 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/06 14:01:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N <= 0)
		return (NULL);
	horde = new(std::nothrow) Zombie[N];
	if (horde == NULL)
		return (NULL);
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}
