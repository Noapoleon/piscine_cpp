/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:04:51 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 04:24:28 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

// Clears the std::cin after an input
void	clear_cin(void)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prints warning message and returns true if std::cin reached an EOF
bool	reachedEof(void)
{
	if (std::cin.eof())
	{
		std::cout << "\n\e[1;38;2;255;0;0mEnd-Of-File reached...\e[0m"
			<< std::endl;
		return (true);
	}
	return (false);
}

std::string	truncField(std::string str)
{
	if (str.length() < 10)
		return (str); // not sure i can do that
	return (str.substr(0, 9) + ".");
}
