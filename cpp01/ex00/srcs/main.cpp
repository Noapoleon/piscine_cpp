/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 05:08:02 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/16 05:37:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("roberto");
	z1.announce();

	Zombie	*z2 = newZombie("vesa");
	z2->announce();
	delete z2;

	randomChump("Ritupon Baishya");

	return (0);
}
