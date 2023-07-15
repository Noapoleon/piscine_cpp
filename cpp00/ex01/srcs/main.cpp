/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:25:02 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 04:40:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "PhoneBook.hpp"
#include "utils.hpp"


int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while(true)
	{
		std::cout << std::endl << "\e[38;2;255;0;255mmapb >\e[0m ";
		std::getline(std::cin, command);
		if (reachedEof())
			break;
		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break;
		if (reachedEof())
			break;
		std::cin.clear();
	}
	return (0);
}
