/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:46 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/08 19:13:58 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	t1("Pedro");
	ScavTrap	t2("Miguel");
	FragTrap	t3("Javier");


	t1.attack("Ritupon");
	t2.attack("Ritupon");
	t3.attack("Ritupon");
	t3.takeDamage(-1);
	t3.beRepaired(33);
	return (0);
}
