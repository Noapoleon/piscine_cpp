/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:46 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/07 20:47:51 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ct1;
	ClapTrap ct2("pedro");
	ClapTrap ct3(ct1);

	ct1.attack(ct2.getName());
	ct1.takeDamage(8);
	ct1.beRepaired(24);

	ct2.attack(ct1.getName());
	ct2.takeDamage(11);
	ct2.beRepaired(24);

	ct3.attack(ct1.getName());
	ct3.takeDamage(-1);
	ct3.beRepaired(24);
	return (0);
}
